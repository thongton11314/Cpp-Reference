/*
* Project: OrderedMap Project
* File: Source.cpp
* Author: Thong Ton, Thai Tran
* Date: 6/13/2019
* Description: This project is created an OrderedMap
* Referece:
*	 Professor Linda Zuvich and Paul Bladek 
*	 https://www.sanfoundry.com/cpp-program-implement-hash-tables/
*	 https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
*/
#include "OrderedMap.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Prototype
void testAddingPair(OrderedMap<int, string>& map, vector<int> key, vector<string> value);
void testGetValueByKey(OrderedMap<int, string>& map, vector<int> key, vector<string> value);
void testContainKey(OrderedMap<int, string>& map, vector<int> key);
void testContainValue(OrderedMap<int, string>& map, vector<string> value);
void testGetAllKey(OrderedMap<int, string>& map, vector<int> key);
void testRemove(OrderedMap<int, string>& map, vector<int> key, vector<string> value);
void testIsEmpty(OrderedMap<int, string>& map);
void testClear(OrderedMap<int, string>& map);
void testDuplicate(OrderedMap<int, string>& map, vector<int> key, vector<string> value);

/*
* Function: main
* Description: Test all funciton
*/
int main()
{
	////Test map without duplicate
	vector<int> key = { 1001, 1002, 1003, 1004, 1005 };
	vector<string> value = { "One", "Two", "Three", "Four", "Five" };
	OrderedMap<int, string> testMap;
	testAddingPair(testMap, key, value);
	testGetValueByKey(testMap, key, value);
	testContainKey(testMap, key);
	testContainValue(testMap, value);
	testGetAllKey(testMap, key);
	testRemove(testMap, key, value);
	testIsEmpty(testMap);
	testClear(testMap);
	//Test map with duplicate
	OrderedMap<int, string> testMap1;
	testDuplicate(testMap1, key, value);
	getchar();
	//end
	return EXIT_SUCCESS;
}

/*
* Function: testAddingPair
* Description: Test adding pair
* Input:
*	OrderedMap<int, string> map - container map type string
*	vector<int> key - hold amount of keys
*	vector<string> value - hold amount of value
*/
void testAddingPair(OrderedMap<int, string>& map, vector<int> key, vector<string> value)
{
	//Assign key and value
	for (unsigned int i = 0; i < key.size(); i++)
		map.put(key.at(i), value.at(i));
	//Print out passed/failed
	if(!map.isEmpty())
		cout << "Test adding Pair" << "\t\t" << "Passed" << endl;
	else
		cout << "Test adding Pair" << "\t\t" << "Failed" << endl;
}

/*
* Function: testGetValueByKey
* Description: Test geting value (get function)
* Input:
*	OrderedMap<int, string> map - container map type string
*	vector<int> key - hold amount of keys
*	vector<string> value - hold amount of value
*/
void testGetValueByKey(OrderedMap<int, string>& map, vector<int> key, vector<string> value)
{	
	//Hold numerical equal times
	int count = 0;
	//Compare each value
	for (unsigned int i = 0; i < map.getKeys().size(); i++)
		if (map.get(key.at(i)) == value.at(i))
			count++;	
	//Print out passed/failed
	if(count == map.getKeys().size())
		cout << "Test valid get by key" << "\t\t" << "Passed" << endl;
	else
		cout << "Test valid get by key" << "\t\t" << "Failed" << endl;
	//Test exception
	try
	{
		map.get(1);
	}
	catch (out_of_range)
	{
		cout << "Test invalid get by key" << "\t\t" << "Passed" << endl;
	}
}

/*
* Function: testContainKey
* Description: Test contain key
* Input:
*	OrderedMap<int, string> map - container map type string
*	vector<int> key - hold amount of keys
*/
void testContainKey(OrderedMap<int, string>& map, vector<int> key)
{
	//Hold numerical keys exist in map
	int count = 0;
	for (unsigned int i = 0; i < map.getKeys().size(); i++)
		if (map.containsKey(key.at(i)))
			count++;
	if(count == map.getKeys().size())
		cout << "Test valid contain key" << "\t\t" << "Passed" << endl;
	else
		cout << "Test valid contain key" << "\t\t" << "Failed" << endl;
}

/*
* Function: testContainValue
* Description: Test contain value
* Input:
*	OrderedMap<int, string> map - container map type string
*	vector<int> key - hold amount of keys
*/
void testContainValue(OrderedMap<int, string>& map, vector<string> value)
{
	int count = 0;
	for (unsigned int i = 0; i < map.getKeys().size(); i++)
		if (map.containsValue(value.at(i)))
			count++;
	if (count == map.getKeys().size())
		cout << "Test valid contain value" << "\t" << "Passed" << endl;
	else
		cout << "Test valid contain value" << "\t" << "Failed" << endl;
}

/*
* Function: testGetAllKey
* Description: Test get Key
* Input:
*	OrderedMap<int, string> map - container map type string
*	vector<int> key - hold amount of keys
*/
void testGetAllKey(OrderedMap<int, string>& map, vector<int> key)
{
	vector<int> allKey = map.getKeys();
	int count = 0;
	for (unsigned int i = 0; i < allKey.size(); i++)
		if (allKey.at(i) == key.at(i))
			count++;
	if (count == allKey.size())
		cout << "Test get all keys" << "\t\t" << "Passed" << endl;
	else
		cout << "Test get all keys" << "\t\t" << "Failed" << endl;	
}

/*
* Function: testRemove
* Description: Test remove
* Input:
*	OrderedMap<int, string> map - container map type string
*	vector<int> key - hold amount of keys
*	vector<string> value - hold amount of value
*/
void testRemove(OrderedMap<int, string>& map, vector<int> key, vector<string> value)
{
	//Using for loop like this can be apply for any cases
	for (unsigned int i = 0; i < key.size() - 1; i++)
		map.remove(key[i]);
	if(map.get(key.at(key.size() - 1)) == value.at(value.size() - 1))
		cout << "Test valid remove" << "\t\t" << "Passed" << endl;
	else
		cout << "Test valid remove" << "\t\t" << "Failed" << endl;
	try
	{
		map.remove(key[map.getKeys().size() + 1]);
	}
	catch (out_of_range)
	{
		cout << "Test in valid remove" << "\t\t" << "Passed" << endl;
	}
}

/*
* Function: testIsEmpty
* Description: Test empty
* Input:
*	OrderedMap<int, string> map - container map type string
*/
void testIsEmpty(OrderedMap<int, string>& map)
{
	if (!map.isEmpty())
		cout << "Test empty" << "\t\t\t" << "Passed" << endl;
	else
		cout << "Test empty" << "\t\t\t" << "Failed" << endl;
}

/*
* Function: testClear
* Description: Test clear
* Input: OrderedMap<int, string> map - container map type string
*/
void testClear(OrderedMap<int, string>& map)
{
	map.clear();
	if (map.isEmpty())
		cout << "Test clear" << "\t\t\t" << "Passed" << endl;
	else
		cout << "Test clear" << "\t\t\t" << "Failed" << endl;
}

/*
* Function: testDuplicate
* Description: Test duplicate(prevent collision)
* Input:
*	OrderedMap<int, string> map - container map type string
*	vector<int> key - hold amount of keys
*	vector<string> value - hold amount of value
*/
void testDuplicate(OrderedMap<int, string>& map, vector<int> key, vector<string> value)
{
	int count = 0;
	for (unsigned int i = 0; i < value.size(); i++)
		map.put(key[0], value.at(i));
	for (unsigned int i = 0; i < value.size(); i++)
		if (map.containsValue(value.at(i)))
			count++;
	if (count == value.size())
		cout << "Test same key" << "\t\t\t" << "Passed" << endl;
	else
		cout << "Test same key" << "\t\t\t" << "Failed" << endl;
}
