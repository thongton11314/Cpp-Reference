/*
 * Project: BstProject
 * File: Node.h
 * Author: Linda Zuvich
 * Last Modified: 3/28/2019
 * Description: This file contains the Node struct definition to be use
 *              in a binary search tree (BST).
 */
#ifndef _NODE_
#define _NODE_

/*
 * Struct: Node
 * Description: Represents a single node in a BST that contains doubles.
 * Data Members:
 *    value - the double to be stored in this node
 *    left - a pointer to the left child of this node, or NULL if there is none
 *    right - a pointer to the right child of this node, or NULL if there is none
 */
typedef struct Node
{
    double value;
    struct Node* left;
    struct Node* right;
} Node;

#endif