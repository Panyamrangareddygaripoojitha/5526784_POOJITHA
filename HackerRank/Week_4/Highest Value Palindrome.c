#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*highestValuePalindrome(char*s,int n,int k){
    char*res=strdup(s);
    int*changed=(int*)calloc(n,sizeof(int));
    int i,j,changes_used=0;
    for(i=0,j=n-1;i<j;i++,j--){
        if(res[i]!=res[j]){
            char maxc=(res[i]>res[j])?res[i]:res[j];
            res[i]=res[j]=maxc;
            changed[i]=changed[j]=1;
            changes_used++;
        }
    }
    if(changes_used>k){
        free(changed);
        free(res);
        return strdup("-1");
    }
    int remaining=k-changes_used;
    for(i=0,j=n-1;i<=j;i++,j--){
        if(i==j){
            if(remaining>0&&res[i]!='9')res[i]='9';
        }
        else{
            if(res[i]!='9'){
                if(changed[i]||changed[j]){
                    if(remaining>=1){
                        res[i]=res[j]='9';
                        remaining--;
                    }
                }
                else if(remaining>=2){
                    res[i]=res[j]='9';
                    remaining-=2;
                }
            }
        }
    }
    free(changed);
    return res;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char s[n+1];
    scanf("%s",s);
    char*ans=highestValuePalindrome(s,n,k);
    printf("%s\n",ans);
    free(ans);
    return 0;
}
