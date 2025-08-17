#include <stdio.h>
char*balancedSums(int arr[],int n){
int totalSum =0,leftSum=0;
for(int i=0;i<n;i++){
    totalSum+=arr[i];
    }
    for(int i=0;i<n;i++){
        int rightSum=totalSum-leftSum-arr[i];
        if(leftSum==rightSum){
            return "YES";
        }
        leftSum+=arr[i];
    }
    return "NO";
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
        printf("%s\n",balancedSums(arr,n));
    }
    return 0;
}
