#include<stdio.h>

struct item{
    int w;
    int v;
};

int n,cap;

struct item a[20];

int knapsack(){
    int arr[cap+1][n+1];
    for(int i=0;i<=cap;i++) arr[i][0]=0;
    for(int i=0;i<=n;i++) arr[0][i]=0;

    for(int i=1;i<=cap;i++){
        for(int j=1;j<=n;j++){
            if(i>=a[j-1].w){
                arr[i][j]=a[j-1].v+arr[i-a[j-1].w][j-1]>arr[i][j-1]?a[j-1].v+arr[i-a[j-1].w][j-1]:arr[i][j-1];
            }else{
                arr[i][j]=arr[i][j-1];
            }
        }
    }
    
    return arr[cap][n];
}

void main(){
    printf("Enter number of items\n");
    scanf("%d",&n);
    printf("Enter weight and value\n");
    for(int i=0;i<n;i++)
    scanf("%d %d",&a[i].w,&a[i].v);
    printf("Enter capacity\n");
    scanf("%d",&cap);
    printf("Maximum profits are %d",knapsack());
}