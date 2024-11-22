#include "../Common/Node.h"
#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>

struct LinkedList ll_constructor(void)
{
    struct LinkedList ll = {
        .head = NULL,
        .length = 0,
        .insert = ll_insert_node,
        .remove = ll_remove_node,
        .sort = ll_bubble_sort,
        .access = ll_acess_node,
        .search = ll_binary_search 
    };

    return ll;
}

void ll_destructor(struct LinkedList* ll)
{
    for(int i = 0; i < ll->length; i++){
        ll->remove(ll, 0);
    }
}

struct Node *ll_create_node(void* data, unsigned long size)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    *new_node = n_constructor(data, size);

    return new_node;
}

struct Node *iterate_all(struct LinkedList *ll, int index)
{
    if(index < 0 || index > ll->length){
        fprintf(stderr, "[Error]: %s\n", "Index out of bounds");
        return NULL;
    }

    struct Node *idx = ll->head;
    for(int i = 0; i < index; i ++){
        idx = idx->next;
    }

    return idx;
}

void insert_ll(struct LinkedList *linked_list, int index, void *data, unsigned long size)
{
    struct Node *nti = ll_create_node(data, size);
    if (index == 0) {
        nti->next = linked_list->head;
        linked_list->head = nti;
    } else {
        struct Node *cursor = iterate_ll(linked_list, index - 1);
        nti->next = cursor->next;
        cursor->next = nti;
    }
    linked_list->length++;
}

void ll_remove_node(struct LinkedList *linked_list, int index)
{
    if (index == 0) {
        struct Node *ntr = linked_list->head;
        if (ntr) {
            linked_list->head = ntr->next;
            ll_destroy_node(ntr);
        }
    } else {
        struct Node *cursor = iterate_ll(linked_list, index - 1);
        struct Node *ntr = cursor->next;
        cursor->next = ntr->next;
        ll_destroy_node(ntr);
    }
    linked_list->length--; 
}

void *ll_acess_node(struct LinkedList *linked_list, int index)
{
    struct Node *cursor = iterate_ll(linked_list, index);
    if (cursor) {
        return cursor->data;
    } else {
        return NULL;
    }
}

void ll_bubble_sort(struct LinkedList *linked_list, int (*compare)(void *a, void *b))
{
    for (struct Node *i = linked_list->access(linked_list, 0); i; i = i->next)
    {
        for (struct Node *n = i->next; n; n = n->next) {
            if (compare(i->data, n->data) > 0) {
               // Swap them.
                void *temporary = n->data;
                n->data = i->data;
                i->data = temporary;
            }
        }
    }
}

short ll_binary_search(struct LinkedList *linked_list, void *query, int (*compare)(void *a, void *b))
{
    int position = linked_list->length/2;
    int min_checked = 0;
    int max_checked = linked_list->length;
    while (max_checked > min_checked)
    {
        void *data = linked_list->access(linked_list, position);
        if (compare(data, query) == 1) {
            max_checked = position;
            if (position != (min_checked + position) / 2) {
                position = (min_checked + position) / 2;
            } else {
                break;
            }
        }
        else if (compare(data, query) == -1) {
            min_checked = position;
            if (position != (max_checked + position) / 2) {
                position = (max_checked + position) / 2;
            }
            else {
                break;
            }
        }
        else {
            return 1;
        }
    }
    return 0;
}
