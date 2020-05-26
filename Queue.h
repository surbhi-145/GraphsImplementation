//
// Created by surbhi on 25/05/20.
//

#ifndef GRAPHS_QUEUE_H
#define GRAPHS_QUEUE_H

typedef struct queue_tag{
    Edge *node;
    struct queue_tag *next;
}Queue;

void push(Queue** front, Queue **end, Edge* edge);
Edge *pop(Queue** front, Queue** end, Edge *ptr);
Bool isEmpty(Queue* front, Queue* end);

#endif //GRAPHS_QUEUE_H
