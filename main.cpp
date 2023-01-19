/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/12/23 13:58:23 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "main.hpp"

int main()
{
	std::cout << "Enter a command: vi (vector int), vc (vector char), mi (map int, int), mc (map char, char): ";  
	std::string command;
	std::cin >> command;
	if (command.compare("vi") == 0)
	{
		test_vector_int();
		return 0;
	}
	else if (command.compare("vc") == 0)
	{
		test_vector_char();
		return 0;
	}
	else if (command.compare("mi") == 0)
	{
		test_map_int();
		return 0;
	}
	else if (command.compare("mc") == 0)
	{
		test_map_char();
		return(0);
	}
	else
	{
		std::cout << "Invalid command" << std::endl;
		return 0;
	}
}