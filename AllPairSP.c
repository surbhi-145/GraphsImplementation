//
// Created by surbhi on 27/05/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "basic.h"
#include "AllPairSP.h"

vertex *initializeMap(Graph* g){
    vertex*map=(vertex*)malloc(size*sizeof(vertex));
    for(int i=0; i<size; i++){
        map[i]=g->EdgeList->v;
        g=g->next_src;
    }

    return map;
}

int getIndexFromVertex(vertex* map, vertex v){
    int i=0;
    int ans=-1;
    while(i<size && ans==-1){
        if(map[i]==v){
            ans=i;
        }else{
            i++;
        }
    }
    return ans;
}

vertex getVertexFromIndex(vertex* map, int index){
    return map[index];
}

void initializeCost(Graph* g, int cost[size][size],vertex* map){

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cost[i][j]=INT_MAX;
        }
    }

    int i=0;
    while(g!=NULL){
        Edge *edgeList=g->EdgeList->next_edge;
        while (edgeList!=NULL){
            int j=getIndexFromVertex(map,edgeList->v);
            cost[i][j]=edgeList->weight;
            edgeList=edgeList->next_edge;
        }
        g=g->next_src;
        i++;
    }
}

void initializePrevNode(vertex prevNode[size][size],vertex* map){
    for(int i=0; i<size; i++){
        int prev=getVertexFromIndex(map,i);
        for (int j=0; j<size; j++){
            prevNode[i][j]=prev;
        }
    }
}

void printPathX(vertex* map, int j, vertex* prevNodes){

    int dest=getVertexFromIndex(map,j);
    if(dest==prevNodes[j]){
        printf("%d---> ",dest);
    }else{
        printPathX(map,getIndexFromVertex(map,prevNodes[j]),prevNodes);
        printf("%d---> ",dest);
    }
}

void printShortestPath(int cost[size][size], vertex prevNode[size][size], vertex* map){

    for(int i=0; i<size; i++){
        printf("-----------------------------\n");
        for(int j=0; j<size; j++){
            if(i!=j){
                printf("%d to %d : ", getVertexFromIndex(map,i),getVertexFromIndex(map,j));
                if(cost[i][j]==INT_MAX){
                    printf("No Path exists.\n");
                } else{
                    printPathX(map,getIndexFromVertex(map,prevNode[i][j]),prevNode[i]);
                    printf("%d Cost :%d\n",getVertexFromIndex(map,j),cost[i][j]);
                }
            }
        }

    }

}

void printCost(int cost[size][size]){
    for(int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
}

void AllPairShortestPath(Graph* g) {

    vertex *map = initializeMap(g);
    int cost[size][size];
    initializeCost(g, cost, map);
    vertex prevNode[size][size];
    initializePrevNode(prevNode, map);

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(cost[i][k]!=INT_MAX && cost[k][j]!=INT_MAX) {
                    if (cost[i][k] + cost[k][j] < cost[i][j]) {
                        cost[i][j] = cost[i][k] + cost[k][j];
                        prevNode[i][j] = getVertexFromIndex(map, k);
                    }
                }
            }
        }
    }
    //printCost(prevNode);
   printShortestPath(cost,prevNode,map);
    //printPathX(map,1,prevNode[0]);
}