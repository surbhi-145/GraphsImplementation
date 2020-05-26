//
// Created by surbhi on 25/05/20.
//

#include <stdlib.h>
#include "basic.h"
#include "Queue.h"

Queue *makeNode(Edge* edge){
    Queue *newNode=(Queue*)malloc(sizeof(Queue));
    newNode->node=edge;
    newNode->next=NULL;
    return newNode;

}

void push(Queue** front, Queue **end, Edge* edge){
    if(*front==NULL && *end==NULL){
        *front=*end=makeNode(edge);
    }else if(*front== *end){
        *front=makeNode(edge);
        (*end)->next=*front;
    } else{
        (*front)->next=makeNode(edge);
        *(front)=(*front)->next;
    }
}

Edge *pop(Queue** front, Queue** end, Edge *ptr){
    ptr=(*end)->node;
    Queue* toFree=*end;
    if(*front == *end){
        *front=*end=NULL;
    }else{
        *end=(*end)->next;
    }
    free(toFree);
    return ptr;
}

Bool isEmpty(Queue* front, Queue* end){
    Bool ret_val=FALSE;
    if(front==NULL && end==NULL)
        ret_val=TRUE;
    return ret_val;
}