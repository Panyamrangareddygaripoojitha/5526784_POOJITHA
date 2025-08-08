#include <stdio.h>
void countingSort(int arr[],int n){
    int count[100]={0};
    
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=0;i<100;i++){
        printf("%d ",count[i]);
    }
    
}
int main(){
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    countingSort(arr,n);
    return 0;
}