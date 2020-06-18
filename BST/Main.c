#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Node.h"
#include "BST.h"

void testStartEnd();
void testEmpty();
void testSorted();
void printTree(BST* tree);
void printList(BST* tree);
void printNodes(Node* node, int spaces);


int main()
{
    printf("%s\n", "==========================================");
    printf("%s\n", "             TESTING BST");
    printf("%s\n", "         1 = true, 0 = false");
    printf("%s\n", "==========================================");
    testStartEnd();
    printf("%s\n", "==========================================");
    testEmpty();
    printf("%s\n", "==========================================");
    testSorted();
    //end
    getchar();
}

void testStartEnd()
{
    //test initializeBST
    BST* tree = initializeBST();
    printf("%s\n", "POST BST INITIALIZATION");
    printf("tree is initialized |%i\n", (tree->count == 0));
    //test deleteBST
    deleteBST(tree);
    printf("%s\n", "POST BST DELETE");
    printf("tree is initialized |%i\n", (tree->count == 0));
}

void testEmpty()
{
    //start
    BST* tree = initializeBST();
    //testing with no nodes
    printf("%s\n", "WITHOUT NODES:");
    //test list
    double* arr1 = list(tree);
    printf("Testing tree list is empty \t|%i\n", (arr1 == NULL));
    //test contains
    printf("Testing contains \t\t|%i\n", contains(tree, 7));
    //test delete
    printf("Testing deleted \t\t|%i\n", delete(tree, 7));
    //test isEmpty
    printf("Testing tree is empty \t\t|%i\n", isEmpty(tree));
    //test size
    printf("count = %i\n", size(tree));
    //end
    deleteBST(tree);
}

void testSorted()
{
    //start
    BST* tree = initializeBST();
    printf("%s\n", "WITH SORTED NODES:");
    //test adding unique values   	
	printf("add 30 | %i\n", insert(tree, 30));	
	printf("add 40 | %i\n", insert(tree, 40));
	printf("add 50 | %i\n", insert(tree, 50));
	printf("add 35 | %i\n", insert(tree, 35));
	printf("add 20 | %i\n", insert(tree, 20));
	printf("add 25 | %i\n", insert(tree, 25));
	printf("add 10 | %i\n", insert(tree, 10));	
	printf("add 15 | %i\n", insert(tree, 15));
	//Test print tree
	printf("Current tree structure:\n");
	printTree(tree);
	//Test print list
	printf("-Test print List:\n");
	printList(tree);
	//test the size function
	printf("-Count list = %i\n", size(tree));
    //test adding a duplicate
	printf("-Testing duplicate:\n");
    printf("Add 30 again | %i\n", insert(tree, 30));
	printf("Add 40 again | %i\n", insert(tree, 40));
	printf("Add 50 again | %i\n", insert(tree, 50));
    //test contains with an existing value
	printf("-Testing existing value:\n");
	printf("Test contain 0  | %d\n", contains(tree, 0));	
	printf("Test contain 30 | %d\n", contains(tree, 30));	
	printf("Test contain 70 | %d\n", contains(tree, 70));
	//test delete 
	printf("Test delete:\n");
	//printf("Delete 50 | %d\n", delete(tree, 50));	
	//printf("Delete 15 | %d\n", delete(tree, 15));
	//printf("Delete 40 | %d\n", delete(tree, 40));
	//printf("Delete 35 | %d\n", delete(tree, 35));
	//printf("Delete 10 | %d\n", delete(tree, 10));
	//printf("Delete 20 | %d\n", delete(tree, 20));
	//printf("Delete 25 | %d\n", delete(tree, 25));
	//printf("Delete 30 | %d\n", delete(tree, 30));
	//printf("Delete 25 | %d\n", delete(tree, 25));	
	//printf("Delete 20 | %d\n", delete(tree, 20));
	//printf("Delete 30 | %d\n", delete(tree, 30));
	printf("Delete  | %d\n", delete(tree, 20));
	printf("Current tree structure:\n");
	printTree(tree);
	printList(tree);
	deleteBST(tree);
    //end    	
}

/*
 * The following functions can be used to print out the entire tree structure horizontally
 * using a simple recursive function. It is good for testing correct insertion and deletion.
 */

void printTree(BST* tree)
{   
    printNodes(tree->root, 4);
    printf("\n");
}

void printNodes(Node* node, int spaces)
{
    int i;
    if (node != NULL)
    {
        printNodes(node->right, spaces + 10);
        for (i = 0; i < spaces; i++)
            printf(" ");
        printf("%.02f\n", node->value);
        printNodes(node->left, spaces + 10);
    }
}

void printList(BST* tree)
{	
	double* arr = list(tree);
	for (int i = 0; i < size(tree); i++)
		printf("%.2f ", arr[i]);
	printf("\n");
	free(arr);
}