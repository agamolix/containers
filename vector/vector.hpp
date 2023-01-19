/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/12/23 14:00:07 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <limits>
#include <iostream>

#include "v_iter.hpp"
#include "v_iter_rev.hpp"
#include "v_iter_const.hpp"
#include "v_iter_rev_const.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../utils/is_same.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef v_iter<T> iter;
		typedef v_iter_const<T> iter_const;
		typedef v_iter_rev<T> iter_rev;
		typedef v_iter_rev_const<T> iter_rev_const;

	private:
		size_t _size;		   // vector size
		size_t _capacity;	   // vector capacity
		value_type *_data;	   // pointeur sur début du vector
		allocator_type _alloc; // allocator memoire

	public:
		// ----- CONST, DESTR -----

		// Default
		explicit vector(const allocator_type &alloc = allocator_type())
		{
			_size = 0;
			_capacity = 0;
			_alloc = alloc;
			_data = _alloc.allocate(0);
		}

		// Int, val
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
		{
			_size = n;
			_capacity = n;
			_alloc = alloc;
			_data = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
		}

		// Range
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type(),
			   typename enable_if<!is_same<InputIterator, int>::value>::type * = 0)
		{
			_alloc = alloc;
			size_t n = 0;
			InputIterator it;
			for (it = first; it != last; it++)
				n++;
			_data = _alloc.allocate(n);
			_capacity = n;
			it = first;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, *(it + i));
			_size = n;
		}

		// Copy
		vector(const vector &x)
		{
			_alloc = x._alloc;
			_size = x._size;
			_capacity = x._capacity;
			_data = _alloc.allocate(_capacity);

			iter_const it = x.cbegin();
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, *(it + i));
		}

		// Destructor
		~vector()
		{
			clear();
			_alloc.deallocate(_data, _capacity);
		}

		// ----- OPERATOR = -----

		vector &operator=(const vector &x)
		{
			std::cout << "op =" << std::endl;
			clear();
			_alloc.deallocate(_data, _capacity);
			_alloc = x._alloc;
			_size = x._size;
			_capacity = x._capacity;
			_data = _alloc.allocate(_capacity);

			iter_const it = x.cbegin();
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_data + i, *(it + i));
			return *this;
		}

		// ----- ITERATORS -----

		iter begin() { return iter(_data); };
		iter end() { return iter(_data) + _size; };

		iter_const cbegin() const { return iter_const(_data); };
		iter_const cend() const { return iter_const(_data) + _size; };

		iter_rev rbegin() { return iter_rev(_data + _size); };
		iter_rev rend() { return iter_rev(_data - 1); };

		// ----- CAPACITY -----

		size_type size() { return _size; };
		size_type max_size() { return std::numeric_limits<size_type>::max(); };
		size_type capacity() { return _capacity; };
		bool empty() const { return (_size == 0); };

		// Reserve
		void reserve(size_type n)
		{
			if (n > _capacity)
				extend_capacity(n);
		};

		// Resize
		void resize(size_type n, value_type val = value_type())
		{
			if (n > _capacity)
				extend_capacity(n);
			if (n < _size)
				for (size_t i = n; i < _size; i++)
					_alloc.destroy(&_data[i]);
			if (n > _size)
				for (size_t i = _size; i < n; i++)
					_alloc.construct(&_data[i], val);
			_size = n;
		}

		// ----- ELEMENT ACCESS -----

		reference operator[](size_type n) { return _data[n]; };
		const_reference operator[](size_type n) const { return _data[n]; };

		reference front() { return (_data[0]); };
		const_reference front() const { return (_data[0]); };

		reference back() { return (_data[_size - 1]); };
		const_reference back() const { return (_data[_size - 1]); };

		value_type *data() { return &_data[0]; };
		const value_type *data() const { return &_data[0]; };

		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("Out of range");
			return _data[n];
		}

		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("Out of range");
			return _data[n];
		}

		// ----- MODIFIERS -----

		// Assign
		void assign(size_type n, const value_type &val)
		{
			if (n > _capacity)
				dealloc_allocnew(n);
			else
				clear();
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
			_size = n;
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename enable_if<!is_same<InputIterator, int>::value>::type * = 0)
		{

			size_t n = 0;
			for (InputIterator it = first; it != last; it++)
				n++;
			if (n > _capacity)
				dealloc_allocnew(n);
			else
				clear();
			InputIterator it = first;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, *(it + i));
			_size = n;
		}

		// Push_back
		void push_back(value_type v)
		{
			if (_size == 0)
			{
				_data = _alloc.allocate(1);
				_capacity++;
				_size++;
				_alloc.construct(&_data[_size - 1], v);
				return;
			}
			if (_size == _capacity)
				extend_capacity(_size + 1);
			_size++;
			_alloc.construct(&_data[_size - 1], v);
		}

		// Pop_back
		void pop_back()
		{
			_alloc.destroy(&_data[_size - 1]);
			_size--;
		}

		// Insert
		iter insert(iter position, const value_type &val)
		{
			value_type v = *(end() - 1);
			iter it;
			for (it = end() - 1; it != position; it--)
				*it = *(it - 1);
			*(it) = val;
			push_back(v);
			return position;
		}

		void insert(iter position, size_type n, const value_type &val)
		{
			difference_type d = position - begin();
			if (_size + n > _capacity)
				extend_capacity(_size + n);
			position = begin() + d;
			_size += n;
			iter it;
			for (it = end() - 1; it != position; it--)
				*it = *(it - n);
			for (it = position; it != position + n; it++)
				*(it) = val;
		}

		template <class InputIterator>
		void insert(iter position, InputIterator first, InputIterator last,
					typename enable_if<!is_same<InputIterator, int>::value>::type * = 0)
		{
			vector v;
			iter it;
			for (it = first; it != last; it++)
				v.push_back(*it);
			difference_type d_pos = position - begin();
			difference_type d_iter = last - first;
			if (_size + d_iter > _capacity)
				extend_capacity(_size + d_iter);
			position = begin() + d_pos;
			_size += d_iter;
			for (it = end() - 1; it != position; it--)
				*it = *(it - d_iter);
			for (difference_type i = 0; i < d_iter; i++)
				*(it + i) = *(v.begin() + i);
		}

		// Erase
		iter erase(iter position)
		{
			iter pos = position;
			iter it;
			for (it = position; it != end() - 1; it++)
				*(it) = *(it + 1);
			_alloc.destroy(&(*it));
			_size--;
			return pos;
		}

		iter erase(iter first, iter last)
		{
			iter pos = first;
			iter it;
			difference_type d = last - first;
			for (it = first; it != end() - d; it++)
				*it = *(it + d);
			for (it = end() - d; it != end(); it++)
				_alloc.destroy(&(*it));
			_size = _size - d;
			return pos;
		}

		// Swap
		void swap(vector &x)
		{
			vector temp;
			temp.assign(x.begin(), x.end());
			temp._capacity = x._capacity;
			temp._size = x._size;
			x.assign(begin(), end());
			x._capacity = _capacity;
			x._size = _size;
			assign(temp.begin(), temp.end());
			_capacity = temp._capacity;
			_size = temp._size;
		}

		// Clear
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_data[i]);
			_size = 0;
		}

		// ----- ALLOCATOR -----

		allocator_type get_allocator() const { return _alloc; };

	private:
		// ----- MY FUNCTIONS -----
		void extend_capacity(size_t n)
		{
			value_type *temp = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(&temp[i], _data[i]);
				_alloc.destroy(&_data[i]);
			}
			_alloc.deallocate(_data, _capacity);
			_data = temp;
			_capacity = n;
		}

		void dealloc_allocnew(size_t n)
		{
			clear();
			_alloc.deallocate(_data, _capacity);
			_data = _alloc.allocate(n);
			_capacity = n;
		}
	};
}

// ----- OPERATORS -----

template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	bool b1 = lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
	bool b2 = lexicographical_compare(rhs.cbegin(), rhs.cend(), lhs.cbegin(), lhs.cend());

	if (b1 == false && b2 == false)
		return true;
	else
		return false;
}

template <class T, class Alloc>
bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	if (lhs == rhs)
		return false;
	return true;
}

template <class T, class Alloc>
bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	return (lexicographical_compare(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend()));
}

template <class T, class Alloc>
bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	return (lhs < rhs || lhs == rhs);
}

template <class T, class Alloc>
bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	return (!(lhs <= rhs));
}

template <class T, class Alloc>
bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	return (!(lhs < rhs));
}

#endif