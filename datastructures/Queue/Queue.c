#include "../LinkedList/LinkedList.h"
#include "Queue.h"

struct Queue queue_constructor()
{
    struct Queue queue = {
        .ll = ll_constructor(),
        .push = push,
        .peek = peek,
        .pop = pop
    };

    return queue;
}

void queue_destructor(struct Queue *queue)
{
    ll_destructor(&queue->ll);
}

void push(struct Queue *queue, void *data, unsigned long size)
{
    queue->ll.insert(&queue->ll, queue->ll.length, data, size);
}

// The peek function returns the data from the first item in the queue-.
void * peek(struct Queue *queue)
{
    void *data = queue->ll.access(&queue->ll, 0);
    return data;
}

void pop(struct Queue *queue)
{
    queue->ll.remove(&queue->ll, 0);
}
