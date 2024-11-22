#include "Node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node n_constructor(void *data, unsigned long size)
{
    struct Node node={
        .data = malloc(size),
        .next = NULL,
        .prev = NULL
    };

    memcpy(node.data, data, size);

    return node;
}

void node_destructor(struct Node *node)
{
    free(node->data);
    free(node);
}
