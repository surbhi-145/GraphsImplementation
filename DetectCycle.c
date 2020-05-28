//
// Created by surbhi on 28/05/20.
//

#include <stdlib.h>
#include "basic.h"
#include "DetectCycle.h"

vertex *traverse(Graph *g,Edge* ptr,vertex* visited, vertex parent ,Bool *ans){
    ptr=ptr->next_edge;
    while(ptr!=NULL && *ans==FALSE){
        if(hasVisited(visited,ptr->v)==0){
            visited=insertVisited(visited,ptr->v);
            Edge *list=findList(g,ptr->v);
            visited=traverse(g,list,visited,parent,ans);
        }else if(ptr->v==parent){
            *ans=TRUE;
        }
        ptr=ptr->next_edge;
    }
    return visited;
}

Bool isCyclic(Graph* g){

    vertex* visited=(vertex*)malloc(size*sizeof(vertex));
    for(int i=0; i<size; i++)
        visited[i]=0;

    Bool  ans=FALSE;

    for( int i=0; i<size && ans==FALSE ; i++){

        if(hasVisited(visited,g->EdgeList->v)==0){
            vertex parent=g->EdgeList->v;
            visited=insertVisited(visited,g->EdgeList->v);
            visited=traverse(g,g->EdgeList,visited,parent,&ans);
        }
        g=g->next_src;
    }

    return ans;
}
