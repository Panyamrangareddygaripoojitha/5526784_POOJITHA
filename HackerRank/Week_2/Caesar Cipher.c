#include <stdio.h>
#include <string.h>
#include <ctype.h>
void caesarCipher(char s[],int k){
    int len =strlen(s);
    k=k%26;
    for(int i=0;i<len;i++){
        char ch=s[i];
        
        if(isalpha(ch)){
            if(islower(ch)){
                s[i]='a'+((ch-'a'+k)%26);
            }else if(isupper(ch)){
                s[i]='A'+((ch-'A'+k)%26);
            }
        }
    }
}int main(){
    int n,k;
    char s[1000];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    caesarCipher(s,k);
    printf("%s\n",s);
    return 0;
}