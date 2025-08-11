#include <stdio.h>
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        int size=2*n,matrix[size][size];
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                scanf("%d",&matrix[i][j]);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a=matrix[i][j];
                int b=matrix[i][size-1-j];
                int c=matrix[size-1-i][j];
                int d=matrix[size-1-i][size-1-j];
                int max1=a>b?a:b;
                int max2=c>d?c:d;
                sum+=max1>max2?max1:max2;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}