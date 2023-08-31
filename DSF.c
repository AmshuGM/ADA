#include<stdio.h>
#include<stdlib.h>

int visited[50];

struct graph{
    int no_nodes;
    int** adj_matrix;
};

struct graph* create(){
    struct graph* graph=(struct graph*)malloc(sizeof(struct graph));
    printf("Enter the number of nodes\n");
    scanf("%d",&graph->no_nodes);
    graph->adj_matrix=(int**)calloc(sizeof(int),graph->no_nodes);
    for(int i=0;i<graph->no_nodes;i++){
        *(graph->adj_matrix+i)=(int*)calloc(graph->no_nodes,sizeof(int));
    }
    printf("Enter graph as adjcency matrix\n");
    for(int i=0;i<graph->no_nodes;i++){
        for(int j=0;j<graph->no_nodes;j++){
            scanf("%d",*(graph->adj_matrix+i)+j);
        }
    }
    return graph;
}

void DFS(struct graph* graph,int start){
    visited[start]=1;
    printf("%d  visited\n",start);
    for(int i=0;i<graph->no_nodes;i++){
        if(visited[i]!=1 && *(*(graph->adj_matrix+start)+i)==1){
            DFS(graph,i);
        }
    }
}

void BFS(struct graph* graph){
    int node[graph->no_nodes],front=0,rear=0;
    node[rear]=0;
    do
    {
        for (int i = 0; i < graph->no_nodes; i++)
        {
            if(*(*(graph->adj_matrix+node[front])+i)==1 && visited[i]!=1){
                node[++rear]=i;
            }
        }
        visited[node[front]]=1;
        printf("%d  visited\n",node[front++]);
        
    } while (front!=rear);
    printf("%d  visited\n",node[front]);
}

int main(){
    struct graph* node=create();
    BFS(node);
    return 0;
}