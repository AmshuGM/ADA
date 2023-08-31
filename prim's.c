#include<stdio.h>
int cost[10][10],n;

void prims(){
    int visited[n],key[n],parent[n];
    for(int i=0;i<n;i++)
    visited[i]=0,key[i]=9999;

    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;i++){
        int v;
        for(int j=0,min=9999;j<n;j++){
            if(!visited[j] && key[j]<min)
            min=key[j],v=j;
        }
        visited[v]=1;

        for(int j=0;j<n;j++){
            if(!visited[j] && cost[v][j]<key[j])
            key[j]=cost[v][j],parent[j]=v;
        }

    }

    printf("MST\n");
    int c=0;
    for(int j=1;j<n;j++){
        printf("%d -> %d\n",j,parent[j]);
        c+=cost[j][parent[j]];
    }
    printf("Cost %d",c);
}

void main(){
printf("ENter the number of nodes\n");
scanf("%d",&n);
printf("Enter weight matrix(-1 for disjoint nodes)\n");
for(int i=0;i<n;i++)
for(int j=0;j<n;j++){
    scanf("%d",&cost[i][j]);
    if(cost[i][j]==-1)
    cost[i][j]=9999;
}
prims();
}