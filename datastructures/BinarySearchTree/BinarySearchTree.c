#include "BinarySearchTree.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Node * create_node_bst(void *data, unsigned long size);
void destroy_node_bst(struct Node *node_to_destroy);
    
struct Node * iterate_bst(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction);
void recursive_tree_destruction(struct Node *node);

void * search_bst(struct BinarySearchTree *tree, void *data);
void insert_bst(struct BinarySearchTree *tree, void *data, unsigned long size);

struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two))
{
    struct BinarySearchTree tree ={
        .head = NULL,
        .compare = compare,
        .search = search_bst,
        .insert = insert_bst
    };

    return tree;
}

void binary_search_tree_destructor(struct BinarySearchTree tree)
{
    recursive_tree_destruction(tree.head);
}


struct Node * create_node_bst(void *data, unsigned long size)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    *new_node = n_constructor(data, size);

    return new_node;
}

void destroy_node_bst(struct Node *node_to_destroy)
{
    node_destructor(node_to_destroy);
}

struct Node * iterate_bst(struct BinarySearchTree *tree, struct Node *cursor, void *data, int *direction)
{
    if (tree->compare(cursor->data, data) == 1) {
        if (cursor->next) {
            // Recursively test the next (right) node.
            return iterate_bst(tree, cursor->next, data, direction);
        }
        else {
            // Set the direction pointer to reflect the next position is desired (moving right).
            *direction = 1;
            return cursor;
        }
    }
    // Alternative outcome of the compare.
    else if (tree->compare(cursor->data, data) == -1) {
        // Check if there is another node in the chain to be tested.
        if (cursor->prev) {
            // Recursively test the previous (left) node.
            return iterate_bst(tree, cursor->prev, data, direction);
        }
        else {
            // Set the direction pointer to reflect the previous position is desired (moving left).
            *direction = -1;

            return cursor;
        }
    }
    // The two data values are equal.
    else {
        // Set direction.
        *direction = 0;

        return cursor;
    }
}

void recursive_tree_destruction(struct Node *node)
{
    if (node->prev) {
        recursive_tree_destruction(node->prev);
    }

    if (node->next) {
        recursive_tree_destruction(node->next);
    }

    destroy_node_bst(node);
}


void * search_bst(struct BinarySearchTree *tree, void *data)
{
    // Set the direction int pointer.
    int direction = 0;
    struct Node *idx= iterate_bst(tree, tree->head, data, &direction);

    if (direction == 0) {
        return idx->data;
    } else {
        return NULL;
    }
}

void insert_bst(struct BinarySearchTree *tree, void *data, unsigned long size)
{
    if (!tree->head) {
        tree->head = create_node_bst(data, size);
    }
    else {
        int direction = 0;
        // Find the desired position.
        struct Node *cursor = iterate_bst(tree, tree->head, data, &direction);
        // Check if the new node should be inserted to the left or right.
        if (direction == 1) {
            cursor->next = create_node_bst(data, size);
        }
        else if (direction == -1) {
            cursor->prev= create_node_bst(data, size);
        }
        // Duplicate nodes will not be added.
    }
}


int binary_search_tree_str_compare(void *data_one, void *data_two)
{
    return strcmp((char *)data_one, (char *)data_two);
}
