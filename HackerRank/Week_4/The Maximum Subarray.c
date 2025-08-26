#include<stdio.h>
int max(int a,int b){
    return(a>b)?a:b;
} 
void maxSubarray(int arr[],int n,int *subArrAns,int*subseqAns){
    int bestsofar=arr[0];
    int current=arr[0];
    for(int i=1;i<n;i++){
        current=max(arr[i],current+arr[i]);
        bestsofar=max(bestsofar,current);
    }
    *subArrAns=bestsofar;

     int subseqsum=0;
     int largest=arr[0];
     for(int i=0;i<n;i++){
        if (arr[i]>0)subseqsum+=arr[i];
        if(arr[i]>largest)largest=arr[i];
     }
     *subseqAns=(subseqsum>0)?subseqsum:largest;
}
int main(){
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        scanf("%d",&n);
        
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
    }
    int subArrAns,subseqAns;
    maxSubarray(arr,n,&subArrAns,&subseqAns);
    
    printf("%d %d\n",subArrAns,subseqAns);
    }
    return 0;
}