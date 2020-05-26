//
// Created by surbhi on 24/05/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "basic.h"
#include "DepthFirst.h"


vertex *traverseDepth(Graph *g,Edge* ptr,vertex* visited){
    ptr=ptr->next_edge;
    while(ptr!=NULL){
        if(hasVisited(visited,ptr->v)==0){
            visited=insertVisited(visited,ptr->v);
            Edge *list=findList(g,ptr->v);
            visited=traverseDepth(g,list,visited);
        }
        ptr=ptr->next_edge;
    }
    return visited;
}

void DepthFirstTraverse(Graph* g){

    vertex* visited=(vertex*)malloc(size*sizeof(vertex));
    for(int i=0; i<size; i++)
        visited[i]=0;

    for(int j=0; j<size; j++){

        if(hasVisited(visited,g->EdgeList->v)==0){
            visited=insertVisited(visited,g->EdgeList->v);
            visited=traverseDepth(g,g->EdgeList,visited);
        }
        g=g->next_src;
    }

    for(int i=0; i<size; i++){
        printf("%d ",visited[i]);
    }
    printf("\n");
}