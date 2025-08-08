#include <stdio.h>
#include <string.h>
#include <ctype.h>
 int main(){
    char s[1000];
    int alphabet[26]={0};
    int i;
    fgets(s,sizeof(s),stdin);
    for(int i=0;s[i]!='\0';i++){
        char ch=tolower(s[i]);
        
        if(ch>='a'&&ch<='z'){
            alphabet[ch-'a']=1;
        
        }
    }
    int is_pangram=1;
    for(int i=0;i<26;i++){
        if(alphabet[i]==0){
            is_pangram=0;
            break;
        }
    }
    if(is_pangram)
    printf("pangram\n");
    else
    printf("not pangram\n");
    return 0;
 }