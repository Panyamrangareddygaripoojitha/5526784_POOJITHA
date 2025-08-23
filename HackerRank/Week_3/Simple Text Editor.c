#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEXT 1000000
typedef struct{
    int opType;
    char*data;
}History;

static inline char*my_strdup(const char*s){
    size_t len=strlen(s);
    char*p=(char*)malloc(len+1);
    if(!p) exit(1);
    memcpy(p,s,len+1);
    return p;
}


int main(void){
    int Q;
    if(scanf("%d",&Q)!=1)return 0;
    History*history=(History*)malloc((size_t)Q*sizeof(History));
    int top=-1;
    
    char*text=(char*)malloc((size_t)MAX_TEXT+1);
    char*buf=(char*)malloc((size_t)MAX_TEXT+1);
    if(!history||!text||!buf)return 0;
    size_t len=0;
    text[0]='\0';
    
    for(int i=0;i<Q;i++){
        int command;
        scanf("%d",&command);
        
        if(command==1){
            scanf("%s",buf);
            size_t wlen=strlen(buf);
            memcpy(text+len,buf,wlen);
            len+=wlen;
            text[len]='\0';
            top++;
            history[top].opType=1;
            history[top].data=my_strdup(buf);
        }
        else if(command==2){
            int k;
            scanf("%d",&k);
            size_t kk=(size_t)k;
            size_t start=len-kk;
            
            char*removed=(char*)malloc(kk+1);
            if(!removed)return 0;
            memcpy(removed,text+start,kk);
            removed[kk]='\0';
            len-=kk;
            text[len]='\0';
            top++;
            history[top].opType=2;
            history[top].data=removed;
        }
        else if(command==3){
            int k;
            scanf("%d",&k);
            printf("%c\n",text[(size_t)k-1]);
        }
        else if(command==4){
            History last=history[top--];
            if(last.opType==1){
                size_t rlen=strlen(last.data);
                len-=rlen;
                text[len]='\0';
                free(last.data);
                }
                else{
                size_t rlen=strlen(last.data);
                memcpy(text+len,last.data,rlen);
                len+=rlen;
                text[len]='\0';
                free(last.data);
                }
                 }
    }
    while(top>=0)free(history[top--].data);
    free(history);
    free(buf);
    free(text);
    return 0;
}
