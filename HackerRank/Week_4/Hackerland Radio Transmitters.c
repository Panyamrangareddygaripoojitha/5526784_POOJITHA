#include <stdio.h>
#include <stdlib.h>
int compare(const void*a, const void*b){
    return(*(int*)a-*(int*)b);
}
int hackerlandradiotransmitters(int houses[],int n,int k){
    qsort(houses,n,sizeof(int),compare);
    int count=0,i=0;
    while(i<n){
        count++;
        int loc=houses[i]+k;
        while(i<n&&houses[i]<=loc)i++;
        int transmitter=houses[i - 1];
        loc=transmitter+k;
        while (i<n&&houses[i]<=loc)i++;
    }
    return count;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int houses[n];
    for (int i=0;i<n;i++){
        scanf("%d",&houses[i]);
    }
    printf("%d\n",hackerlandradiotransmitters(houses,n,k));
    return 0;
}
