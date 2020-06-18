//#include "BinarySearchTree.h"
//#include <iostream>
//#include <iomanip>
//#include <exception>
//#include <stdexcept>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
////--------------------------------------------------------------------
//// overloaded =
//// throws bad_alloc
////--------------------------------------------------------------------
//template <class T>
//bst<T>& bst<T>::operator=(const bst<T>& t)
//{
//	if (this != &t)
//	{
//		if (!isempty())
//			delTree(root);
//		if (!t.isempty())
//		{
//			root = new node<T>(*(t.root));
//		}
//	}
//	return *this;
//}
//
////--------------------------------------------------------------------
//// overloaded +=
//// throws bad_alloc
////--------------------------------------------------------------------
//template <class T>
//bst<T>& bst<T>::operator+=(const bst<T>& t)
//{
//	addTree(t.root);
//	return *this;
//}
//
////--------------------------------------------------------------------
//// recursively adds in the contents of a second tree
////--------------------------------------------------------------------
//template <class T>
//void bst<T>::addTree(const node<T>* np)
//{
//	if (np != nullptr)
//	{
//		addTree(np->left);
//		addTree(np->right);
//		insert(np->value(), root);
//	}
//}
//
////--------------------------------------------------------------------
//// Title: BST::contains
//// Description: checks if an item is in the tree
//// Called By: AVL and Set methods and driver
//// Calls: findFirstOf
//// Parameters: item to find
//// Returns: True if item exists
////--------------------------------------------------------------------
//template<class T>
//bool bst<T>::isExist(const T & d)
//{
//	node<T>* matchptr = nullptr;
//	findFirstOf(d, getroot(), matchptr);
//	return matchptr != nullptr;
//}
//
////--------------------------------------------------------------------
//// recursively finds the first occurance of a data item
//// pre: match must be set to nullptr
////--------------------------------------------------------------------
//template <class T>
//void bst<T>::findFirstOf(const T& d, node<T>* &np, node<T>* &match)
//{
//	if (match != nullptr)
//		return;
//	if (np != nullptr)
//	{
//		findFirstOf(d, np->left, match);
//		if (d == np->value())
//		{
//			match = np;
//			parentptr = &np;
//			return;
//		}
//		findFirstOf(d, np->right, match);
//	}
//}
//
////--------------------------------------------------------------------
//// inserts a new element
//// into the tree
////--------------------------------------------------------------------
//template <class T>
//bool bst<T>::insert(T d)
//{
//	return insert(d, root);
//}
//
////--------------------------------------------------------------------
//// inserts a new element
//// into the tree
//// throws bad_alloc
////--------------------------------------------------------------------
//template <class T>
//bool bst<T>::insert(T d, node<T>* &cur)
//{
//	if (cur == nullptr)
//	{
//		cur = new node<T>(d);
//		if (isempty())
//			root = cur;
//		return true;
//	}
//	else if (!isExist(d))
//	{
//		if (d < cur->value())
//			insert(d, cur->left);
//		else
//			insert(d, cur->right);
//		if (root != nullptr)
//			root->setHeight();
//		return true;
//	}
//	return false;
//}
//
////------------------------------------------------------------------------
//// recursuively sets levelVector to represent the specified level 
////------------------------------------------------------------------------
//template <class T>
//void bst<T>::setLevel(node<T>* cur, vector<T>& levelVector, int level2print, int position) const
//{
//	static int currentLevel = -1;
//	if (level2print < 0)
//		return;
//	if (cur != nullptr)
//	{
//		currentLevel++;
//		if (currentLevel < level2print)
//			setLevel(cur->left, levelVector, level2print, position * 2);
//		if (currentLevel == level2print)
//			levelVector[position] = cur->value();
//		if (currentLevel < level2print)
//			setLevel(cur->right, levelVector, level2print,
//				position * 2 + 1);
//		currentLevel--;
//	}
//}
//
////-------------------------------------------------------------------- 
//// recursively deletes out the subtree
////--------------------------------------------------------------------
//template <class T>
//void bst<T>::delTree(node<T>* &cur)
//{
//	if (cur != nullptr)
//	{
//		delTree(cur->left);
//		delTree(cur->right);
//		delete cur;
//		cur = nullptr;
//		if (root != nullptr)
//			root->setHeight();
//	}
//}
//
////-------------------------------------------------------------------- 
//// pops a given node
////--------------------------------------------------------------------
//template <class T>
//T bst<T>::popNode(node<T>* &cur)
//{
//	if (cur == nullptr)
//		throw (invalid_argument("Pointer does not point to a node"));
//	T contents = cur->value();
//	if (cur->left == nullptr && cur->right == nullptr)
//	{ // no children
//		delete cur;
//		cur = nullptr;
//	}
//	else if (cur->left == nullptr)
//	{ // only right child
//		node<T>* temp = cur->right;
//		delete cur;
//		cur = temp;
//	}
//	else if (cur->right == nullptr)
//	{ // only left child
//		node<T>* temp = cur->left;
//		delete cur;
//		cur = temp;
//	}
//	else
//	{ // two children
//		cur->setdata(popHigh(cur->left));
//		// pops leftmost node of right child and
//		// places that value into the current node
//	}
//	if (root != nullptr)
//		root->setHeight();
//	return contents;
//}
//
////-------------------------------------------------------------------- 
//// pops out the leftmost child of cur
////--------------------------------------------------------------------
//template <class T>
//T bst<T>::popLow(node<T>* &cur)
//{
//	if (cur == nullptr)
//		throw (invalid_argument("Pointer does not point to a node"));
//	if (cur->left == nullptr)
//	{
//		T temp = cur->value();
//		node<T>* temptr = cur->right;
//		delete cur;
//		cur = temptr;
//		if (root != nullptr)
//			root->setHeight();
//		return temp;
//	}
//	return popLow(cur->left);
//}
//
////------------------------------------------------------------------------
//// pops out the rightmost child of cur
//// throws invalid_argument
////------------------------------------------------------------------------
//template <class T>
//T bst<T>::popHigh(node<T>* &cur)
//{
//	if (cur == nullptr)
//		throw(invalid_argument("Pointer does not point to a node"));
//	if (cur->right == nullptr)
//	{
//		T temp = cur->value();
//		node<T>* temptr = cur->left;
//		delete cur;
//		cur = temptr;
//		if (root != nullptr)
//			root->setHeight();
//		return temp;
//	}
//	return popHigh(cur->right);
//}
//
////-------------------------------------------------------------------- 
//// pops first node matching d
////--------------------------------------------------------------------
//template <class T>
//T bst<T>::popFirstOf(const T& d, node<T>*& np)
//{
//	node<T>* matchptr = nullptr;
//	findFirstOf(d, np, matchptr);
//	if (*parentptr != nullptr)
//	{
//		if ((*parentptr)->value() == d)
//			return popNode((*parentptr));
//	}
//	if (root != nullptr)
//		root->setHeight();
//	return 0;
//}
//
////-------------------------------------------------------------------- 
//// returns the number of nodes in the tree
//// recursive
////--------------------------------------------------------------------
//template <class T>
//int bst<T>::getNumberOfNodes(node<T>* np) const
//{
//	int count = 1;
//	if (np != nullptr)
//	{
//		count += getNumberOfNodes(np->left);
//		count += getNumberOfNodes(np->right);
//		return count;
//	}
//	return 0;
//}

