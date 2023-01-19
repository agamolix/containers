/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/12/23 13:38:57 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"

template <class Tkey, class Tvalue>
class tree
{
private:
	node<Tkey, Tvalue> *root;

public:
	// ----- CONST, DESTR -----
	tree<Tkey, Tvalue>() { root = NULL; };
	tree(ft::pair<Tkey, Tvalue> p) { set_new_root(p); };
	~tree(){};
	tree(tree const &t) { *this = t; };
	tree &operator=(tree const &t)
	{
		root = t.root;
		return *this;
	};

	// ----- ROOT -----
	node<Tkey, Tvalue> *set_new_root(ft::pair<Tkey, Tvalue> p)
	{
		node<Tkey, Tvalue> *n = new node<Tkey, Tvalue>(p);
		n->set_key(p);
		n->set_left(NULL);
		n->set_parent(NULL);
		n->set_is_end(false);
		n->set_is_beg(false);

		node<Tkey, Tvalue> *end = new node<Tkey, Tvalue>;
		end->set_parent(n);
		end->set_is_end(true);
		end->set_key_first(1);
		n->set_right(end);

		node<Tkey, Tvalue> *beg = new node<Tkey, Tvalue>;
		beg->set_parent(n);
		beg->set_is_beg(true);
		end->set_key_first(1);
		n->set_left(beg);

		root = n;
		return root;
	}

	// ----- END -----
	void set_end()
	{
		node<Tkey, Tvalue> *end = new node<Tkey, Tvalue>;
		end->set_parent(max());
		end->set_is_end(true);
		end->set_key_first(size());
		end->set_key_second(0);
		max()->set_right(end);
	}

	void remove_end()
	{
		node<Tkey, Tvalue> *end = next(max());
		delete (end);
		max()->set_right(NULL);
	}

	// ----- BEG -----
	void set_beg()
	{
		node<Tkey, Tvalue> *beg = new node<Tkey, Tvalue>;
		beg->set_parent(min());
		beg->set_is_beg(true);
		beg->set_key_first(size());
		beg->set_key_second(0);
		min()->set_left(beg);
	}

	void remove_beg()
	{
		node<Tkey, Tvalue> *beg = previous(min());
		delete (beg);
		min()->set_left(NULL);
	}

	// ----- INSERT -----
	node<Tkey, Tvalue> *insert(ft::pair<Tkey, Tvalue> k)
	{
		if (!root)
			return (set_new_root(k));
		return (insert(root, k));
	}

	node<Tkey, Tvalue> *insert(node<Tkey, Tvalue> *n, ft::pair<Tkey, Tvalue> k)
	{
		remove_beg();
		remove_end();
		node<Tkey, Tvalue> *res = insert(n, k, 0);
		set_beg();
		set_end();
		return res;
	}

	node<Tkey, Tvalue> *insert(node<Tkey, Tvalue> *n, ft::pair<Tkey, Tvalue> k, node<Tkey, Tvalue> *p)
	{
		if (!n)
		{
			n = new node<Tkey, Tvalue>;
			n->set_key(k);
			n->set_left(NULL);
			n->set_right(NULL);
			n->set_parent(p);
			n->set_is_beg(false);
			n->set_is_end(false);
		}
		else if (k.first < n->get_key().first)
			n->set_left(insert(n->get_left(), k, n));
		else
			n->set_right(insert(n->get_right(), k, n));
		return n;
	}

	// ----- SEARCH -----
	node<Tkey, Tvalue> *search(Tkey k)
	{
		return (search(root, k));
	}

	node<Tkey, Tvalue> *search(node<Tkey, Tvalue> *n, Tkey k)
	{
		if (!n)
			return 0;
		else if (n->get_key().first == k)
			return n;
		else if (k < n->get_key().first)
		{
			if (n->get_left() && !(n->get_left()->get_is_beg()))
				return (search(n->get_left(), k));
			else
				return 0;
		}
		else
		{
			if (n->get_right() && !(n->get_right()->get_is_end()))
				return (search(n->get_right(), k));
			else
				return 0;
		}
		return 0;
	}

	// ----- REMOVE -----
	void remove_all()
	{
		remove_branch(root);
	}

	void remove_branch(node<Tkey, Tvalue> *(&(n)))
	{
		if (n)
		{
			remove_branch_ptr(n->get_left());
			remove_branch_ptr(n->get_right());
			delete n;
			n = NULL;
		}
	}

	void remove_branch_ptr(node<Tkey, Tvalue> *n)
	{
		if (n)
		{
			remove_branch_ptr(n->get_left());
			remove_branch_ptr(n->get_right());
			delete n;
			n = NULL;
		}
	}

	node<Tkey, Tvalue> *remove_node(Tkey k)
	{
		remove_beg();
		remove_end();
		node<Tkey, Tvalue> *n = search(k);
		node<Tkey, Tvalue> *res = remove_node(root, n->get_key().first, NULL);
		set_beg();
		set_end();
		return res;
	}

	node<Tkey, Tvalue> *remove_node(node<Tkey, Tvalue> *n, Tkey k, node<Tkey, Tvalue> *p)
	{
		node<Tkey, Tvalue> *temp;
		if (!n)
			return 0;
		else if (k < n->get_key().first)
			n->set_left(remove_node(n->get_left(), k, n));
		else if (k > n->get_key().first)
			n->set_right(remove_node(n->get_right(), k, n));
		else if (n->get_left() && !n->get_right())
		{
			temp = n;
			n = n->get_left();
			n->set_parent(p);
			if (!p)
				root = n;
			delete temp;
		}
		else if (!n->get_left() && n->get_right())
		{
			temp = n;
			n = n->get_right();
			n->set_parent(p);
			if (!p)
				root = n;
			delete temp;
		}
		else if (n->get_left() && n->get_right())
		{
			temp = min(n->get_right());
			n->set_key(temp->get_key());
			n->set_right(remove_node(n->get_right(), n->get_key().first, n));
		}
		else
			delete (n = 0);
		return n;
	}

	// ----- MIN, MAX -----
	node<Tkey, Tvalue> *min()
	{
		return min(root);
	}

	node<Tkey, Tvalue> *min() const
	{
		return min(root);
	}

	node<Tkey, Tvalue> *min(node<Tkey, Tvalue> *n)
	{
		if (!n)
			return 0;
		if (!(n->get_left()) || n->get_left()->get_is_beg())
			return n;
		return min(n->get_left());
	}

	node<Tkey, Tvalue> *min(node<Tkey, Tvalue> *n) const
	{
		if (!n)
			return 0;
		if (!(n->get_left()) || n->get_left()->get_is_beg())
			return n;
		return min(n->get_left());
	}

	node<Tkey, Tvalue> *max()
	{
		return max(root);
	}

	node<Tkey, Tvalue> *max(node<Tkey, Tvalue> *n)
	{
		if (!n)
			return 0;
		if (!(n->get_right()) || n->get_right()->get_is_end())
			return n;
		return max(n->get_right());
	}

	// ----- PREVIOUS, NEXT -----
	node<Tkey, Tvalue> *previous(node<Tkey, Tvalue> *n)
	{
		if (!n || n->is_min())
			return 0;
		if (n->get_left())
			return max(n->get_left());
		if (n->is_right())
			return n->get_parent();
		node<Tkey, Tvalue> *temp = n;
		while (temp->get_key().first < n->get_parent()->get_key().first)
			n = n->get_parent();
		return n->get_parent();
	}

	node<Tkey, Tvalue> *next(node<Tkey, Tvalue> *n)
	{
		if (!n)
			return 0;
		if (n->is_max())
			return n->get_right();
		if (n->get_right())
			return min(n->get_right());
		if (n->is_left())
			return n->get_parent();
		node<Tkey, Tvalue> *temp = n;
		while (temp->get_key().first > n->get_parent()->get_key().first)
			n = n->get_parent();
		return n->get_parent();
	}

	// ----- LOWER, UPPER -----
	node<Tkey, Tvalue> *lower(Tkey k)
	{
		node<Tkey, Tvalue> *res = min();
		while (res->get_key().first < k)
		{
			res = next(res);
			if (res->get_is_end())
				break;
		}
		return res;
	}

	node<Tkey, Tvalue> *upper(Tkey k)
	{
		node<Tkey, Tvalue> *res = min();
		while (res->get_key().first <= k)
		{
			res = next(res);
			if (res->get_is_end())
				break;
		}
		return res;
	}

	// -----SIZE -----
	int size()
	{
		int res = 1;
		node<Tkey, Tvalue> *n = min();
		while (n != max())
		{
			n = next(n);
			res++;
		}
		return res;
	}

	// ----- GET, SET -----
	void set_root(node<Tkey, Tvalue> *n) { root = n; };
	node<Tkey, Tvalue> *get_root() { return root; };
};

#endif