#include<stdio.h>
#include<limits.h>

int arr[50][50],c[50][50],n;

void floyds(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][k]!=INT_MAX && arr[k][j]!=INT_MAX)
                arr[i][j]= arr[i][j]<arr[i][k]+arr[k][j]? arr[i][j] : arr[i][k]+arr[k][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==INT_MAX)
            printf("INF ");
            else
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void main(){
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    printf("Enter weight matrix(-1 for disjoint nodes)\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        scanf("%d",&c[i][j]);
        if(c[i][j]==-1){
            c[i][j]=INT_MAX;
        }
        arr[i][j]=c[i][j];
        }
    }
     
    printf("Shortest paths:\n");
    floyds();
}
