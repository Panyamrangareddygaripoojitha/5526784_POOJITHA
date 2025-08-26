#include <stdio.h>
#include <stdlib.h>
#define LIMIT 100000

int heap[LIMIT];
int heapsize=0;

void swapint(int*x,int*y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void siftup(int pos){
    while(pos>0){
        int parent=(pos-1)/2;
        if(heap[parent]<=heap[pos])break;
        swapint(&heap[parent],&heap[pos]);
        pos=parent;
        }
}
void siftdown(int pos){
    while(1){
    int left=2*pos+1;
    int right=2*pos+2;
    int smallest=pos;
    if(left<=heapsize&&heap[left]<heap[smallest])smallest=left;
    if(right<=heapsize&&heap[right]<heap[smallest])smallest=right;
    if(smallest==pos)break;
        swapint(&heap[pos],&heap[smallest]);
        pos=smallest;
    }
}
void addelement(int value){
    heap[heapsize]=value;
    siftup(heapsize);
    heapsize++;
}
void removeelement(int value){
    for(int i=0;i<heapsize;i++){
        if(heap[i]==value){
            heap[i]=heap[heapsize-1];
            heapsize--;
            siftdown(i);
            siftup(i);
            break;     
       }
    }
}
int getmin(){
    return heap[0];
}
int main(){
    int queries;
    scanf("%d",&queries);
    for(int q=0;q<queries;q++){
        int type,num;
        scanf("%d",&type);
        if(type==1){
            scanf("%d",&num);
                addelement(num);
            }
            else if(type==2){
                scanf("%d",&num);
                removeelement(num);
            }
            else if(type==3){
                printf("%d\n",getmin());
            }
        }
        return 0;
    }
