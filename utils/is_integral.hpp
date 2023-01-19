/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/03 16:27:03 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
	template <class T>
	struct is_integral
	{
		bool value = false;
	};

	template <>
	struct is_integral<bool>
	{
		bool value = true;
	};
	template <>
	struct is_integral<char>
	{
		bool value = true;
	};
	template <>
	struct is_integral<char16_t>
	{
		bool value = true;
	};
	template <>
	struct is_integral<char32_t>
	{
		bool value = true;
	};
	template <>
	struct is_integral<wchar_t>
	{
		bool value = true;
	};
	template <>
	struct is_integral<signed char>
	{
		bool value = true;
	};
	template <>
	struct is_integral<short int>
	{
		bool value = true;
	};
	template <>
	struct is_integral<int>
	{
		bool value = true;
	};
	template <>
	struct is_integral<long int>
	{
		bool value = true;
	};
	template <>
	struct is_integral<long long int>
	{
		bool value = true;
	};
	template <>
	struct is_integral<unsigned char>
	{
		bool value = true;
	};
	template <>
	struct is_integral<unsigned short int>
	{
		bool value = true;
	};
	template <>
	struct is_integral<unsigned int>
	{
		bool value = true;
	};
	template <>
	struct is_integral<unsigned long int>
	{
		bool value = true;
	};
	template <>
	struct is_integral<unsigned long long int>
	{
		bool value = true;
	};
}

#endif