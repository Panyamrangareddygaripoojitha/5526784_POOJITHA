#include <stdio.h>
#include <string.h>
long long digitSum(char n[]){
    long long sum=0;
    for(int i=0;i<strlen(n);i++){
    sum+=n[i]-'0';
    }
    return sum;
}
int superDigitCheck(long long num){
    if(num<10){
        return(int)num;
    }
    long long sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    return superDigitCheck(sum);
}    
int superDigit(char n[],int k){
    long long initialSum=digitSum(n);
    long long total=initialSum*k;
    return superDigitCheck(total);
}
int main(){
    char n[100001];
    int k;
    scanf("%s %d",&n,&k);
    int result=superDigit(n,k);
    printf("%d\n",result);
    return 0;
}
