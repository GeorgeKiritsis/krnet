#ifndef __NODE_H__
#define __NODE_H__

struct Node{
    void *data;
    struct Node *next;
    struct Node *prev;
};

struct Node n_constructor(void *data, unsigned long size);

void node_destructor(struct Node *node);
#endif //__NODE_H__
