#include <stdio.h>
int makeUnique(int arr[],int n,int unique[]){
    int k=0;
    unique[k++]=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            unique[k++]=arr[i];
        }
    }
    return k;
}
int main(){
    int n,m;
    scanf("%d",&n);
    int scores[n];
    for(int i=0;i<n;i++){
        scanf("%d",&scores[i]);
    }
    scanf("%d",&m);
    int player[m];
    for(int i=0;i<m;i++){
        scanf("%d",&player[i]);
    }
    int unique[n];
    int ucount=makeUnique(scores,n,unique);
    int pos=ucount-1;
    for(int i=0;i<m;i++){
        while(pos>=0&&player[i]>=unique[pos]){
            pos--;
        }
        printf("%d\n",pos+2);
    }
    return 0;
 }