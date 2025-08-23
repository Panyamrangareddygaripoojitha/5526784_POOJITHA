#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000
typedef struct{
    int arr[SIZE];
    int top;
}stack;
void init(stack*s){
    s->top=-1;
}
int empty(stack*s){
    return s->top==-1;
}
void push(stack*s,int val){
    s->arr[++s->top]=val;
}
int pop(stack*s){
    return s->arr[s->top--];
}
int peek(stack*s){
    return s->arr[s->top];
}
int main(){
    int q;
    scanf("%d",&q);
    
    stack in,out;
    init(&in);
    init(&out);
    
    while(q--){
        int type,x;
        scanf("%d",&type);
        
        if(type==1){
            scanf("%d",&x);
            push(&in,x);
        }
        else if(type==2){
            if(empty(&out)){
                while(!empty(&in)){
                    push(&out,pop(&in));
                }
            }
            pop(&out);
        }
        else if(type==3){
            if(empty(&out)){
                while(!empty(&in)){
                    push(&out,pop(&in));
                }
            }
            printf("%d\n",peek(&out));
        }
    }
    return 0;
}
