#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "../LinkedList/LinkedList.h"

struct Queue{
    struct LinkedList ll;

    void (*push)(struct Queue *queue, void *data, unsigned long size);
    void *(*peek)(struct Queue *queue);
    void (*pop)(struct Queue *queue);
};

struct Queue queue_constructor(void);

void queue_destructor(struct Queue *queue);

void push(struct Queue *queue, void *data, unsigned long size);
void *peek(struct Queue *queue);
void pop (struct Queue *queue);

#endif //__QUEUE_H__
