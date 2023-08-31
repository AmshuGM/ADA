#include<stdio.h>

int mat[20][20],n,dist[20];

void dijkstra(int s){
    int visited[n];
    for(int i=0;i<n;i++) visited[i]=0;
    int c=0;
    for(int i=0;i<n;i++) dist[i]=mat[s][i];
    visited[s]=1;
    c++;

    while(c<n){
        int min=999,index=-1;
        for(int i=0;i<n;i++)
        if(visited[i]==0 && dist[i]<min){
            min=dist[i];
            index=i;
        }

        visited[index]=1;
        c++;
        for(int i=0;i<n;i++){
            if(dist[i]>dist[index]+mat[index][i])
            dist[i]=dist[index]+mat[index][i];
        }
    }
}

void main(){
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the weight matrix(-1 for disconnected nodes)\n");
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        scanf("%d",&mat[i][j]);
        if(mat[i][j]==-1)
        mat[i][j]=999;
    }
    dijkstra(0);
    printf("Node distance\n");
    for(int i=0;i<n;i++)
    printf("%d %d\n",i,dist[i]);
}