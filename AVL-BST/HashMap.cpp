#include "HashMap.h"

using namespace std;


template<typename K, typename V, typename F>
inline HashMap<K, V, F>::~HashMap()
{
	//destroy all buckets one by one
	for (int i = 0; i < TABLE_SIZE; ++i)
	{
		this->hashTable[i].delTree();
	}
}

template<typename K, typename V, typename F>
bool HashMap<K, V, F>::get(const K key, V value)
{
	unsigned long hashValue = hashFunc(key);
	if (this->hashTable[hashValue].isExist(value))
		return true;
	return false;
}

template<typename K, typename V, typename F>
V HashMap<K, V, F>::get(const K key)
{
	V value;
	unsigned long hashValue = hashFunc(key);
	if (!this->hashTable[hashValue].isempty())
		return this->hashTable[hashValue].getRootValue();
	return value;
}

template<typename K, typename V, typename F>
void HashMap<K, V, F>::put(const K key, const V value)
{
	unsigned long hashValue = hashFunc(key);
	if (this->hashTable[hashValue].isempty())
		this->hashTable[hashValue].insert(value);
	else if (!this->hashTable[hashValue].isExist(value))
	{
		this->hashTable[hashValue].insert(value);
	}
}

template<typename K, typename V, typename F>
void HashMap<K, V, F>::remove(const K key)
{
	unsigned long hashValue = hashFunc(key);
	TT_AVL::avl<V> bucket = this->hashTable[hashValue];
	this->hashTable[hashValue].delTree();
}