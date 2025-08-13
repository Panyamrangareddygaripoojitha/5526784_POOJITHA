#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    
int *arr[n];
int sizes[n];
for(int i=0;i<n;i++){
    arr[i]=NULL;
    sizes[i]=0;
}    
int lastAnswer=0;
int answers[q];
int ansCount=0;

for(int i=0;i<q;i++){
    int type,x,y;
    scanf("%d %d %d",&type,&x,&y);
    
int idx=(x^lastAnswer)%n;

if(type==1){
    sizes[idx]++;
    arr[idx]=realloc(arr[idx],sizes[idx]*sizeof(int));
    arr[idx][sizes[idx]-1]=y;
    }
    else if(type==2){
        lastAnswer=arr[idx][y%sizes[idx]];
        answers[ansCount++]=lastAnswer;
    }   
}
for(int i=0;i<ansCount;i++){
    printf("%d\n",answers[i]);
}
for(int i=0;i<n;i++){
    free(arr[i]);
}
return 0;
}