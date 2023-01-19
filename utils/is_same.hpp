/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/12/23 13:38:57 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_SAME_HPP
#define IS_SAME_HPP

namespace ft
{
	template <class T, class U>
	struct is_same
	{
		static const bool value = false;
	};

	template <class T>
	struct is_same<T, T>
	{
		static const bool value = true;
	};
};

#endif