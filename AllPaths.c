//
// Created by surbhi on 28/05/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "basic.h"
#include "AllPaths.h"

void printAtoB(vertex* path,vertex dest){
    for(int i=1; i<= path[0]; i++){
        printf("%d ---> ",path[i]);
    }
    printf("%d\n",dest);
}

void traverseFind(Graph* g,vertex src,vertex dest, vertex* visited, vertex* path){

    vertex *currPath=(vertex*)malloc((size+1)*sizeof(vertex));
    for(int i=0; i<size+1; i++)
        currPath[i]=path[i];

    Edge *list=findList(g,src)->next_edge;
    currPath[0] += 1;
    currPath[currPath[0]]=src;

    while (list!=NULL){
        if(hasVisited(visited,list->v)==0) {
            if(list->v==dest){
                printAtoB(currPath,dest);
            }else{
                visited=insertVisited(visited,list->v);
                vertex *newPath=(vertex*)malloc((size+1)*sizeof(vertex));
                for(int i=0; i<size+1; i++)
                    newPath[i]=currPath[i];
                traverseFind(g,list->v,dest,visited,newPath);
                free(newPath);
            }
        }
        list=list->next_edge;
    }

}

void printALlPaths(Graph* g, vertex src , vertex dest){

    vertex *path=(vertex*)malloc((size+1)*sizeof(vertex));
    for(int i=0; i<size+1; i++)
        path[i]=0;
    path[0]=1;
    path[1]=src;

    printf("------------------\n");
    Edge *src_list=findList(g,src)->next_edge;
    while (src_list!=NULL){
        vertex* visited=(vertex*)malloc(size*sizeof(vertex));
        for(int i=0; i<size; i++)
            visited[i]=0;
        visited=insertVisited(visited,src);

        if(src_list->v!=dest) {
            visited = insertVisited(visited, src_list->v);
            traverseFind(g, src_list->v, dest, visited, path);
        }else{
            printAtoB(path,dest);
        }
        src_list=src_list->next_edge;
        free(visited);
    }
    printf("------------------\n");

    free(path);
}

