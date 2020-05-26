//
// Created by surbhi on 25/05/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "basic.h"
#include "Queue.h"

static int size=8;

vertex *traverseBreadth(Graph *g,Edge* edgeList, vertex* visited){
    Queue *front=NULL;
    Queue *end=NULL;
    push(&front,&end,edgeList);
    while (isEmpty(front,end)==0){
        edgeList=pop(&front,&end,edgeList);
        if(hasVisited(visited,edgeList->v)==0) {

            visited = insertVisited(visited, edgeList->v);
            edgeList = edgeList->next_edge;
            while (edgeList != NULL) {
                push(&front, &end,findList(g,edgeList->v));
                edgeList=edgeList->next_edge;
            }
        }
    }
    return visited;
}

void BreadthFirstTraverse(Graph* g){

    vertex* visited=(vertex*)malloc(size*sizeof(vertex));
    for(int i=0; i<size; i++)
        visited[i]=0;

   for(int i=0; i<size; i++){
       if(hasVisited(visited,g->EdgeList->v)==0) {
           Edge *edge = g->EdgeList;
           visited = traverseBreadth(g,edge, visited);
       }
       g=g->next_src;
   }

    for(int i=0; i<size; i++){
        printf("%d ",visited[i]);
    }
    printf("\n");

}