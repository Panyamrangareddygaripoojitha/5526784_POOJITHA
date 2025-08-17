#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmpfunc(const void *a,const void*b){
    return(*(char*)a-*(char*)b);
}
int main(){
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        scanf("%d",&n);
        
        char grid[n][n+1];
        for(int i=0;i<n;i++){
            scanf("%s",grid[i]);
            qsort(grid[i],n,sizeof(char),cmpfunc);
        }
        int isSorted=1;
        for(int col=0;col<n;col++){
            for(int row=0;row<n-1;row++){
                if(grid[row][col]>grid[row+1][col]){
                    isSorted=0;
                    break;
                }
            }
                if(!isSorted)break;
            }
            if(isSorted)
            printf("YES\n");
            else
            printf("NO\n");
        }
        return 0;
    }
    