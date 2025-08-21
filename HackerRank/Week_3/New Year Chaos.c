#include <stdio.h>
#include<stdlib.h>
void minimumBribes(int q[],int n){
    long long bribes=0;
    
    for(int i=0;i<n;i++){
        int person=q[i];
        if(person-(i+1)>2){
            printf("Too chaotic\n");
            return;
        }
        int start=person-2;
        if(start<0)start=0;
        for(int j=start;j<i;j++){
            if(q[j]>person)bribes++;
         }
    }
    printf("%lld\n",bribes);
}
int main(void){
    int t;
    if(scanf("%d",&t)!=1)return 0;
    while(t--){
        int n;
        if(scanf("%d",&n)!=1)return 0;
        
        int *q=(int*)malloc(n*sizeof(int));
        if(!q)return 0;
        for(int i=0;i<n;i++){
            scanf("%d",&q[i]);
        }
        minimumBribes(q,n);
        free(q);
    }
    return 0;
    
}