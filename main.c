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

int main(){
    size=0;
    //int nodes[]={1,2,3,4};
    Graph *g=NULL;
    //g=initializeGraph(g,nodes);
    g=insertEdge(g,1,3,50);
    g=insertEdge(g,1,2,10);
    g=insertEdge(g,1,4,5);
    g=insertEdge(g,2,4,10);
    g=insertEdge(g,4,3,10);
    g=insertEdge(g,3,4,0);
    //printGraph(g);
    printALlPaths(g,1,4);
    return 0;
}