//
// Created by surbhi on 25/05/20.
//

#include <stdio.h>
#include "basic.h"
#include "DepthFirst.h"
#include "BreadthFirst.h"
#include "TopologicalSort.h"

int size =8;

int main(){
    int nodes[]={1,2,3,4,5,6,7,8};
    Graph *g=NULL;
    g=initializeGraph(g,nodes);
    //directed
    g=insertEdge(g,1,2,0);
    g=insertEdge(g,3,1,0);
    g=insertEdge(g,2,4,0);
    g=insertEdge(g,2,5,0);
    g=insertEdge(g,4,8,0);
    g=insertEdge(g,5,8,0);
    g=insertEdge(g,8,6,0);
    g=insertEdge(g,8,7,0);
    g=insertEdge(g,7,3,0);
    g=insertEdge(g,6,3,0);
    printGraph(g);
    DepthFirstTraverse(g);
    BreadthFirstTraverse(g);
    TopologicalSort(g);
    //Undirected
    g=insertEdge(g,2,1,0);
    g=insertEdge(g,1,3,0);
    g=insertEdge(g,4,2,0);
    g=insertEdge(g,5,2,0);
    g=insertEdge(g,8,4,0);
    g=insertEdge(g,8,5,0);
    g=insertEdge(g,6,8,0);
    g=insertEdge(g,7,8,0);
    g=insertEdge(g,3,7,0);
    g=insertEdge(g,3,6,0);
    printGraph(g);
    DepthFirstTraverse(g);
    BreadthFirstTraverse(g);
    TopologicalSort(g);
    g=deleteNode(g,1);
    printGraph(g);
    return 0;
}