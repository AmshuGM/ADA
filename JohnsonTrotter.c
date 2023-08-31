#include<stdio.h>
#include<stdlib.h>

int val[10],dir[10],n;

int mobile(){
    int mobp=-1,mob=0;

    for (int i = 0; i < n; i++)
    {
        if(i!=0 && dir[i]==1 && val[i]>val[i-1] && val[i]>mob){
            
            mob=val[i];
            mobp=i;
        }else if(i!=n-1 && dir[i]==-1 && val[i]>val[i+1] && val[i]>mob){
           
            mob=val[i];
            mobp=i;
        }
    }

    return mobp;
}

int main(){

    printf("Enter number of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        val[i]=i+1;
        dir[i]=1;
    }

    while(1){
        
        for(int i=0;i<n;i++){
            printf("%d",val[i]);
        }
        printf("\n");

        int mobp=mobile();
        if(mobp==-1){
            break;
        }
        int mob=val[mobp];
        if (dir[mobp]==1)
        {
           int temp=val[mobp-1];
           val[mobp-1]=val[mobp];
           val[mobp]=temp;

           temp=dir[mobp];
           dir[mobp]=dir[mobp-1];
           dir[mobp-1]=temp;
        }else{
           int temp=val[mobp+1];
           val[mobp+1]=val[mobp];
           val[mobp]=temp;

           temp=dir[mobp];
           dir[mobp]=dir[mobp+1];
           dir[mobp+1]=temp;
        }
        
        for(int i=0;i<n;i++){
            if(mob<val[i]){
                dir[i]=-dir[i];
            }
        }
    }
    
    return 0;
}