#include <stdio.h>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    char strings[1000][1001];
    for(int i=0;i<n;i++){
        scanf("%s",strings[i]);
    }
    int q;
    scanf("%d",&q);
    char queries[1000][1001];
    for(int i=0;i<q;i++){
        scanf("%s",queries[i]);
    }
    for(int i=0;i<q;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(strcmp(queries[i],strings[j])==0){
                count++;
                }
     }
     printf("%d\n",count); 
                   }
                   return 0;
}