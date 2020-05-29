//
// Created by surbhi on 29/05/20.
//

#ifndef GRAPHS_PRIMSALGO_H
#define GRAPHS_PRIMSALGO_H

typedef struct {
    int parent;
    int child;
    int cost;
}MST;

void MinSpanningTree(Graph* g);

#endif //GRAPHS_PRIMSALGO_H
