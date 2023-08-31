#include<stdio.h>

int n,mat[20][20],visited[20],mincost=0;

struct minedge{
int i;
int j;
int w;
};
struct minedge e[10];

void kruskal(){
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mat[i][j]!=999){
                e[k].i=i;
                e[k].j=j;
                e[k++].w=mat[i][j];
            }
        }
    }

    for(int i=0;i<k;i++){
        for(int j=0;j<k-1;j++){
            if(e[j].w>e[j+1].w){
                struct minedge temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++) visited[i]=0;
    
    for(int i=0;i<k;i++){
        if(visited[e[i].i]==0 || visited[e[i].j]==0){
            visited[e[i].i]=1;
            visited[e[i].j]=1;
            mincost+=e[i].w;
            printf("%d->%d\n",e[i].i,e[i].j);
        }
    }
    printf("Minmum cost %d",mincost);
}

void main(){
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    printf("Enter weight matrix(0 for disjoint nodes)\n");
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        scanf("%d",&mat[i][j]);
        if(mat[i][j]==0)
        mat[i][j]=999;
    }
    kruskal();
}