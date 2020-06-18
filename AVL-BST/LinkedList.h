/*
* Project: OrderedMap project
* File: LinkedList.h
* Author: Thong Ton, Thai Tran
* Date: 6/13/2019
* Description: This is STL linked list
* Reference: Professor Linda Zuvich
*/
#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <stdexcept>

/*
* Struct: Node
* Description: A struct of node which hold data and next data
*/
template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};

/*
* Class: LinkedList
* Description: An STL Linked List
* Data member:
*	Node<T>* : template dynamic node
*	int count: amount of node in the link
*/
template <typename T>
class LinkedList
{
private:
	Node<T>* head;
	int count;
public:
	/*
	* Function: LinkedList
	* Description: List constructor
	* Output:
	*	initialize head with NULL
	*	initialize count with 0
	*/
	LinkedList()
	{
		head = NULL;
		count = 0;
	}

	/*
	* Function: ~LinkedList()
	* Description: Use to delete all node(Constructor)
	* Output:
	*	all node will be deleted
	*/
	~LinkedList()
	{
		while (count > 0)
			removeAt(0);
	}

	/*
	* Function: insertFront
	* Description: insert at the index 0 of list
	* Input: 
	*	T data: Given data
	* Output:
	*	data will be added at the beginning of list
	*/
	void insertFront(const T data)
	{
		Node<T>* newNode = new Node<T>{ data, head };
		head = newNode;
		count++;
	}

	/*
	* Function: insertAt
	* Description: Insert at given index with given data
	* Input:
	*	int index: Given index
	*	int data: Given data
	* Output:
	*	data will be add in list
	*/
	void insertAt(int index, const T data)
	{
		if (index < 0 || index > count)
			throw std::out_of_range("index out of range");
		if (index == 0)
		{
			insertFront(data);
			return;
		}
		Node<T>* temp = head;
		for (int i = 1; i < index; i++)
			temp = temp->next;
		Node<T>* newNode = new Node<T>{ data, temp->next };
		temp->next = newNode;
		count++;
	}

	/*
	* Function: get
	* Description: Get data at given index
	* Input:
	*	int index: given index
	* Output:
	*	T : template data at given index
	*/
	T get(int index)
	{
		if (index < 0 || index >= count)
			throw std::out_of_range("index out of range");
		Node<T>* temp = head;
		for (int i = 1; i <= index; i++)
			temp = temp->next;
		return temp->data;
	}

	/*
	* Function: search
	* Description: Search for given data
	* Input:
	*	T data: template given data
	* Output:
	*	true - if given data exist in list
	*	false - if given data doesn't exist in list
	*/
	bool search(const T data)
	{
		Node<T>* current = head; // Initialize current  
		while (current != NULL)
		{
			if (current->data == data)
				return true;
			current = current->next;
		}
		return false;
	}

	/*
	* Function: getIndex
	* Description: Get index at given data
	* Input:
	*	T data: template given data
	* Output:
	*	int - index that hold given data
	*/
	int getIndex(const T data)
	{
		Node<T>* current = head; // Initialize current  
		int count = 0;
		while (current != NULL)
		{
			if (current->data == data)
				return count;
			current = current->next;
			count++;
		}
		throw std::out_of_range("Invalid data");
	}

	/*
	* Function: removeAt
	* Description: remove at given index
	* Input:
	*	int index: given index
	* Output:
	*	a node at given index is removed
	*/
	void removeAt(int index)
	{
		if (index < 0 || index >= count)
			throw std::out_of_range("index out of range");
		Node<T>* curr = head;
		if (index == 0)
		{
			head = curr->next;
			delete(curr);
		}
		else
		{
			for (int i = 1; i < index; i++)
				curr = curr->next;
			Node<T>* temp = curr->next->next;
			delete(curr->next);
			curr->next = temp;
		}
		count--;
	}

	/*
	* Function: getCount
	* Description: Get the amount of node in the list
	* Output: 
	*	int - return amount of node
	*/
	int getCount() const
	{
		return count;
	}
};

#endif