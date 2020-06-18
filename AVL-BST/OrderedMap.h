/*
* Project: OrderedMap project
* File: OrderedMap.h
* Author: Thong Ton, Thai Tran
* Date: 6/13/2019
* Description: This is STL OrderedMap
*/
#ifndef _ORDERED_MAP_
#define _ORDERED_MAP_
#include "Hashmap.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "BinarySearchTreeAVL.h"
#include <vector>
#include <stdexcept>

/*
* Class: OrderedMap
* Description: This class is an STL OrderedMap
* Data Members:
*	typename K - hold key
*   typename V - hold value
*/
template <typename K, typename V>
class OrderedMap
{
private:
	HashMap<K, V> map;
	LinkedList<K> list;
	int count = 0;
public:
	/*
	* Function: put
	* Description: Recieve a key and value then put in map
	* Input:
	*     K - Key
	*     V - Value
	* Output:
	*     A paired added to map
	*/
	void put(K key, V value)
	{
		map.put(key, value);
		if (!list.search(key))
			list.insertAt(list.getCount(), key);
		count++;
	}

	/*
	* Function: get
	* Description: Recieve a key then return a value hold that key
	* Input:
	*	K : key
	* Output:
	*	value at that key
	*/
	V get(const K key)
	{
		if (list.search(key))
			return map.get(key);
		throw std::out_of_range("The key does not exist");
	}

	/*
	* Function: containsKey
	* Description: reports if the key exists or not
	* Input:
	*	K : key
	* Output:
	*	true - if key exist
	*	false - if key doesn't exist
	*/ 
	bool containsKey(const K key)
	{
		return list.search(key);
	}

	/*
	* Function: containsValue
	* Description: searches the map for the given value and reports if it exists
	* Input:
	*	K : key
	* Output:
	*	true - if value exist
	*	false - if value doesn't exist
	*/
	bool containsValue(const V value)
	{	
		for (int i = 0; i < count; i++)
			if (map.get(list.get(i),value))
				return true;
		return false;
	}

	/*
	* Function: getKeys
	* Description: Returns a vector of all of the keys in insertion order
	* Output:
	*	vector : hold all keys exist - return empty vector if has no keys
	*/
	std::vector<K> getKeys()
	{
		std::vector<K> result;
		if (list.getCount() > 0)
			for (int i = 0; i < list.getCount(); i++)
				result.push_back(list.get(i));
		return result;
	}

	/*
	* Function: remove
	* Description: removes the key 
	*			   value pair from the map and the key from the linked list
	*			   throws an exception if the key does not exists
	* Output:
	*	input key is deleted if this key exist
	*/
	V remove(K key)
	{
		if (list.search(key))
		{
			V temp = map.get(key);
			//list.removeValue(key); //This doesn't work
			list.removeAt(list.getIndex(key));
			map.remove(key);
			count--;
			return temp;
		}
		throw std::out_of_range("There is no key");
	}

	/*
	* Function: clear
	* Description: Deletes all elements in the map and all keys in the linked list
	*/
	void clear()
	{
		map.~HashMap();
		list.~LinkedList();
		count = 0;
	}
	
	/*
	* Function: isEmpty
	* Description: reports if the map is empty or not
	*/
	bool isEmpty()
	{
		return count < 1;
	}
};
#endif  // !_ORDERED_MAP_

