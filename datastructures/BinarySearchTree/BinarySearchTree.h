#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include "../Common/Node.h"

struct BinarySearchTree
{
    struct Node *head;
    
    int (*compare)(void *data_one, void *data_two);
    void *(*search)(struct BinarySearchTree *tree, void *data);
    void (*insert)(struct BinarySearchTree *tree, void *data, unsigned long size);
};

struct BinarySearchTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two));
void binary_search_tree_destructor(struct BinarySearchTree tree);

/*
int binary_search_tree_int_compare(void *data_one, void *data_two);
int binary_search_tree_float_compare(void *data_one, void *data_two);
int binary_search_tree_char_compare(void *data_one, void *data_two);
*/

//instead of the above we use a preprocessor macro

#define BST_COMPARE_FUNCTION(type, name, compare_op)                      \
int binary_search_tree_##name##_compare(void *data_one, void *data_two) { \
    type val1 = *(type *)data_one;                                        \
    type val2 = *(type *)data_two;                                        \
    if (val1 < val2) return -1;                                           \
    if (val1 > val2) return 1;                                            \
    return 0;                                                             \
}

//special case for strings
int binary_search_tree_str_compare(void *data_one, void *data_two);

#endif //__BINARY_SEARCH_TREE__
