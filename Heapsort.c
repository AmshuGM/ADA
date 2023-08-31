#include<stdio.h>

int a[50],n;

void heapify(int root,int end){
    int largest=root;
    int left=2*root+1;
    int right=2*root+2;

    if(left<end && a[left]>a[largest])
    largest=left;

    if(right<end && a[right]>a[largest] )
    largest=right;

    if(largest!=root){
        int temp=a[largest];
        a[largest]=a[root];
        a[root]=temp;
        heapify(largest,end);
    }
}

void heapsort(){
    for(int i=n/2-1;i>=0;i--)
    heapify(i,n-1);

    for(int i=n-1;i>=0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
    heapify(0,i);
    }
}

void main(){
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    heapsort();
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}