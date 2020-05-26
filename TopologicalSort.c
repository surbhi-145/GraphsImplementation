//
// Created by surbhi on 25/05/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "basic.h"
#include "TopologicalSort.h"


int findPredIndex(Pred* pred, int vertex){
    int i=0;
    int flag=0;
    while(i<size && flag==0){
        if(pred[i].vertex==vertex)
        {
            flag=1;
        }else{
            i++;
        }
    }

    return i;
}

Pred *findPred(Graph* g){
    Graph *ptr=g;
    Pred *pred=(Pred*)malloc(sizeof(Pred)*size);
    for(int i=0; i<size; i++){
        pred[i].vertex=ptr->EdgeList->v;
        pred[i].pred_count=0;
        ptr=ptr->next_src;
    }
    for(int i=0; i<size; i++){
        Edge *edgeList=g->EdgeList;
        edgeList=edgeList->next_edge;
        while (edgeList!=NULL){
            int predPos=findPredIndex(pred,edgeList->v);
            pred[predPos].pred_count+=1;
            edgeList=edgeList->next_edge;
        }

        g=g->next_src;
    }
    return pred;
}


void TopologicalSort(Graph* g){

    int flag=0;
    Pred *pred=findPred(g);
    vertex* visited=(vertex*)malloc(size*sizeof(vertex));
    for(int i=0; i<size; i++)
        visited[i]=0;

    int visited_count=0;
    do {
        int visited_count_per_cycle=0;
        for (int i = 0; i < size; i++) {
            Edge *edgeList = g->EdgeList;
            int predPos = findPredIndex(pred, edgeList->v);
            if (hasVisited(visited, edgeList->v) == 0 && pred[predPos].pred_count == 0) {
                visited = insertVisited(visited, edgeList->v);
                visited_count_per_cycle+=1;
                edgeList=edgeList->next_edge;
                while (edgeList!=NULL){
                    predPos=findPredIndex(pred,edgeList->v);
                    pred[predPos].pred_count-=1;
                    edgeList=edgeList->next_edge;
                }
            }
            g=g->next_src;
        }
        if(visited_count_per_cycle==0){
            flag=1;
        }else{
            visited_count+=visited_count_per_cycle;
        }
    }while (visited_count<size && flag==0);

    if(visited_count==size) {
        for (int i = 0; i < size; i++) {
            printf("%d ", visited[i]);
        }
    }else{
        printf("Acyclic Graph. Cannot perform Topological Sort.");
    }
    printf("\n");

}
