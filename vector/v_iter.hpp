/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_iter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/03 16:27:03 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_ITER_HPP
#define V_ITER_HPP

namespace ft
{
	template <typename T>
	class v_iter
	{
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;

	private:
		pointer _ptr;

	public:
		v_iter() : _ptr(0){};
		v_iter(pointer ptr) : _ptr(ptr){};
		v_iter(v_iter const &src) { *this = src; };
		~v_iter(){};

		reference operator*() { return *_ptr; };
		pointer operator->() { return _ptr; };

		v_iter operator++()
		{
			_ptr++;
			return _ptr;
		};
		v_iter operator--()
		{
			_ptr--;
			return _ptr;
		};
		v_iter operator++(int)
		{
			v_iter temp = *this;
			_ptr++;
			return temp;
		};
		v_iter operator--(int)
		{
			v_iter temp = *this;
			_ptr--;
			return temp;
		};

		void operator+=(difference_type d) { _ptr += d; };
		void operator-=(difference_type d) { _ptr -= d; };

		v_iter operator+(difference_type d) { return (_ptr + d); };
		v_iter operator-(difference_type d) { return (_ptr - d); };

		difference_type operator+(v_iter v) { return (_ptr + v._ptr); };
		difference_type operator-(v_iter v) { return (_ptr - v._ptr); };

		bool operator==(v_iter const &v) { return (_ptr == v._ptr); };
		bool operator!=(v_iter const &v) { return (_ptr != v._ptr); };
		bool operator>(v_iter const &v) { return (_ptr > v._ptr); };
		bool operator>=(v_iter const &v) { return (_ptr >= v._ptr); };
		bool operator<(v_iter const &v) { return (_ptr < v._ptr); };
		bool operator<=(v_iter const &v) { return (_ptr <= v._ptr); };

		v_iter operator[](size_t n) { return (_ptr + n); };
	};
}

#endif