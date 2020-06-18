#include "BST.h"
#include "Node.h"
#include <stdbool.h>
#include <stdlib.h>

void postOrderDelete(Node* node);
int inOrderList(double* arr, Node* node, int index);
bool recursiveContains(Node* node, double value);
bool recursiveInsert(Node* current, Node*parent, double value);
void deleteNode(BST* tree, Node* node, Node* parent);

//Done by Linda
BST* initializeBST()
{
    BST* tree = malloc(sizeof(BST));
    tree->count = 0;
    tree->root = NULL;
    return tree;
}

//Done by Linda
void deleteBST(BST* tree)
{
    //post order traversal to delete each node
    if (tree->count > 0)
        postOrderDelete(tree->root);
    //delete BST
    free(tree);
}

void postOrderDelete(Node* node)
{
    //TODO - Write a post-order traversal that deletes each node from memory
	//1-Traverse the left subtree, 2-Traverse the right subtree, 3-reach root
	if (node == NULL)//Base case
		return;
	postOrderDelete(node->left);
	postOrderDelete(node->right);
	free(node);
}

//Done by Linda
double* list(BST* tree)
{
    if (tree->count == 0)
        return NULL;
    double* arr = calloc(tree->count, sizeof(double));
    inOrderList(arr, tree->root, 0);
    return arr;
}

int inOrderList(double* arr, Node* node, int index)
{
    //TODO - Write an in-order traversal that places each value in the given array
    //     - Note: it needs to return index at the end to keep the index correctly
	//1-Traverse the left subtree, 2-reach root, 3-Traverse the right subtree
	if (node != NULL)
	{
		index = inOrderList(arr, node->left, index);
		arr[index] = node->value;
		index++;
		index = inOrderList(arr, node->right, index);
	}
	return index;
}

//Done by Linda
bool contains(BST* tree, double value)
{
   return recursiveContains(tree->root, value);
}

bool recursiveContains(Node* node, double value)
{
	//TODO - Write a recursive binary search for the given value
	//     - Return true if it's found, false if not
	// Base case
	if (node == NULL)
		return false;
	// Found value
	if (node->value == value)
		return true;	
	// Value is greater than node's value
	if (node->value < value)
		return recursiveContains(node->right, value);
	// Value is smaller than node's value
	else if (node->value > value)
		return recursiveContains(node->left, value);	
	// Not found value
	return false;
}

bool insert(BST* tree, double value)
{
    //if there are no nodes yet, make this value the root
    if (tree->count == 0)
    {
        tree->root = malloc(sizeof(Node));
        tree->root->value = value;
        tree->root->left = NULL;
        tree->root->right = NULL;
        tree->count++;
        return true;
    }
    //call recursive insert to handle the rest
    if (recursiveInsert(tree->root, NULL, value))
    {
        tree->count++;
        return true;
    }
    else
        return false;
}

bool recursiveInsert(Node* current, Node* parent, double value)
{
    //TODO - follow the lecture pseudocode to write the recursive insert function
    //     - returns true if the value was added, false if not
    //     - don't forget to set the new node's left and right child to NULL
	Node* newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	if (current == NULL)
	{
		if (parent == NULL)
			current = newNode;
		else
		{
			if (newNode->value < parent->value)
				parent->left = newNode;
			else if (newNode->value > parent->value)
				parent->right = newNode;
		}
		return true;
	}
	else if (newNode->value == current->value)
		return false;
	else if (newNode->value < current->value)
		recursiveInsert(current->left, current, newNode->value);
	else if (newNode->value > current->value)
		recursiveInsert(current->right, current, newNode->value);	
}

//Done by Linda
bool delete(BST* tree, double value)
{
    //handle if tree is empty
    if (tree->count == 0)
        return false;
    //find the value in the tree and its parent
    Node* node = tree->root;
    Node* parent = NULL;
    bool foundIt = (node->value == value);	
    while (node != NULL && !foundIt) 
	{
        if (value < node->value)
        {
            parent = node;
            node = node->left;
        }
        else if (value > node->value)
        {
            parent = node;
            node = node->right;
        }
        else
        {
            foundIt = true;
        }
    }
    if (!foundIt)
        return false;
    //call the deleteNode function to delete the found node
	deleteNode(tree, node, parent);
    tree->count--;
    return true;
}

void deleteNode(BST* tree, Node* node, Node* parent)
{	
	//TODO - follow the lecture pseudocode to write the deleteNode function
	//     - returns true if the value was deleted, false if not
	//     - don't forget to free the memory for the node you're deleting
	//No children
	if (node->left == NULL && node->right == NULL)
	{
		if (parent == NULL)
		{
			tree->root = NULL;
			free(tree->root);
		}
		else
		{
			if (parent->left == node)
				parent->left = NULL;
			else if (parent->right == node)
				parent->right = NULL;
			free(node);
		}
	}	
	//One right chill
	else if (node->left == NULL)
	{
		if (parent->left == node)
			parent->left = node->right;
		else if (parent->right == node)
			parent->right = node->left;
		free(node);
	}
	//One left chill
	else if (node->right == NULL)
	{	
		if (parent->left == node)
			parent->left = node->right;
		else if (parent->right == node)
			parent->right = node->left;		
		free(node);
	}
	//Two child case
	else
	{		
		Node* temp = node;		
		while (temp->right != NULL)
		{
			parent = temp;
			temp = temp->right;
		}
		node->value = temp->value;
		deleteNode(tree, temp, parent);		
	}
}

//Done by Linda
bool isEmpty(BST* tree)
{
    return (tree->count == 0);
}

//Done by Linda
int size(BST* tree)
{
    return tree->count;
}
