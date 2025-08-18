#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool isPowerOfTwo(unsigned long long n){
    return(n && !(n&(n-1)));
}
unsigned long long largestPowerOfTwo(unsigned long long n){
    unsigned long long p=1ULL;
    while(p<<1ULL<=n){
    p<<=1ULL;
}
return p;
}
char*counterGame(unsigned long long n)
{
int moves=0;
while(n>1){
    if(isPowerOfTwo(n)){
        n/=2;
    }else{
        n-=largestPowerOfTwo(n);
    }
    moves++;
   }
   if(moves%2==1)return "Louise";
   else return "Richard";
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        unsigned long long n;
        scanf("%llu",&n);
        printf("%s\n",counterGame(n));
    }
    return 0;
}
    
    
