//
// Created by surbhi on 27/05/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "basic.h"
#include "Connectivity.h"

Graph *reverseEdges(Graph* g){
    Graph *newG=(Graph*)malloc(sizeof(Graph));
    Graph *ptr1=g,*ptr2=newG;
    ptr2->EdgeList=createNode(ptr1->EdgeList->v,0);
    ptr2->next_src=NULL;

    while (ptr1->next_src!=NULL){
        ptr2->next_src=(Graph*)malloc(sizeof(Graph));
        ptr2->next_src->EdgeList=createNode(ptr1->next_src->EdgeList->v,0);
        ptr2=ptr2->next_src;
        ptr1=ptr1->next_src;
    }

    ptr1=g;
    ptr2=newG;
    for(int i=0; i<size; i++){
        int vertex=ptr1->EdgeList->v;
        Edge *list=ptr1->EdgeList->next_edge;
        while (list!=NULL){
            Edge *insertList=findList(newG,list->v);
            while(insertList->next_edge!=NULL) {
                insertList = insertList->next_edge;
            }
            insertList->next_edge=createNode(vertex,list->weight);
            list=list->next_edge;
        }
        ptr1=ptr1->next_src;
    }

    return newG;
}

Bool isConnected(Graph* g){
    Bool ans=TRUE;

    Graph *newG=reverseEdges(g);

    for(int i=0; i<size && ans==TRUE; i++){
        if(g->EdgeList->next_edge==NULL && newG->EdgeList->next_edge==NULL){
            ans=FALSE;
        } else{
            g=g->next_src;
            newG=newG->next_src;
        }
    }

    return ans;
}