/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/12/23 14:00:07 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef map_HPP
#define map_HPP

#include <cstddef>
#include <limits>
#include <iostream>

#include "m_iter.hpp"
#include "m_iter_rev.hpp"
#include "m_iter_const.hpp"
#include "tree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>,
			  class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef m_iter<Key, T, Compare> iter;
		typedef m_iter_const<Key, T, Compare> iter_const;
		typedef m_iter_rev<Key, T, Compare> iter_rev;

	private:
		size_t _size;					   // map size
		key_compare _keycomp;			   // map compare way
		tree<key_type, mapped_type> _tree; // tree
		allocator_type _alloc;			   // allocator memoire
		bool _hastree;

		class value_compare
		{
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c){};

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};

	public:
		// ----- CONST, DESTR -----
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type())
		{
			_size = 0;
			_keycomp = comp;
			_alloc = alloc;
			_hastree = false;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		{
			_size = 0;
			_keycomp = comp;
			_alloc = alloc;
			_hastree = false;
			insert(first, last);
		}

		map(const map &x)
		{
			_size = x._size;
			_keycomp = x._keycomp;
			_alloc = x._alloc;
			_hastree = x._hastree;
			_tree = x._tree;
			*this = x;
		}

		~map(){};

		// ----- OPERATOR = -----
		map &operator=(const map &x)
		{
			_size = x._size;
			_keycomp = x._keycomp;
			_alloc = x._alloc;
			_hastree = x._hastree;
			_tree = x._tree;
			return *this;
		}

		// ----- ITERATORS -----
		iter begin() { return iter(_tree.min()); };
		iter end() { return begin() + _size; };
		iter_const cbegin() const { return iter_const(_tree.min()); };
		iter_const cend() const { return cbegin() + _size; };
		iter_rev rbegin() { return iter_rev(_tree.max()); };
		iter_rev rend() { return rbegin() + (_size); };

		// ----- CAPACITY -----
		size_type size() const { return _size; };
		size_type max_size() const { return std::numeric_limits<size_type>::max(); };
		bool empty() const { return (_size == 0); };

		// ----- ELEMENT ACCESS -----
		mapped_type &operator[](const key_type &k)
		{
			insert_value(k);
			return (find(k)->second);
		}

		mapped_type &at(const key_type &k)
		{
			if (find(k) == end())
				throw std::out_of_range("Out of range");
			return find(k)->second;
		}

		const mapped_type &at(const key_type &k) const
		{
			if (find(k) == end())
				throw std::out_of_range("Out of range");
			return find(k)->second;
		}

		// ----- MODIFIERS -----

		// Insert
		ft::pair<iter, bool> insert(const value_type &val)
		{
			if (find(val.first) == end())
			{
				insert_pair(val);
				ft::pair<iter, bool> p = ft::make_pair(find(val.first), true);
				return (p);
			}
			else
			{
				ft::pair<iter, bool> p = ft::make_pair(find(val.first), false);
				return (p);
			}
		}

		iter insert(iter position, const value_type &val)
		{
			(void)position;
			if (find(val.first) == end())
			{
				insert_pair(val);
				return (find(val.first));
			}
			else
			{
				return (find(val.first));
			}
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			iter it;
			for (it = first; it != last; it++)
			{
				if (find(it->first) == end())
				{
					ft::pair<key_type, mapped_type> p = ft::make_pair(it->first, it->second);
					insert_pair(p);
				}
			}
		}

		// Erase
		void erase(iter position)
		{
			if (find(position->first) != end())
			{
				_tree.remove_node(position->first);
				_size--;
			}
		}

		size_type erase(const key_type &k)
		{
			if (find(k) != end())
			{
				_tree.remove_node(k);
				_size--;
				return 1;
			}
			return 0;
		}

		void erase(iter first, iter last)
		{
			iter it = first;
			iter next;
			key_type last_key = last->first;
			key_type next_key;
			while (it->first != last_key && it != end())
			{
				next = it + 1;
				next_key = next->first;
				erase(it);
				if (next_key != end()->first)
					it = find(next_key);
				else
					break;
			}
		}

		// Swap
		void swap(map &x)
		{
			size_t temp_size = _size;
			tree<key_type, mapped_type> temp_tree = _tree;
			key_compare temp_keycomp = _keycomp;

			_size = x._size;
			_tree = x._tree;
			_keycomp = x._keycomp;

			x._size = temp_size;
			x._tree = temp_tree;
			x._keycomp = temp_keycomp;
		}

		// Clear
		void clear()
		{
			_tree.remove_all();
			_size = 0;
		}

		// ----- OBSERVERS -----

		key_compare key_comp() const { return key_compare(); };
		value_compare value_comp() const { return (value_compare(key_compare())); };

		// ----- OPERATIONS -----

		// Find
		iter find(const key_type &k)
		{
			if (_tree.search(k))
				return (_tree.search(k));
			else
				return end();
		}

		iter_const find(const key_type &k) const
		{
			if (_tree.search(k))
				return (_tree.search(k));
			else
				return end();
		}

		// Count
		size_type count(const key_type &k) // const
		{
			if (find(k) == end())
				return 0;
			return 1;
		}

		// Bounds
		iter lower_bound(const key_type &k) { return _tree.lower(k); };
		iter_const lower_bound(const key_type &k) const { return _tree.lower(k); };
		iter upper_bound(const key_type &k) { return _tree.upper(k); };
		iter_const upper_bound(const key_type &k) const { return _tree.upper(k); };

		// Equal_range
		ft::pair<iter, iter> equal_range(const key_type &k)
		{
			return ft::make_pair<iter, iter>(lower_bound(k), upper_bound(k));
		};

		ft::pair<iter_const, iter_const> equal_range(const key_type &k) const
		{
			return ft::make_pair<iter_const, iter_const>(lower_bound(k), upper_bound(k));
		};

		// ----- ALLOCATOR -----
		allocator_type get_allocator() const { return _alloc; };

	private:
		// ----- MY FUNCTIONS -----
		void insert_value(const key_type &k)
		{
			if (!_hastree)
			{
				ft::pair<key_type, mapped_type> p = ft::make_pair(k, 0);
				_tree = tree<key_type, mapped_type>(p);
				_hastree = true;
				_size++;
			}
			if (find(k) == end())
			{
				ft::pair<key_type, mapped_type> p = ft::make_pair(k, 0);
				_tree.insert(p);
				_size++;
			}
		}

		void insert_pair(const value_type &p)
		{
			if (!_hastree)
			{
				_tree = tree<key_type, mapped_type>(p);
				_hastree = true;
				_size++;
			}
			if (find(p.first) == end())
			{
				_tree.insert(p);
				_size++;
			}
		}
	};
}

// ----- OPERATORS -----

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
	ft::m_iter_const<Key, T, Compare> itlhs = lhs.cbegin();
	ft::m_iter_const<Key, T, Compare> itelhs = lhs.cend();
	ft::m_iter_const<Key, T, Compare> itrhs = rhs.cbegin();
	ft::m_iter_const<Key, T, Compare> iterhs = rhs.cend();

	if (lhs.size() != rhs.size())
		return false;

	while (itlhs != itelhs && itrhs != iterhs)
	{
		if ((itlhs->first != itrhs->first) || (itlhs->second != itrhs->second))
			return false;
		itlhs++;
		itrhs++;
	}
	return true;
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
	ft::m_iter_const<Key, T, Compare> itlhs = lhs.cbegin();
	ft::m_iter_const<Key, T, Compare> itelhs = lhs.cend();
	ft::m_iter_const<Key, T, Compare> itrhs = rhs.cbegin();
	ft::m_iter_const<Key, T, Compare> iterhs = rhs.cend();

	if (lhs == rhs)
		return false;

	while (itlhs != itelhs && itrhs != iterhs)
	{
		if (itlhs->first > itrhs->first)
			return false;
		else if ((itlhs->first == itrhs->first) && (itlhs->second > itrhs->second))
			return false;
		itlhs++;
		itrhs++;
	}
	return true;
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
	return (lhs == rhs || lhs < rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
	return !(lhs <= rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
	return !(lhs < rhs);
}

#endif