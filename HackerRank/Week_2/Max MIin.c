#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int compare(const void*a,const void*b){
    return(*(int*)a-*(int*)b);
}
int maxMin(int k,int arr[],int n){
    qsort(arr,n,sizeof(int),compare); 
    int minUnfairness=INT_MAX;
    for(int i=0;i<=n-k;i++){
        int unfairness=arr[i+k-1]
-arr[i];
if(unfairness<minUnfairness){
    minUnfairness=unfairness;
}        
    }   
    return minUnfairness;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int result=maxMin(k,arr,n);
    printf("%d\n",result);
    return 0;
}
