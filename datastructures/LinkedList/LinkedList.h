#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "../Common/Node.h"

struct LinkedList{
    struct Node *head;
    int length;
    
    void(*insert)(struct LinkedList *linked_list, const int index, void* data, unsigned long size);
    void(*remove)(struct LinkedList *linked_list, const int index);
    void*(*access)(struct LinkedList *linked_list, const int index);

    void(*sort)(struct LinkedList *linked_list, int(*compare)(void *a, void *b));
    short(*search)(struct LinkedList *linked_list, void *query, int(*compare)(void *a, void *b));
};


struct LinkedList ll_constructor(void);
void ll_destructor(struct LinkedList *linked_list);

static struct Node *ll_create_node(void *data, unsigned long size);
void ll_destroy_node(struct Node *node_to_destroy);


struct Node *iterate_ll(struct LinkedList *linked_list, int index);

void ll_insert_node(struct LinkedList *linked_list, int index, void *data, unsigned long size);
void ll_remove_node(struct LinkedList *linked_list, int index);
void *ll_acess_node(struct LinkedList *linked_list, int index);
void ll_bubble_sort(struct LinkedList *linked_list, int (*compare)(void *a, void *b));
short ll_binary_search(struct LinkedList *linked_list, void *query, int (*compare)(void *a, void *b));

#endif  //__LINKED_LIST_H__
