//
// Created by surbhi on 26/05/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "basic.h"
#include "DijkshatraSPA.h"

static int size=8;

int getMinIndex(VertexInfo* vertList){
    int min=INT_MAX;
    int min_index=-1;
    for(int i=0; i<size; i++){
        if(vertList[i].distance<min && vertList[i].found==0){
            min=vertList[i].distance;
            min_index=i;
        }
    }
    return min_index;
}

int findIndex(VertexInfo* vertList, int vertex){
    int i=0;
    int flag=0;
    while(i<size && flag==0){
        if(vertList[i].dest==vertex)
        {
            flag=1;
        }else{
            i++;
        }
    }

    return i;
}

void dijkshatra(Graph* g,vertex v){

    Graph *ptr=g;
    VertexInfo *vertList=(VertexInfo*)malloc(size*(sizeof(VertexInfo)));

    for(int i=0; i<size; i++){
        vertList[i].dest=ptr->EdgeList->v;
        if(ptr->EdgeList->v==v){
            vertList[i].distance=0;
            vertList[i].found=0;
        }else{
            vertList[i].found=0;
            vertList[i].distance=INT_MAX;
        }
        ptr=ptr->next_src;
    }

    int found_count=0;
    while(found_count<size) {
        int index=getMinIndex(vertList);
        found_count+=1;
        vertList[index].prev_node=v;
        v=vertList[index].dest;
        vertList[index].found=1;
        Edge *edgeList=findList(g,v);
        edgeList=edgeList->next_edge;
        while (edgeList!=NULL){
            int i=findIndex(vertList,edgeList->v);
            if(vertList[i].found==0) {
                int distance = vertList[index].distance + edgeList->weight;
                if (distance < vertList[i].distance) {
                    vertList[i].distance = distance;
                }
            }
            edgeList=edgeList->next_edge;
        }
    }
}