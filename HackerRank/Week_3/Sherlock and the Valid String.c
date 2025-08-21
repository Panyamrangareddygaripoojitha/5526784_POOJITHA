#include <stdio.h>
#include <stdlib.h>
#define SIZE 26
const char*checkValid(char s[]){
    int freq[SIZE]={0};
    for(int i=0;s[i]!='\0';i++){
        int index=s[i]-'a';
        freq[index]++;
    }
    int count[SIZE],n=0;
    for(int i=0;i<SIZE;i++){
        if(freq[i]>0){
            count[n++]=freq[i];
        }
    }
    int min=count[0],max=count[0];
    for(int i=1;i<n;i++){
        if(count[i]<min)min=count[i];
        if(count[i]>max)max=count[i];
        }
       if(min==max)return "YES";
       int ones=0,freqMax=0;
       for(int i=0;i<n;i++){
        if(count[i]==1)ones++;
        if(count[i]==max)freqMax++;
       } 
       if(ones==1&&max==min+1)return "YES";
       if(ones==1&&freqMax==n-1)return "YES";
       if(max-min==1){
        int minCount=0,maxCount=0;
        for(int i=0;i<n;i++){
            if(count[i]==min)minCount++;
            if(count[i]==max)maxCount++;
        }
        if(maxCount==1||minCount==1)return "YES";
       }
       return "NO";
       }
       int main(){
        char s[100005];
        scanf("%s",s);
        printf("%s\n",checkValid(s));
        return 0;
       }
       
