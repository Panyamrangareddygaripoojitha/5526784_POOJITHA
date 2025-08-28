#include <stdio.h>
#include <stdlib.h>

int compareAsc(const void*a,const void*b){
    return(*(int*)a-*(int*)b);
}
int compareDesc(const void*a,const void*b){
    return(*(int*)b-*(int*)a);
}
int countSwaps(int n,int*arr,int*target){
    int swaps=0;
    int *arrCopy=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)arrCopy[i]=arr[i];

    for(int i=0;i<n;i++){
        if(arrCopy[i]!=target[i]){
            int j;
            for(j=i;j<n;j++){
                if(arrCopy[j]==target[i])break;
            }
            int temp=arrCopy[i];
            arrCopy[i]=arrCopy[j];
            arrCopy[j]=temp;
            swaps++;
        }
    }
    free(arrCopy);
    return swaps;
}
int lilysHomework(int n,int*arr){
    int *asc=(int*)malloc(n*sizeof(int));
    int *desc=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        asc[i]=arr[i];
        desc[i]=arr[i];
    }
    qsort(asc,n,sizeof(int),compareAsc);
    qsort(desc,n,sizeof(int),compareDesc);

    int swapsAsc=countSwaps(n,arr,asc);
    int swapsDesc=countSwaps(n,arr,desc);

    free(asc);
    free(desc);

    return swapsAsc<swapsDesc?swapsAsc:swapsDesc;
}
int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);

    int result=lilysHomework(n,arr);
    printf("%d\n",result);

    free(arr);
    return 0;
}