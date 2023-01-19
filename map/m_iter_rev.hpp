/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_iter_rev.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/03 16:27:03 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_ITER_REV_HPP
#define M_ITER_REV_HPP

#include "node.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key> >
	class m_iter_rev
	{
	private:
		node<Key, T> *_node;

	public:
		typedef ft::pair<Key, T> value_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type *pointer;
		typedef value_type &reference;

		m_iter_rev() : _node(0){};
		m_iter_rev(node<Key, T> *n) : _node(n){};
		m_iter_rev(m_iter_rev const &m) { *this = m; };
		~m_iter_rev(){};

		reference operator*() { return _node->get_key(); };
		pointer operator->() { return &(_node->get_key()); };

		m_iter_rev &operator=(m_iter_rev const &src)
		{
			_node = src._node;
			return *this;
		};

		m_iter_rev operator++() { return (_node->previous()); };
		m_iter_rev operator--() { return (_node->next()); };
		m_iter_rev operator++(int)
		{
			m_iter_rev temp = *this;
			_node = _node->previous();
			return temp;
		};

		m_iter_rev operator--(int)
		{
			m_iter_rev temp = *this;
			_node = _node->next();
			return temp;
		};

		m_iter_rev operator+(difference_type d)
		{
			m_iter_rev res = *this;
			for (difference_type dt = d; dt > 0; dt--)
				res = ++res;
			return res;
		}

		m_iter_rev operator-(difference_type d)
		{
			m_iter_rev res = *this;
			for (difference_type dt = d; dt > 0; dt--)
				res = --res;
			return res;
		}

		bool operator==(m_iter_rev const &m) { return (_node == m._node); };
		bool operator!=(m_iter_rev const &m) { return (_node != m._node); };
	};
}
#endif