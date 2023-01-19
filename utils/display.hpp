/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/12/23 13:58:23 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <vector>
#include "../vector/vector.hpp"
#include <map>
#include "../map/map.hpp"
#include <iomanip>

template <class T1, class T2>
void display_pair(ft::pair<T1, T2> p)
{
	std::cout << p.first << "," << p.second;
}

template <class T1, class T2>
void display_pair(std::pair<T1, T2> p)
{
	std::cout << p.first << "," << p.second;
}

template <class T1, class T2>
void rdisplay_map(std::map<T1, T2> m)
{
	for (typename std::map<T1, T2>::reverse_iterator itt = m.rbegin(); itt != m.rend(); itt++)
		std::cout << itt->first << ',' << itt->second << ' ';
}

template <class T1, class T2>
void rdisplay_map(ft::map<T1, T2> m)
{
	for (ft::m_iter_rev<T1, T2> itt = m.rbegin(); itt != m.rend(); itt++)
		std::cout << itt->first << ',' << itt->second << ' ';
}

template <class T1, class T2>
void rdisplay_map(std::string s, std::map<T1, T2> mstd, ft::map<T1, T2> mft)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	rdisplay_map(mstd);
	std::cout << "  |  ";
	rdisplay_map(mft);
	std::cout << "\n";
}

template <class T1, class T2>
void display_map(std::map<T1, T2> m)
{
	for (typename std::map<T1, T2>::iterator itt = m.begin(); itt != m.end(); itt++)
		std::cout << itt->first << ',' << itt->second << ' ';
}

template <class T1, class T2>
void display_map(ft::map<T1, T2> m)
{
	for (ft::m_iter<T1, T2> itt = m.begin(); itt != m.end(); itt++)
		std::cout << itt->first << ',' << itt->second << ' ';
}

template <class T1, class T2>
void display_map(std::string s, std::map<T1, T2> mstd, ft::map<T1, T2> mft)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	display_map(mstd);
	std::cout << "  |  ";
	display_map(mft);
	std::cout << "\n";
}

template <class T1, class T2>
void display_map(std::string s, std::pair<T1, T2> pstd1, std::pair<T1, T2> pstd2, ft::pair<T1, T2> pft1, ft::pair<T1, T2> pft2)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	display_pair(pstd1);
	std::cout << " - ";
	display_pair(pstd2);
	std::cout << "  |  ";
	display_pair(pft1);
	std::cout << " - ";
	display_pair(pft2);
	std::cout << "\n";
}

template <class T1, class T2>
void display_map(std::string s, std::pair<T1, T2> pstd1, std::pair<T1, T2> pstd2,
				 typename ft::m_iter<T1, T2, std::less<int> >::value_type pft1, typename ft::m_iter<T1, T2, std::less<int> >::value_type pft2)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	display_pair(pstd1);
	std::cout << " - ";
	display_pair(pstd2);
	std::cout << "  |  ";
	display_pair(pft1);
	std::cout << " - ";
	display_pair(pft2);
	std::cout << "\n";
}

template <class T1, class T2>
void display_map(std::string s, std::pair<T1, T2> pstd, ft::pair<T1, T2> pft)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	display_pair(pstd);
	std::cout << "  |  ";
	display_pair(pft);
	std::cout << "\n";
}

template <class T1, class T2>
void display_map(std::string s, std::pair<T1, T2> pstd, typename ft::m_iter<T1, T2, std::less<int> >::value_type pft)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	display_pair(pstd);
	std::cout << "  |  ";
	display_pair(pft);
	std::cout << "\n";
}

template <class T1, class T2>
void display_map(std::string s, int istd, int ift)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	std::cout << istd;
	std::cout << "  |  ";
	std::cout << ift;
	std::cout << "\n";
}

void display_map(std::string s, size_t istd, size_t ift)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	std::cout << istd;
	std::cout << "  |  ";
	std::cout << ift;
	std::cout << "\n";
}

template <class T>
void display(ft::vector<T> v)
{
	for (ft::v_iter<T> itt = v.begin(); itt != v.end(); itt++)
		std::cout << *itt << ' ';
}

template <class T>
void display(std::vector<T> v)
{
	for (typename std::vector<T>::iterator itt = v.begin(); itt != v.end(); itt++)
		std::cout << *itt << ' ';
}

template <class T>
void display(std::string s, std::vector<T> vstd, ft::vector<T> vft)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	display(vstd);
	std::cout << "  |  ";
	display(vft);
	std::cout << "\n";
}

template <class T>
void display(std::string s, T istd, T ift)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	std::cout << istd;
	std::cout << "  |  ";
	std::cout << ift;
	std::cout << "\n";
}

template <class T>
void display(std::string s, T *istd, T *ift)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	std::cout << &istd;
	std::cout << "  |  ";
	std::cout << &ift;
	std::cout << "\n";
}

void display(std::string s, std::string s2, std::string s3)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	std::cout << s2;
	std::cout << "  |  ";
	std::cout << s3;
	std::cout << "\n";
}

template <class T>
void display(std::string s, T *p1, T *p2, int s1, int s2)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	for (int i = 0; i < s1; i++)
		std::cout << p1[i] << ' ';
	std::cout << "  |  ";
	for (int i = 0; i < s2; i++)
		std::cout << p2[i] << ' ';
	std::cout << "\n";
}

void display_bool(std::string s, bool s2, bool s3)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	std::cout << std::boolalpha << s2;
	std::cout << "  |  ";
	std::cout << std::boolalpha << s3;
	std::cout << "\n";
}

void display_sizet(std::string s, size_t istd, size_t ift)
{
	std::cout << std::left << std::setw(60) << s;
	std::cout << std::right;
	std::cout << istd;
	std::cout << "  |  ";
	std::cout << ift;
	std::cout << "\n";
}

#endif