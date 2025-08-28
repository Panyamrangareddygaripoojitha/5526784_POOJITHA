#include <stdio.h>
#include <stdlib.h>

long arrayManipulation(int n,int q,int queries[q][3]){
    long *diff=(long*)calloc(n+2,sizeof(long));
    for(int i=0;i<q;i++){
        int a=queries[i][0];
        int b=queries[i][1];
        int k=queries[i][2];
        diff[a]+=k;
        diff[b+1]-=k;
    }
    long maxVal=0,curr=0;
    for(int i=1;i<=n;i++){
        curr+=diff[i];
        if(curr>maxVal)maxVal=curr;
    }
    free(diff);
    return maxVal;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int(*queries)[3]=malloc(sizeof(int)*3*q);
    for(int i=0;i<q;i++){
        scanf("%d %d %d",&queries[i][0],&queries[i][1],&queries[i][2]);
    }
    printf("%ld\n",arrayManipulation(n,q,queries));
    free(queries);
    return 0;
}
