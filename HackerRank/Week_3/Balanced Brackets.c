#include <stdio.h>
#include <string.h>
#define SIZE 1000
char stack[SIZE];
int top=-1;

void push(char c){
    stack[++top]=c;
}
char pop(){
    if(top==-1)return '\0';
    return stack[top--];
    }
    int isBalanced(char*s){
        top=-1;
        for(int i=0;s[i]!='\0';i++){
            char c=s[i];
        
        if(c=='('||c=='{'||c=='['){
            push(c);
        }
        else{
            if(top==-1)return 0;
            char open=pop();
            
            if((c==')'&&open!='(')||
            (c=='}'&&open!='{')||
            (c==']'&&open!='[')){
                return 0;
            }
        }
        }
        return (top==-1);
    }
    int main(){
        int n;
        scanf("%d",&n);
        
        char s[SIZE];
        for(int i=0;i<n;i++){
            scanf("%s",s);
            if(isBalanced(s))
            printf("YES\n");
            else
             printf("NO\n");
        }
        return 0;
    }