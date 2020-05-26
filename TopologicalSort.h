//
// Created by surbhi on 25/05/20.
//

#ifndef GRAPHS_TOPOLOGICALSORT_H
#define GRAPHS_TOPOLOGICALSORT_H

typedef struct{
    int vertex;
    int pred_count;
}Pred;

void TopologicalSort(Graph* g);

#endif //GRAPHS_TOPOLOGICALSORT_H
