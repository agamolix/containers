/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/12/23 13:58:23 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/display.hpp"

int test_vector_int(void)
{
	std::cout << std::left << std::setw(60) << " " << "v_std  |  v_ft" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector<int> v1_std(3);
	ft::vector<int> v1_ft(3);
	display("Constructor (3) // v1 = ", v1_std, v1_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	ft::vector<int> v2_ft(3, 10);
	std::vector<int> v2_std(3, 10);
	display("Constructor (3, 10) // v2 = ", v2_std, v2_ft);		
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v2_ft.push_back(3);
	v2_std.push_back(3);
	v2_std.push_back(7);
	v2_ft.push_back(7);
	v2_std.push_back(8);
	v2_ft.push_back(8);
	display("Push back (3, 7, 8) // v2 = ", v2_std, v2_ft);

	v2_std.pop_back();
	v2_ft.pop_back();
	display("Pop back () // v2 = ", v2_std, v2_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	ft::vector<int> v3_ft(v2_ft.end() - 3, v2_ft.end());
	std::vector<int> v3_std(v2_std.end() - 3, v2_std.end());
	display("Constr (end - 3, end) // v3 =", v3_std, v3_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	ft::vector<int> v4_ft(v3_ft);
	std::vector<int> v4_std(v3_std);
	display("Constructor copy (v3) // v4 = ", v4_std, v4_ft);		
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	ft::vector<int> v5_ft = v4_ft;
	std::vector<int> v5_std = v4_std;
	display("Operator = (v4) // v5 = ", v5_std, v5_ft);		
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	display("Begin (v5) = ", *(v5_std.begin()), *(v5_ft.begin()));
	display("End (v5) = ", *(v5_std.end()), *(v5_ft.end()));
	display("End - 1 (v5) = ", *(v5_std.end() - 1), *(v5_ft.end() - 1));

	display("Rbegin (v5) = ", *(v5_std.rbegin()), *(v5_ft.rbegin()));
	display("Rend (v5) = ", *(v5_std.rend()), *(v5_ft.rend()));
	display("Rend - 1 (v5) = ", *(v5_std.rend() - 1), *(v5_ft.rend() - 1));
	
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	display("Size (v5) = ", v2_std.size(), v2_ft.size());		
	display("Capacity (v5) = ", v2_std.capacity(), v2_ft.capacity());		
	display_sizet("Max size (v5) = ", v2_std.max_size(), v2_ft.max_size());		
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.clear();
	v5_std.clear();
	display("Clear (v5) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.assign(5, 100);
	v5_std.assign(5, 100);
	display("Assign (5, 100) // v5 =", v5_std, v5_ft);

	v5_ft.assign(4, 10);
	v5_std.assign(4, 10);
	display("Assign (4, 10) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.push_back(5);
	v5_std.push_back(5);
	display("Push back (5) // v5 =", v5_std, v5_ft);
	v5_ft.assign(v5_ft.begin() + 2, v5_ft.end());
	v5_std.assign(v5_std.begin() + 2, v5_std.end());
	display("Assign (begin + 2, end) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.clear();
	v5_ft.push_back(1);
	v5_ft.push_back(2);
	v5_ft.push_back(3);
	v5_std.clear();
	v5_std.push_back(1);
	v5_std.push_back(2);
	v5_std.push_back(3);
	display("Clear + Push back (1, 2, 3) // v5 =", v5_std, v5_ft);
	v5_ft.insert(v5_ft.begin() + 1, 6);
	v5_std.insert(v5_std.begin() + 1, 6);
	display("Insert (begin + 1, 6) // v5 =", v5_std, v5_ft);

	v5_ft.insert(v5_ft.begin() + 1, 2, 4);
	v5_std.insert(v5_std.begin() + 1, 2, 4);
	display("Insert (begin + 1, 2, 4) // v5 =", v5_std, v5_ft);

	v5_ft.insert(v5_ft.begin() + 4, v5_ft.begin() + 1, v5_ft.begin() + 3);
	v5_std.insert(v5_std.begin() + 4, v5_std.begin() + 1, v5_std.begin() + 3);
	display("Insert (beg + 4, beg + 1, beg + 3) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.erase(v5_ft.begin() + 4);
	v5_std.erase(v5_std.begin() + 4);
	display("Erase (begin + 4) // v5 =", v5_std, v5_ft);

	v5_ft.erase(v5_ft.begin() + 1, v5_ft.begin() + 3);
	v5_std.erase(v5_std.begin() + 1, v5_std.begin() + 3);
	display("Erase (begin + 1, begin + 3) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector<int> v6_std;
	v6_std.push_back(1);
	v6_std.push_back(2);
	ft::vector<int> v6_ft;
	v6_ft.push_back(1);
	v6_ft.push_back(2);
	display("Push back (1, 2) // v6 =", v6_std, v6_ft);
	v5_ft.swap(v6_ft);
	v5_std.swap(v6_std);
	display("Swap (v5, v6) // v5 =", v5_std, v5_ft);
	display("Swap (v5, v6) // v6 =", v6_std, v6_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.resize(4);
	v5_std.resize(4);
	display("Resize (4) // v5 =", v5_std, v5_ft);
	v5_ft.resize(7, 1);
	v5_std.resize(7, 1);
	display("Resize (7, 1) // v5 =", v5_std, v5_ft);
	v5_ft.resize(5);
	v5_std.resize(5);
	display("Resize (5) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector <int> v7_std = v5_std;
	ft::vector <int> v7_ft = v5_ft;
	display("Copy (v5) // v7 =", v7_std, v7_ft);
	display_bool("Empty (v5) =", v5_std.empty(), v5_ft.empty());
	v5_ft.clear();
	v5_std.clear();
	display("Clear (v5) // v5 =", v5_std, v5_ft);
	display_bool("Empty (v5) =", v5_std.empty(), v5_ft.empty());
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v7_std.reserve(20);
	v7_ft.reserve(20);
	display("Reserve (20) // v7 =", v7_std, v7_ft);
	display("Capacity (v7) =", v7_std.capacity(), v7_ft.capacity());
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector <int> v8_std;
	ft::vector <int> v8_ft;
	int * p_std = v8_std.get_allocator().allocate(5);
	int * p_ft = v8_ft.get_allocator().allocate(5);
	for (size_t i = 0; i < 3; i++) 
		v8_std.get_allocator().construct(&p_std[i], i * 2);
	for (size_t i = 0; i < 3; i++) 
		v8_ft.get_allocator().construct(&p_ft[i], i * 2);
	display("Get allocator (alloc + construct 0, 2, 4) // v8 =", p_std, p_ft, 3, 3);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	display("v6 =", v6_std, v6_ft);
	display("Front (v6) =", v6_std.front(), v6_ft.front());
	display("Back (v6) =", v6_std.back(), v6_ft.back());
	display("Data (v6) =", v6_std.data(), v6_ft.data());
	display("Operator [] // v6[1] =", v6_std[1], v6_ft[1]);
	try
	{
		display("At (v6.at(1)) = ", v6_std.at(1), v6_ft.at(1));
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "At (v6.at(10)) = " << std::endl;
	try
	{
		display("At (v6.at(10)) = ", v6_std.at(10), v6_ft.at(10));
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector <int> v9_std = v6_std;
	ft::vector <int> v9_ft = v6_ft;
	display("v9 = v6 // v6 =", v6_std, v6_ft);
	v9_std[2] = 300;
	v9_ft[2] = 300;
	display("v9[2] = 300 // v9 =", v9_std, v9_ft);
	display_bool("v6 == v9:", v6_std == v9_std, v6_ft == v9_ft);
	display_bool("v6 != v9:", v6_std != v9_std, v6_ft != v9_ft);
	display_bool("v6 > v9:", v6_std > v9_std, v6_ft > v9_ft);
	display_bool("v6 >= v9:", v6_std >= v9_std, v6_ft >= v9_ft);
	display_bool("v6 < v9:", v6_std < v9_std, v6_ft < v9_ft);
	display_bool("v6 <= v9:", v6_std <= v9_std, v6_ft <= v9_ft);

	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
	return 0;
}

int test_vector_char(void)
{
	std::cout << std::left << std::setw(60) << " " << "v_std  |  v_ft" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector<char> v1_std(3);
	ft::vector<char> v1_ft(3);
	display("Constructor (3) // v1 = ", v1_std, v1_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	ft::vector<char> v2_ft(3, 'A');
	std::vector<char> v2_std(3, 'A');
	display("Constructor (3, 'A') // v2 = ", v2_std, v2_ft);		
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v2_ft.push_back('B');
	v2_std.push_back('B');
	v2_std.push_back('C');
	v2_ft.push_back('C');
	v2_std.push_back('D');
	v2_ft.push_back('D');
	display("Push back ('B', 'C', 'D') // v2 = ", v2_std, v2_ft);

	v2_std.pop_back();
	v2_ft.pop_back();
	display("Pop back () // v2 = ", v2_std, v2_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	ft::vector<char> v3_ft(v2_ft.end() - 3, v2_ft.end());
	std::vector<char> v3_std(v2_std.end() - 3, v2_std.end());
	display("Constr (end - 3, end) // v3 =", v3_std, v3_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	ft::vector<char> v4_ft(v3_ft);
	std::vector<char> v4_std(v3_std);
	display("Constructor copy (v3) // v4 = ", v4_std, v4_ft);		
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	ft::vector<char> v5_ft = v4_ft;
	std::vector<char> v5_std = v4_std;
	display("Operator = (v4) // v5 = ", v5_std, v5_ft);		
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	display("Begin (v5) = ", *(v5_std.begin()), *(v5_ft.begin()));
	display("End (v5) = ", *(v5_std.end()), *(v5_ft.end()));
	display("End - 1 (v5) = ", *(v5_std.end() - 1), *(v5_ft.end() - 1));

	display("Rbegin (v5) = ", *(v5_std.rbegin()), *(v5_ft.rbegin()));
	display("Rend (v5) = ", *(v5_std.rend()), *(v5_ft.rend()));
	display("Rend - 1 (v5) = ", *(v5_std.rend() - 1), *(v5_ft.rend() - 1));
	
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	display("Size (v5) = ", v2_std.size(), v2_ft.size());		
	display("Capacity (v5) = ", v2_std.capacity(), v2_ft.capacity());		
	display_sizet("Max size (v5) = ", v2_std.max_size(), v2_ft.max_size());		
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.clear();
	v5_std.clear();
	display("Clear (v5) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.assign(5, 'E');
	v5_std.assign(5, 'E');
	display("Assign (5, 'E') // v5 =", v5_std, v5_ft);

	v5_ft.assign(4, 'F');
	v5_std.assign(4, 'F');
	display("Assign (4, 'F') // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.push_back('G');
	v5_std.push_back('G');
	display("Push back ('G') // v5 =", v5_std, v5_ft);
	v5_ft.assign(v5_ft.begin() + 2, v5_ft.end());
	v5_std.assign(v5_std.begin() + 2, v5_std.end());
	display("Assign (begin + 2, end) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.clear();
	v5_ft.push_back('H');
	v5_ft.push_back('I');
	v5_ft.push_back('J');
	v5_std.clear();
	v5_std.push_back('H');
	v5_std.push_back('I');
	v5_std.push_back('J');
	display("Clear + Push back ('H', 'I', 'J') // v5 =", v5_std, v5_ft);
	v5_ft.insert(v5_ft.begin() + 1, 'K');
	v5_std.insert(v5_std.begin() + 1, 'K');
	display("Insert (begin + 1, 'K') // v5 =", v5_std, v5_ft);

	v5_ft.insert(v5_ft.begin() + 1, 2, 'L');
	v5_std.insert(v5_std.begin() + 1, 2, 'L');
	display("Insert (begin + 1, 2, 'L') // v5 =", v5_std, v5_ft);

	v5_ft.insert(v5_ft.begin() + 4, v5_ft.begin() + 1, v5_ft.begin() + 3);
	v5_std.insert(v5_std.begin() + 4, v5_std.begin() + 1, v5_std.begin() + 3);
	display("Insert (beg + 4, beg + 1, beg + 3) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.erase(v5_ft.begin() + 4);
	v5_std.erase(v5_std.begin() + 4);
	display("Erase (begin + 4) // v5 =", v5_std, v5_ft);

	v5_ft.erase(v5_ft.begin() + 1, v5_ft.begin() + 3);
	v5_std.erase(v5_std.begin() + 1, v5_std.begin() + 3);
	display("Erase (begin + 1, begin + 3) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector<char> v6_std;
	v6_std.push_back('M');
	v6_std.push_back('N');
	ft::vector<char> v6_ft;
	v6_ft.push_back('M');
	v6_ft.push_back('N');
	display("Push back ('M', 'N') // v6 =", v6_std, v6_ft);
	v5_ft.swap(v6_ft);
	v5_std.swap(v6_std);
	display("Swap (v5, v6) // v5 =", v5_std, v5_ft);
	display("Swap (v5, v6) // v6 =", v6_std, v6_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v5_ft.resize(4);
	v5_std.resize(4);
	display("Resize (4) // v5 =", v5_std, v5_ft);
	v5_ft.resize(7, 'O');
	v5_std.resize(7, 'O');
	display("Resize (7, 'O') // v5 =", v5_std, v5_ft);
	v5_ft.resize(5);
	v5_std.resize(5);
	display("Resize (5) // v5 =", v5_std, v5_ft);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector <char> v7_std = v5_std;
	ft::vector <char> v7_ft = v5_ft;
	display("Copy (v5) // v7 =", v7_std, v7_ft);
	display_bool("Empty (v5) =", v5_std.empty(), v5_ft.empty());
	v5_ft.clear();
	v5_std.clear();
	display("Clear (v5) // v5 =", v5_std, v5_ft);
	display_bool("Empty (v5) =", v5_std.empty(), v5_ft.empty());
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	v7_std.reserve(20);
	v7_ft.reserve(20);
	display("Reserve (20) // v7 =", v7_std, v7_ft);
	display("Capacity (v7) =", v7_std.capacity(), v7_ft.capacity());
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector <char> v8_std;
	ft::vector <char> v8_ft;
	char * p_std = v8_std.get_allocator().allocate(3);
	char * p_ft = v8_ft.get_allocator().allocate(3);
	for (size_t i = 0; i < 3; i++) 
		v8_std.get_allocator().construct(&p_std[i], 'P' + i);
	for (size_t i = 0; i < 3; i++) 
		v8_ft.get_allocator().construct(&p_ft[i], 'P' + i);
	display("Get allocator (alloc + construct 'P', 'Q', 'R') // v8 =", p_std, p_ft, 3, 3);
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	display("v6 =", v6_std, v6_ft);
	display("Front (v6) =", v6_std.front(), v6_ft.front());
	display("Back (v6) =", v6_std.back(), v6_ft.back());
	display("Data (v6) =", v6_std.data(), v6_ft.data());
	display("Operator [] // v6[1] =", v6_std[1], v6_ft[1]);
	try
	{
		display("At (v6.at(1)) = ", v6_std.at(1), v6_ft.at(1));
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "At (v6.at(10)) = " << std::endl;
	try
	{
		display("At (v6.at(10)) = ", v6_std.at(10), v6_ft.at(10));
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	std::vector <char> v9_std = v6_std;
	ft::vector <char> v9_ft = v6_ft;
	display("v9 = v6 // v6 =", v6_std, v6_ft);
	v9_std[2] = 'S';
	v9_ft[2] = 'S';
	display("v9[2] = 'S' // v9 =", v9_std, v9_ft);
	display_bool("v6 == v9:", v6_std == v9_std, v6_ft == v9_ft);
	display_bool("v6 != v9:", v6_std != v9_std, v6_ft != v9_ft);
	display_bool("v6 > v9:", v6_std > v9_std, v6_ft > v9_ft);
	display_bool("v6 >= v9:", v6_std >= v9_std, v6_ft >= v9_ft);
	display_bool("v6 < v9:", v6_std < v9_std, v6_ft < v9_ft);
	display_bool("v6 <= v9:", v6_std <= v9_std, v6_ft <= v9_ft);

	std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;
	return 0;
}

int test_map_int(void)
{
	std::cout << std::left << std::setw(60) << " " << "m_std  |  m_ft" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::map<int, int> m1_std;
	ft::map<int, int> m1_ft;
	display_map("Constructor () // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std[50] = 1;
	m1_ft[50] = 1;
	display_map("Operator []: m1[50] = 1 // m1 = ", m1_std, m1_ft);

	m1_std[20] = 2;
	m1_std[70] = 3;
	m1_std[30] = 4;

	m1_ft[20] = 2;
	m1_ft[70] = 3;
	m1_ft[30] = 4;
	display_map("[]: (20,2) (70,3) (30,4) // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::map<int, int> m2_std(m1_std.begin(), --m1_std.end());
	ft::map<int, int> m2_ft(m1_ft.begin(), --m1_ft.end());
	display_map("Constructor (begin, end) // m2 = ", m2_std, m2_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;


	display_map("Begin (m2) = ", *m2_std.begin(), *m2_ft.begin());
	display_map("End (m2) = ", *m2_std.end(), *m2_ft.end());
	display_map("--End (m2) = ", *(--m2_std.end()), *(--m2_ft.end()));
	display_map("Rbegin (m2) = ", *m2_std.rbegin(), *m2_ft.rbegin());
	display_map("Rend (m2) = ", *m2_std.rend(), *m2_ft.rend());
	display_map("--Rend (m2) = ", *(--m2_std.rend()), *(--m2_ft.rend()));
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display("Size (m2) = ", m2_std.size(), m2_ft.size());
	display("Max_size (m2) = ", m2_std.max_size(), m2_ft.max_size());
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_bool("Empty (m2) = ", m2_std.empty(), m2_ft.empty());
	m2_std.clear();
	m2_ft.clear();
	display_map("Clear() // m2 = ", m2_std, m2_ft);
	display_bool("Empty (m2) = ", m2_std.empty(), m2_ft.empty());
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std[25] = 7;
	m1_ft[25] = 7;

	display_map("Add 25,7 // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_map("Find(25) = ", *m1_std.find(25), *m1_ft.find(25));
	display_map("Find(26) = ", *m1_std.find(26), *m1_ft.find(26));
	display_map("Count(25) = ", m1_std.count(25), m1_ft.count(25));
	display_map("Count(26) = ", m1_std.count(26), m1_ft.count(26));
	display_map("At(25) = ", m1_std.at(25), m1_ft.at(25));
	std::cout << "At(26) = " << std::endl;
	try
	{
		display_map("At(26) = ", m1_std.at(26), m1_ft.at(26));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::map<int, int>::reverse_iterator itrstd;
	ft::map<int, int>::iter_rev itrft;

	rdisplay_map("Reverse_iterator // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std.erase(m1_std.find(30));
	m1_ft.erase(m1_ft.find(30));
	display_map("Erase position [find(30)] // m1 = ", m1_std, m1_ft);

	m1_std.erase(25);
	m1_ft.erase(25);
	display_map("Erase key_type(25) // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std.insert (std::pair<int,int>(35, 8));
	m1_ft.insert (ft::pair<int,int>(35, 8) );
	display_map("Insert (35, 8) // m1 = ", m1_std, m1_ft);

	m1_std.insert (std::pair<int,int>(35, 8));
	m1_ft.insert (ft::pair<int,int>(35, 8) );
	display_map("Insert same (35, 8) // m1 = ", m1_std, m1_ft);

	m1_std.insert (m1_std.begin(), std::pair<int,int>(75, 9));
	m1_ft.insert (m1_ft.begin(), ft::pair<int,int>(75, 9) );
	display_map("Insert hint (begin, (75, 9)) // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std.erase(m1_std.find(35), m1_std.find(70));
	m1_ft.erase(m1_ft.find(35), m1_ft.find(70));
	display_map("Erase range [find(35), find(70)] // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_map("m2 = ", m2_std, m2_ft);

	m2_std.insert(std::pair<int, int>(50, 5));
	m2_std.insert(std::pair<int, int>(60, 12));
	m2_ft.insert(ft::pair<int, int>(50, 5));
	m2_ft.insert(ft::pair<int, int>(60, 12));
	display_map("Insert (50, 5)(60, 12) // m2 = ", m2_std, m2_ft);

	m1_std.insert(m2_std.begin(), m2_std.end());
	m1_ft.insert(m2_ft.begin(), m2_ft.end());
	display_map("Insert range (m2 begin, end) // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std.swap(m2_std);
	m1_ft.swap(m2_ft);
	display_map("Swap m1 m2 // m1 = ", m1_std, m1_ft);
	display_map("Swap m1 m2 // m2 = ", m2_std, m2_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_map("Lower_bound 1 (m2) = ", *m2_std.lower_bound(1), *m2_ft.lower_bound(1));
	display_map("Upper_bound 1 (m2) = ", *m2_std.upper_bound(1), *m2_ft.upper_bound(1));

	display_map("Equal range 1 (m2) = ", *(m2_std.equal_range(1).first), *(m2_std.equal_range(1).second), *(m2_ft.equal_range(1).first), *(m2_ft.equal_range(1).second));
	display_map("Equal range 49 (m2) = ", *(m2_std.equal_range(49).first), *(m2_std.equal_range(49).second), *(m2_ft.equal_range(49).first), *(m2_ft.equal_range(49).second));
	display_map("Equal range 50 (m2) = ", *(m2_std.equal_range(50).first), *(m2_std.equal_range(50).second), *(m2_ft.equal_range(50).first), *(m2_ft.equal_range(50).second));
	display_map("Equal range 51 (m2) = ", *(m2_std.equal_range(51).first), *(m2_std.equal_range(51).second), *(m2_ft.equal_range(51).first), *(m2_ft.equal_range(51).second));
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_bool("m1 == m2", (m1_std == m2_std), (m1_ft == m2_ft));
	display_bool("m1 != m2", (m1_std != m2_std), (m1_ft != m2_ft));
	display_bool("m1 < m2", (m1_std < m2_std), (m1_ft < m2_ft));
	display_bool("m1 <= m2", (m1_std <= m2_std), (m1_ft <= m2_ft));
	display_bool("m1 > m2", (m1_std > m2_std), (m1_ft > m2_ft));
	display_bool("m1 >= m2", (m1_std >= m2_std), (m1_ft >= m2_ft));

	return 0;
}

int test_map_char(void)
{
	std::cout << std::left << std::setw(60) << " " << "m_std  |  m_ft" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::map<char, char> m1_std;
	ft::map<char, char> m1_ft;
	display_map("Constructor () // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std['m'] = 'A';
	m1_ft['m'] = 'A';
	display_map("Operator []: m1[50] = 'A' // m1 = ", m1_std, m1_ft);

	m1_std['b'] = 'B';
	m1_std['s'] = 'C';
	m1_std['i'] = 'D';

	m1_ft['b'] = 'B';
	m1_ft['s'] = 'C';
	m1_ft['i'] = 'D';
	display_map("[]: (b, B) (s, C) (i, D) // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::map<char, char> m2_std(m1_std.begin(), --m1_std.end());
	ft::map<char, char> m2_ft(m1_ft.begin(), --m1_ft.end());
	display_map("Constructor (begin, end) // m2 = ", m2_std, m2_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_map("Begin (m2) = ", *(m2_std.begin()), *(m2_ft.begin()));
	display_map("End (m2) = ", *m2_std.end(), *m2_ft.end());
	display_map("--End (m2) = ", *(--m2_std.end()), *(--m2_ft.end()));
	display_map("Rbegin (m2) = ", *m2_std.rbegin(), *m2_ft.rbegin());
	display_map("Rend (m2) = ", *m2_std.rend(), *m2_ft.rend());
	display_map("--Rend (m2) = ", *(--m2_std.rend()), *(--m2_ft.rend()));
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display("Size (m2) = ", m2_std.size(), m2_ft.size());
	display("Max_size (m2) = ", m2_std.max_size(), m2_ft.max_size());
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_bool("Empty (m2) = ", m2_std.empty(), m2_ft.empty());
	m2_std.clear();
	m2_ft.clear();
	display_map("Clear() // m2 = ", m2_std, m2_ft);
	display_bool("Empty (m2) = ", m2_std.empty(), m2_ft.empty());
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std['e'] = 'E';
	m1_ft['e'] = 'E';

	display_map("Add (e, E) // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_map("Find('e') = ", *m1_std.find('e'), *m1_ft.find('e'));
	display_map("Find('f') = ", *m1_std.find('f'), *m1_ft.find('f'));
	display_map("Count('e') = ", m1_std.count('e'), m1_ft.count('e'));
	display_map("Count('f') = ", m1_std.count('f'), m1_ft.count('f'));
	display_map("At('e') = ", m1_std.at('e'), m1_ft.at('e'));
	std::cout << "At('f') = " << std::endl;
	try
	{
		display_map("At('f') = ", m1_std.at('f'), m1_ft.at('f'));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	std::map<char, char>::reverse_iterator itrstd;
	ft::map<char, char>::iter_rev itrft;

	rdisplay_map("Reverse_iterator // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std.erase(m1_std.find('i'));
	m1_ft.erase(m1_ft.find('i'));
	display_map("Erase position [find('i')] // m1 = ", m1_std, m1_ft);

	m1_std.erase('e');
	m1_ft.erase('e');
	display_map("Erase key_type('e') // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std.insert (std::pair<char, char>('k', 'F'));
	m1_ft.insert (ft::pair<char, char>('k', 'F') );
	display_map("Insert (k, F) // m1 = ", m1_std, m1_ft);

	m1_std.insert (std::pair<char, char>('k', 'G'));
	m1_ft.insert (ft::pair<char, char>('k', 'G') );
	display_map("Insert same (k, G) // m1 = ", m1_std, m1_ft);

	m1_std.insert (m1_std.begin(), std::pair<char, char>('w', 'H'));
	m1_ft.insert (m1_ft.begin(), ft::pair<char, char>('w', 'H') );
	display_map("Insert hint (begin, (w, H)) // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std.erase(m1_std.find('k'), m1_std.find('s'));
	m1_ft.erase(m1_ft.find('k'), m1_ft.find('s'));
	display_map("Erase range [find('k'), find('s')] // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_map("m2 = ", m2_std, m2_ft);

	m2_std.insert(std::pair<char, char>('m', 'I'));
	m2_std.insert(std::pair<char, char>('p', 'J'));
	m2_ft.insert(ft::pair<char, char>('m', 'I'));
	m2_ft.insert(ft::pair<char, char>('p', 'J'));
	display_map("Insert (m, I)(p, J) // m2 = ", m2_std, m2_ft);

	m1_std.insert(m2_std.begin(), m2_std.end());
	m1_ft.insert(m2_ft.begin(), m2_ft.end());
	display_map("Insert range (m2 begin, end) // m1 = ", m1_std, m1_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	m1_std.swap(m2_std);
	m1_ft.swap(m2_ft);
	display_map("Swap m1 m2 // m1 = ", m1_std, m1_ft);
	display_map("Swap m1 m2 // m2 = ", m2_std, m2_ft);
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_map("Lower_bound 'a' (m2) = ", *m2_std.lower_bound('a'), *m2_ft.lower_bound('a'));
	display_map("Upper_bound 'a' (m2) = ", *m2_std.upper_bound('a'), *m2_ft.upper_bound('a'));

	display_map("Equal range 'a' (m2) = ", *(m2_std.equal_range('a').first), *(m2_std.equal_range('a').second), *(m2_ft.equal_range('a').first), *(m2_ft.equal_range('a').second));
	display_map("Equal range 'l' (m2) = ", *(m2_std.equal_range('l').first), *(m2_std.equal_range('l').second), *(m2_ft.equal_range('l').first), *(m2_ft.equal_range('l').second));
	display_map("Equal range 'm' (m2) = ", *(m2_std.equal_range('m').first), *(m2_std.equal_range('m').second), *(m2_ft.equal_range('m').first), *(m2_ft.equal_range('m').second));
	display_map("Equal range 'n' (m2) = ", *(m2_std.equal_range('n').first), *(m2_std.equal_range('n').second), *(m2_ft.equal_range('n').first), *(m2_ft.equal_range('n').second));
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

	display_bool("m1 == m2", (m1_std == m2_std), (m1_ft == m2_ft));
	display_bool("m1 != m2", (m1_std != m2_std), (m1_ft != m2_ft));
	display_bool("m1 < m2", (m1_std < m2_std), (m1_ft < m2_ft));
	display_bool("m1 <= m2", (m1_std <= m2_std), (m1_ft <= m2_ft));
	display_bool("m1 > m2", (m1_std > m2_std), (m1_ft > m2_ft));
	display_bool("m1 >= m2", (m1_std >= m2_std), (m1_ft >= m2_ft));

	return 0;
}