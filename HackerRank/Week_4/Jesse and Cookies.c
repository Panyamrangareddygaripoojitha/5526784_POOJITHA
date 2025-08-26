#include <stdio.h>
#include <stdlib.h>

#define LIMIT 1000000

int heap[LIMIT];
int size = 0;

void swap(int*a,int*b){
    int t =*a;*a=*b;*b=t;
}
void siftUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<=heap[i])break;
        swap(&heap[p],&heap[i]);
        i=p;
    }
}
void siftDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<size&&heap[l]<heap[s])s=l;
        if (r<size&&heap[r]<heap[s])s=r;
        if(s==i)break;
        swap(&heap[i],&heap[s]);
        i=s;
    }
}
void insert(int v){
    heap[size]=v;
    siftUp(size);
    size++;
}
int extractMin(){
    int m=heap[0];
    heap[0]=heap[size-1];
    size--;
    siftDown(0);
    return m;
}
int cookies(int k,int arr[],int n){
    size=0;
    for(int i=0;i<n;i++)insert(arr[i]);
    int ops=0;
    while(size>0&&heap[0]<k){
        if(size<2)return-1;
        int a=extractMin();
        int b=extractMin();
        insert(a+2*b);
        ops++;
    }
    return ops;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d", &arr[i]);
    printf("%d\n",cookies(k,arr,n));
    return 0;
}
