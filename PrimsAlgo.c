//
// Created by surbhi on 29/05/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "basic.h"
#include "Connectivity.h"
#include "PrimsAlgo.h"

int edge_count=0;
int vertex_count=1;

void printMST(MST* tree){

    int cost=0;
    printf("-------------------------\n");
    printf("Src\tDest\tCost\n");
    for(int i=0; i<edge_count; i++){
        printf("%d\t%d\t%d\n",tree[i].parent,tree[i].child,tree[i].cost);
        cost+=tree[i].cost;
    }
    printf("Total Cost: %d \n",cost);
    printf("-------------------------\n");
}

vertex* findMin(vertex* visited, MST* tree, Graph* g){

    MST min;
    min.cost=INT_MAX;
    for(int i=0; i<vertex_count; i++){
        Edge *edgeList=findList(g,visited[i]);
        edgeList=edgeList->next_edge;
        while (edgeList!=NULL){
            if(hasVisited(visited,edgeList->v)==0 && edgeList->weight<min.cost){
                min.parent=visited[i];
                min.cost=edgeList->weight;
                min.child=edgeList->v;
            }
            edgeList=edgeList->next_edge;
        }
    }

    if(min.cost!=INT_MAX){
        tree[edge_count]=min;
        edge_count+=1;
        visited=insertVisited(visited,min.child);
        vertex_count+=1;
    }
    return visited;
}

void MinSpanningTree(Graph* g){
    if(isConnected(g)==TRUE) {
        MST tree[size-1];
        vertex *visited = (vertex *) malloc(size * sizeof(vertex));
        for (int i = 0; i < size; i++)
            visited[i] = 0;
        visited=insertVisited(visited,g->EdgeList->v);

        for(int i=0; i<size; i++){
            visited=findMin(visited,tree,g);
        }

        if(edge_count!=size-1){
            printf("No Minimum Spanning Tree exists\n");
        }else{
            printMST(tree);
        }

    }else{
        printf("Disconnected Graph. No min spanning Tree\n");
    }
}
