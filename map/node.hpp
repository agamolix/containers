/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/12/23 13:38:57 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include "pair.hpp"
#include <functional>

template <typename Tkey, typename Tvalue>
class node
{
private:
	ft::pair<Tkey, Tvalue> key;
	node *left;
	node *right;
	node *parent;
	bool is_end;
	bool is_beg;

public:
	// ----- CONST, DESTR -----
	node(){};
	node(ft::pair<Tkey, Tvalue> k) : key(k), left(NULL), right(NULL), is_end(false), is_beg(false){};
	~node(){};
	node(node const &n) { *this = n; };

	node &operator=(node const &n)
	{
		key = n.key;
		left = n->left;
		right = n->right;
		is_end = n->is_end;
		is_beg = n->is_beg;
		return *this;
	}

	// ----- PREVIOUS, NEXT -----
	node *previous()
	{
		node *n = this;
		if (!n)
			return 0;
		if (is_min(n))
			return n->left;
		if (n->left)
			return max(n->left);
		if (is_right(n))
			return n->parent;
		node *temp = n;
		while (temp->key.first < n->parent->key.first)
			n = n->parent;
		return n->parent;
	}

	node *next()
	{
		node *n = this;
		if (!n)
			return 0;
		if (is_max(n))
			return n->right;
		if (n->right)
			return min(n->right);
		if (is_left(n))
			return n->parent;
		node *temp = n;
		while (temp->key.first > n->parent->key.first)
			n = n->parent;
		return n->parent;
	}

	// ----- MIN, MAX -----
	node *min(node *n)
	{
		if (!n)
			return 0;
		if (!(n->left) || n->left->is_beg)
			return n;
		return min(n->left);
	}

	node *max(node *n)
	{
		if (!n)
			return 0;
		if (!(n->right) || n->right->is_end)
			return n;
		return max(n->right);
	}

	// ----- BOOL -----
	bool is_root(node *n) { return !(n->parent); };
	bool is_parent(node *n) { return (n->left || n->right); };
	bool is_max() { return is_max(this); };
	bool is_min() { return is_min(this); };
	bool is_left() { return is_left(this); };
	bool is_right() { return is_right(this); };
	bool is_parent() { return is_parent(this); };
	bool is_root() { return is_root(this); };

	bool is_right(node *n)
	{
		if (is_root(n))
			return false;
		else if (n == n->parent->right)
			return true;
		return false;
	}

	bool is_left(node *n)
	{
		if (is_root(n))
			return false;
		else if (n == n->parent->left)
			return true;
		return false;
	}

	bool is_min(node *n)
	{
		node *temp = n;
		while (!(is_root(n)))
			n = n->parent;
		if (temp == min(n))
			return true;
		return false;
	}

	bool is_max(node *n)
	{
		node *temp = n;
		while (!(is_root(n)))
			n = n->parent;
		if (temp == max(n))
			return true;
		return false;
	}

	// ----- GET, SET -----
	void set_key(ft::pair<Tkey, Tvalue> p) { key = p; };
	void set_key_first(Tkey k) { key.first = k; };
	void set_key_second(Tvalue v) { key.second = v; };
	void set_left(node *n) { left = n; };
	void set_right(node *n) { right = n; };
	void set_parent(node *n) { parent = n; };
	void set_is_end(bool b) { is_end = b; };
	void set_is_beg(bool b) { is_beg = b; };

	ft::pair<Tkey, Tvalue> & get_key() { return key; };
	node *get_left() { return left; };
	node *get_right() { return right; };
	node *get_parent() { return parent; };
	bool get_is_end() { return is_end; };
	bool get_is_beg() { return is_beg; };
};

#endif