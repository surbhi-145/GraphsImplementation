//
// Created by surbhi on 25/05/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "basic.h"
#include "Queue.h"

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

vertex *traverseBreadthSearch(Graph *g,Edge* ptr,vertex* visited, Bool* ans,vertex v){
    ptr=ptr->next_edge;
    while(ptr!=NULL){
        if(hasVisited(visited,ptr->v)==0){
            if(ptr->v==v){
                *ans=TRUE;
            }else {
                visited = insertVisited(visited, ptr->v);
                Edge *list = findList(g, ptr->v);
                visited = traverseBreadthSearch(g, list, visited, ans,v);
            }
        }
        ptr=ptr->next_edge;
    }
    return visited;
}

Bool BreadthFirstSearch(Graph*g , vertex v){

    Bool ans = FALSE;

    vertex *visited = (vertex *) malloc(size * sizeof(vertex));
    for (int i = 0; i < size; i++)
        visited[i] = 0;

    for (int j = 0; j < size && ans == FALSE; j++) {

        if (hasVisited(visited, g->EdgeList->v) == 0) {
            if (g->EdgeList->v == v)
                ans = TRUE;
            else {
                visited = insertVisited(visited, g->EdgeList->v);
                visited = traverseBreadthSearch(g, g->EdgeList, visited, &ans,v);
            }
        }
        g = g->next_src;
    }

    free(visited);
    return ans;
}