#include<stdio.h>

int board[10][10],n;

int safe(int row,int col){
    for(int i=0;i<n;i++){
        if(board[i][col])
        return 0;
    }

    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    if(board[i][j])
    return 0;

    for(int i=row,j=col;i>=0 && j>=0;i--,j++)
    if(board[i][j])
    return 0;

    return 1;
}

void solve(int row){
    if(row==n){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        printf("%d ",board[i][j]);
        }
        printf("\n");
        }
    }

    for(int i=0;i<n;i++){
        if(safe(row,i)){
            board[row][i]=1;
            solve(row+1);
            board[row][i]=0;
        }
    }
}

void main(){
    printf("Enter number of queens\n");
    scanf("%d",&n);
    solve(0);
}