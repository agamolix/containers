/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_iter_rev.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/03 16:27:03 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_ITER_REV_HPP
#define V_ITER_REV_HPP

namespace ft
{
	template <typename T>
	class v_iter_rev
	{
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;

	private:
		pointer _ptr;

	public:
		v_iter_rev() : _ptr(0){};
		v_iter_rev(pointer ptr) : _ptr(ptr){};
		v_iter_rev(v_iter_rev const &src) { *this = src; };
		~v_iter_rev(){};

		reference operator*() { return *_ptr; };
		pointer operator->() { return _ptr; };

		v_iter_rev operator++()
		{
			_ptr--;
			return _ptr;
		};
		v_iter_rev operator--()
		{
			_ptr++;
			return _ptr;
		};
		v_iter_rev operator++(int)
		{
			v_iter_rev temp = *this;
			_ptr--;
			return temp;
		};
		v_iter_rev operator--(int)
		{
			v_iter_rev temp = *this;
			_ptr++;
			return temp;
		};

		void operator+=(difference_type d) { _ptr -= d; };
		void operator-=(difference_type d) { _ptr += d; };

		v_iter_rev operator+(difference_type d) { return (_ptr - d - 1); };
		v_iter_rev operator-(difference_type d) { return (_ptr + d); };

		difference_type operator+(v_iter_rev v) { return (_ptr - v._ptr); };
		difference_type operator-(v_iter_rev v) { return (_ptr + v._ptr); };

		bool operator==(v_iter_rev const &v) { return (_ptr == v._ptr); };
		bool operator!=(v_iter_rev const &v) { return (_ptr != v._ptr); };
		bool operator>(v_iter_rev const &v) { return (_ptr < v._ptr); };
		bool operator>=(v_iter_rev const &v) { return (_ptr <= v._ptr); };
		bool operator<(v_iter_rev const &v) { return (_ptr > v._ptr); };
		bool operator<=(v_iter_rev const &v) { return (_ptr >= v._ptr); };

		v_iter_rev operator[](size_t n) { return (_ptr - n); };
	};
}

#endif