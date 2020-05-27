//
// Created by surbhi on 17/05/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "basic.h"

int size=4;

Edge *createNode(int vertex,int weight){
    Edge *newEdge=(Edge*)malloc(sizeof(Edge));
    newEdge->next_edge=NULL;
    newEdge->v=vertex;
    newEdge->weight=weight;

    return newEdge;
}

Graph *initializeGraph(Graph* g, int *nodes){

    g=(Graph*)malloc(sizeof(Graph));
    g->next_src=NULL;
    g->EdgeList=createNode(nodes[0],0);
    Graph *ptr=g;
    for(int i=1; i<size; i++) {
        ptr->next_src=(Graph*)malloc(sizeof(Graph));
        ptr->next_src->EdgeList=createNode(nodes[i],0);
        ptr=ptr->next_src;
    }
    return g;
}

Edge* findList(Graph *g,int v){
    Edge *ret_val=NULL;
    int flag=0;
    while (g!=NULL && flag==0){
        if(g->EdgeList->v==v){
            flag=1;
            ret_val=g->EdgeList;
        }else{
            g=g->next_src;
        }
    }
    return ret_val;
}

Graph *insertNode(Graph *g,int vertex, int weight){
    size+=1;
    Graph *ptr=g;
    Edge* tmp=findList(g,vertex);
    if(tmp==NULL) {
        if (ptr == NULL) {
            g=(Graph*)malloc(sizeof(Graph));
            g->next_src=NULL;
            g->EdgeList=createNode(vertex,weight);
        } else {
            while (ptr->next_src!=NULL)
                ptr=ptr->next_src;
            ptr->next_src=(Graph*)malloc(sizeof(Graph));
            ptr=ptr->next_src;
            ptr->next_src=NULL;
            ptr->EdgeList=createNode(vertex,weight);
        }
    }
    return g;
}

Graph *insertEdge(Graph *g,int src, int dest,int dest_weight){

    Edge *ptr=findList(g,src);
    if(ptr==NULL)
    {
        g=insertNode(g,src,0);
        ptr=findList(g,src);
    }
    while(ptr->next_edge!=NULL){
        ptr=ptr->next_edge;
    }
    ptr->next_edge=createNode(dest,dest_weight);
    ptr=findList(g,dest);
    if(ptr==NULL){
        g=insertNode(g,dest,0);
    }
    return g;
}

Graph *deleteEdge(Graph* g, int src, int dest){

    Edge *ptr=findList(g,src);
    Edge* prev=ptr;
    Edge *toDeleteNode=NULL;
    ptr=ptr->next_edge;
    int flag=0;
    while(flag==0 && ptr!=NULL)
    {
        if(ptr->v==dest){
            toDeleteNode=ptr;
            prev->next_edge=ptr->next_edge;
            flag=1;
            free(toDeleteNode);
        } else{
            prev=ptr;
            ptr=ptr->next_edge;
        }
    }

    return g;
}

Edge *freeList(Edge* ptr){

    Edge *ret_val=NULL;
    if(ptr!=NULL){
        ret_val=freeList(ptr->next_edge);
        free(ptr);
    }
    return ret_val;
}

Graph *deleteNode(Graph* g, int vertex){

    if(size==1){
        g->EdgeList=freeList(g->EdgeList);
        Graph *tmp=g;
        g=NULL;
        free(tmp);
    }
    else{
        Graph *prev=NULL;
        Graph *ptr=g;
        while (ptr!=NULL){
            if(ptr->EdgeList->v==vertex) {
                if(prev==NULL){
                    g=ptr->next_src;
                }else{
                    prev->next_src=ptr->next_src;
                }
                ptr->EdgeList=freeList(ptr->EdgeList);
                ptr=ptr->next_src;

            }else{
                Edge* prev_dest=ptr->EdgeList;
                Edge* curr_dest=prev_dest->next_edge;
                int flag=0;
                while (curr_dest!=NULL && flag==0) {
                    if (curr_dest->v == vertex) {
                        flag = 1;
                        Edge *toFree = curr_dest;
                        prev_dest->next_edge = curr_dest->next_edge;
                        free(toFree);
                    } else{
                        prev_dest=curr_dest;
                        curr_dest=curr_dest->next_edge;
                    }
                }
                prev=ptr;
                ptr=ptr->next_src;
            }
        }
    }
    size-=1;
    return g;
}

Bool hasVisited(vertex *visited,vertex v){
    Bool ans=0;
    int j=0;
    while(j<size && ans==0){
        if(visited[j]==v) {
            ans = 1;
        }
        j+=1;
    }
    return ans;
}

vertex *insertVisited(vertex* visited, vertex v){
    for(int j=0; j<size; j++){
        if(visited[j]==0){
            visited[j]=v;
            break;
        }
    }
    return visited;
}

void printGraph(Graph* g){

    printf("--------------------------\n");

    for(int i=0; i<size; i++){
        vertex src=g->EdgeList->v;
        Edge *ptr=g->EdgeList;
        if(ptr->next_edge!=NULL){
            ptr=ptr->next_edge;
            while(ptr!=NULL){
                printf("(%d-- %d ->%d) ",src,ptr->weight,ptr->v);
                ptr=ptr->next_edge;
            }
            printf("\n");
        }
        g=g->next_src;
    }

    printf("--------------------------\n");
}
