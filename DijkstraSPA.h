//
// Created by surbhi on 26/05/20.
//

#ifndef GRAPHS_DIJKSTRASPA_H
#define GRAPHS_DIJKSTRASPA_H

typedef struct {
    vertex dest;
    int found;
    int distance;
    vertex prev_node;
}VertexInfo;

void dijkstra(Graph* g,vertex v);

#endif //GRAPHS_DIJKSTRASPA_H
