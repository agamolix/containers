/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/03 16:27:03 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;

	private:
		iterator_type _it;

	public:
		// ----- CONST, DESTR -----
		reverse_iterator() : _it(){};

		explicit reverse_iterator(iterator_type it) { _it = it; };

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) { _it = rev_it.base(); };

		// ----- OPERATOR= -----
		reverse_iterator &operator=(const reverse_iterator &other)
		{
			_it = other._it;
			return *this;
		}

		// ----- BASE -----
		iterator_type base() const { return _it; };

		// ----- DEREFERENCE -----
		reference operator*() const { return *_it; };
		pointer operator->() const { return &(_it); };
		reference operator[](difference_type n) const { return *(_it - n); };

		// ----- +/- -----
		reverse_iterator operator+(difference_type n) const { return _it - n; };
		reverse_iterator operator-(difference_type n) const { return _it + n; };

		// ----- INCREMENT -----
		reverse_iterator &operator++()
		{
			_it--;
			return _it;
		};
		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			_it--;
			return temp;
		};
		reverse_iterator &operator--()
		{
			_it++;
			return _it;
		};
		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			_it++;
			return temp;
		};

		// ----- +=/-= -----
		reverse_iterator &operator+=(difference_type n) { return (_it -= n); };
		reverse_iterator &operator-=(difference_type n) { return (_it += n); };
	};
}

#endif