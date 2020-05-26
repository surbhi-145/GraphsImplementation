//
// Created by surbhi on 24/05/20.
//

#ifndef GRAPHS_BASIC_H
#define GRAPHS_BASIC_H

typedef enum{FALSE, TRUE}Bool;

typedef int vertex;

typedef struct edge_tag{
    vertex v;
    struct edge_tag *next_edge;
    int weight;
}Edge;

typedef struct graph{
    Edge* EdgeList;
    struct graph* next_src;
}Graph;


Edge *createNode(int vertex, int weight);
Graph *initializeGraph(Graph* g, int *nodes);
Edge* findList(Graph *g,int v);
Graph *insertEdge(Graph *g,int src, int dest,int dest_weight);
Bool hasVisited(vertex *visited,vertex v);
void printGraph(Graph* g);
Graph *deleteEdge(Graph* g, int src, int dest);
Graph *insertNode(Graph *g,int vertex,int weight);
Graph *deleteNode(Graph* g, int vertex);
vertex *insertVisited(vertex* visited, vertex v);

#endif //GRAPHS_BASIC_H
