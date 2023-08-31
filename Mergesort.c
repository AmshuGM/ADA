#include<stdio.h>
#include<stdlib.h>

int a[10],b[10];

void merge(int low, int mid,int high){
    int i=low;
    int j=mid+1;
    int k=0;

    while (i<=mid && j<=high)
    {
        if (a[i]<a[j])  
        {
            b[k]=a[i];
            k++;i++;
        }else{
            b[k]=a[j];
            k++;j++;
        }
        
    }

    while(i<=mid){
        b[k]=a[i];
        k++;i++;
    }

    while(j<=high){
        b[k]=a[j];
        k++;j++;
    }

    for(k=0;k<(high-low+1);k++){
        a[low+k]=b[k];
    }
}

void mergesort(int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}

int main(){
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergesort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }

    return 0;
}