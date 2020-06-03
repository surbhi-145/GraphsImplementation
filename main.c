//
// Created by surbhi on 25/05/20.
//

#include <stdio.h>
#include "basic.h"
#include "DepthFirst.h"
#include "BreadthFirst.h"
#include "TopologicalSort.h"
#include "DijkstraSPA.h"
#include "Connectivity.h"
#include "AllPairSP.h"
#include "DetectCycle.h"
#include "AllPaths.h"
#include "PrimsAlgo.h"
int main(){
    size=0;
    //int nodes[]={1,2,3,4};
    Graph *g=NULL;
    //g=initializeGraph(g,nodes);
    g=insertEdge(g,0,1,7);
    g=insertEdge(g,1,0,7);
    g=insertEdge(g,0,2,8);
    g=insertEdge(g,2,0,8);
    g=insertEdge(g,1,2,3);
    g=insertEdge(g,2,1,3);
    g=insertEdge(g,1,3,6);
    g=insertEdge(g,3,1,6);
    g=insertEdge(g,2,3,4);
    g=insertEdge(g,3,2,4);
    g=insertEdge(g,2,4,3);
    g=insertEdge(g,4,2,3);
    g=insertEdge(g,3,4,2);
    g=insertEdge(g,4,3,2);
    g=insertEdge(g,3,5,5);
    g=insertEdge(g,5,3,5);
    g=insertEdge(g,4,5,2);
    g=insertEdge(g,5,4,2);
    //printGraph(g);
    //MinSpanningTree(g);
    printALlPaths(g,0,1);
    return 0;
}