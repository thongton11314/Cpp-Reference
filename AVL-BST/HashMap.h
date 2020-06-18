/*
* Project: OrderedMap project
* File: OrderedMap.h
* Author: Thong Ton, Thai Tran
* Date: 6/13/2019
* Description: This is STL OrderedMap
* Rerferences https://www.sanfoundry.com/cpp-program-implement-hash-tables/
* Rerferences https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
*/

#ifndef _HASH_MAP_
#define _HASH_MAP_
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <stdexcept>
#include <vector>
#include "BinarySearchTreeAVL.h"
#include "BinarySearchTree.h"

//Table Size
const int TABLE_SIZE = 128;

/*
* Struct: KeyHash
* Description:  Default hash function class
*/
template <typename K>
struct KeyHash
{
	/*
	* Function: operator
	* Description: get key hash
	* Input:
	*	K key - key to be hashed
	* Output:
	*	value key hash
	*/
	unsigned long operator()(const K key) const
	{
		return static_cast<unsigned long>(key) % TABLE_SIZE;
	}
};

/*
* Class: HashMap
* Description: Will be used to implement Map by hashing key and pair value with key
* Data member:
*	avl HasTablep[] - hold the hashed key
*	F hasFunc - hash key
*/
template <typename K, typename V, typename F = KeyHash<K>>
class HashMap 
{
private:
	TT_AVL::avl<V> hashTable[TABLE_SIZE];
	F hashFunc;	
public:
	/*
	* Function: ~HashMap
	* Description: Deconstruct of HashMap, delete all hashed key in hash table
	* Output:
	*	hasTable has no hashed key
	*/
	~HashMap()
	{
		//destroy all buckets one by one
		for (int i = 0; i < TABLE_SIZE; ++i)
			this->hashTable[i].delTree();
	}

	/*
	* Function: put
	* Description: get input key and value to hash then make a pair
	* Output:
	*	a pair is added
	*/
	void put(const K key, const V value)
	{
		unsigned long hashValue = hashFunc(key);
		if (this->hashTable[hashValue].isempty())
			this->hashTable[hashValue].insert(value);
		else if (!this->hashTable[hashValue].isExist(value))
			this->hashTable[hashValue].insert(value);
	}

	/*
	* Function: get
	* Description: Get the value at the given key
	* Output:
	*	return value at key if key exist
	*	exception if key is not exist
	*/
	V get(const K key)
	{
		unsigned long hashValue = hashFunc(key);
		if (!this->hashTable[hashValue].isempty())
			return this->hashTable[hashValue].getRootValue();
		throw std::out_of_range("Key doesn't exist");
	}

	/*
	* Function: get
	* Description: Check if this input key has input value
	* Output:
	*	true - if given key hold given value
	*	false - if given key doens't hold given value
	*/
	bool get(const K key, V value)
	{
		unsigned long hashValue = hashFunc(key);
		if (this->hashTable[hashValue].isExist(value))
			return true;
		return false;
	}

	/*
	* Function: remove
	* Description: Remove given key
	* Output:
	*	a key is removed
	*/
	void remove(const K key)
	{
		unsigned long hashValue = hashFunc(key);
		TT_AVL::avl<V> bucket = this->hashTable[hashValue];
		this->hashTable[hashValue].delTree();
	}
};
#endif // !_HASH_MAP_