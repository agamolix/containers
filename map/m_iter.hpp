/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_iter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/03 16:27:03 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ITER_HPP
#define M_ITER_HPP

#include "node.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key> >
	class m_iter
	{
	private:
		node<Key, T> *_node;

	public:
		typedef ft::pair<Key, T> value_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type *pointer;
		typedef value_type &reference;

		m_iter() : _node(0){};
		m_iter(node<Key, T> *n) : _node(n){};
		m_iter(m_iter const &m) { *this = m; };
		~m_iter(){};

		reference operator*() { return _node->get_key(); };
		pointer operator->() { return &(_node->get_key()); };

		m_iter &operator=(m_iter const &src)
		{
			_node = src._node;
			return *this;
		};

		m_iter operator++() { return (_node->next()); };
		m_iter operator--() { return (_node->previous()); };
		m_iter operator++(int)
		{
			m_iter temp = *this;
			_node = _node->next();
			return temp;
		};

		m_iter operator--(int)
		{
			m_iter temp = *this;
			_node = _node->previous();
			return temp;
		};

		m_iter operator+(difference_type d)
		{
			m_iter res = *this;
			for (difference_type dt = d; dt > 0; dt--)
				res = ++res;
			return res;
		}

		m_iter operator-(difference_type d)
		{
			m_iter res = *this;
			for (difference_type dt = d; dt > 0; dt--)
				res = --res;
			return res;
		}

		bool operator==(m_iter const &m) { return (_node == m._node); };
		bool operator!=(m_iter const &m) { return (_node != m._node); };
	};
}
#endif