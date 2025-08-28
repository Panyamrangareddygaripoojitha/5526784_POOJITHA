#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int*data;
    int front,back;
}Deque;

Deque*createDeque(int n){
    Deque*dq=(Deque*)malloc(sizeof(Deque));
    dq->data=(int*)malloc(sizeof(int)*n);
    dq->front=dq->back=0;
    return dq;
}
int isEmpty(Deque*dq){
    return dq->front==dq->back;
}
void pushBack(Deque*dq,int val){
    dq->data[dq->back++]=val;
}
void popBack(Deque*dq){
    dq->back--;
}
void popFront(Deque*dq){
    dq->front++;
}
int front(Deque*dq){
    return dq->data[dq->front];
}
int back(Deque*dq){
    return dq->data[dq->back-1];
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);

    int *arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);

    int *queries=(int*)malloc(sizeof(int)*q);
    for(int i=0;i<q;i++)scanf("%d",&queries[i]);
    for(int qi=0;qi<q;qi++){
        int k=queries[qi];
        Deque*dq=createDeque(n);
        int minOfMax=INT_MAX;

        for(int i=0;i<n;i++){
            while(!isEmpty(dq)&&arr[back(dq)]<=arr[i])popBack(dq);
            pushBack(dq,i);
            if(front(dq)<=i-k)popFront(dq);
            if(i>=k-1){
                int windowMax=arr[front(dq)];
                if(windowMax<minOfMax)minOfMax=windowMax;
            }
        }
        printf("%d\n",minOfMax);
        free(dq->data);
        free(dq);
    }
    free(arr);
    free(queries);
    return 0;
}
