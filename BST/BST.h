/*
 * Project: BstProject
 * File: BST.h
 * Author: Linda Zuvich
 * Last Modified: 3/28/2019
 * Description: This file contains a binary search tree (BST) struct definition
 *              and associated function prototypes.
 */
#ifndef _BST_
#define _BST_

#include <stdbool.h>
#include "Node.h"

 /*
  * Struct: BST
  * Description: Represents a complete BST.
  * Data Members:
  *     root - a pointer to the root node of the BST
  *     count - the current number of nodes in the BST
  */
typedef struct BST
{
    Node* root;
    int count;
} BST;

/*
 * Function: initializeBST
 * Description: Creates a dynamic BST struct object and returns
 *              a pointer to it.
 * Output:
 *     BST* - a pointer to the BST struct object
 */
BST* initializeBST();

/*
 * Function: deleteBST
 * Description: Frees the dynamic memory for all nodes in the BST
                and then deletes the BST itself from memory.
 * Input:
 *    tree - a pointer to the BST struct object to be deleted
 */
void deleteBST(BST* tree);

/*
 * Function: list
 * Description: Creates a dynamic array of all the values in the
 *              given BST in sorted order. NOTE: This function passes
 *              the responsibility to the caller to free the memory
 *              reserved for this array.
 * Input:
 *     tree - a pointer to the BST struct object
 * Output:
 *     double* - a pointer to the array
 */
double* list(BST* tree);

/*
 * Function: contains
 * Description: Checks if the given value exists in the given BST.
 * Input:
 *     tree - a pointer to the BST struct object to be deleted
 *     value - the value to search for
 * Output:
 *     bool - true if the tree contains the value, false if not
 */
bool contains(BST* tree, double value);

/*
 * Function: insert
 * Description: Adds the given value to the given BST if the value
                does not already exist in the tree.
 * Input:
 *     tree - a pointer to the BST struct object
 *     value - the value to add
 * Output:
 *     bool - true if the value was added, false if not (no duplicates allowed)
 */
bool insert(BST* tree, double value);

/*
 * Function: delete
 * Description: Removes the given value from the given BST if the value
                exists in the tree.
 * Input:
 *     tree - a pointer to the BST struct object
 *     value - the value to remove
 * Output:
 *     bool - true if the value was removed, false if not (not found)
 */
bool delete(BST* tree, double value);

/*
 * Function: isEmpty
 * Description: Reports if the given BST currently has any values in it.
 * Input:
 *     tree - a pointer to the BST struct object
 * Output:
 *     bool - true if the tree is empty, false if not
 */
bool isEmpty(BST* tree);

/*
 * Function: size
 * Description: Reports the number of values currently stored in the given BST.
 * Input:
 *     tree - a pointer to the BST struct object
 * Output:
 *     int - the number of values in the tree
 */
int size(BST* tree);

#endif
