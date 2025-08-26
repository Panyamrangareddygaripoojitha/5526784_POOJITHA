#include <stdio.h>
#define MOD 1000000007
long long modpow(long long base,int exp){
    long long res=1;
    while(exp>0){
        if(exp&1)res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp>>=1;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    
    int n[t],m[t],maxM=0;
    for(int i=0;i<t;i++){
        scanf("%d %d",&n[i],&m[i]);
        if(m[i]>maxM)maxM=m[i];
    }
    long long row[maxM+1];
    row[0]=1;
    for(int w=1;w<=maxM;w++){
        row[w]=0;
        if(w>=1)row[w]=(row[w]+row[w-1])%MOD;
        if(w>=2)row[w]=(row[w]+row[w-2])%MOD;
        if(w>=3)row[w]=(row[w]+row[w-3])%MOD;
        if(w>=4)row[w]=(row[w]+row[w-4])%MOD;
      }
      for(int c=0;c<t;c++){
        int N=n[c],M=m[c];
        
        long long total[M+1],solid[M+1];
        for(int w=1;w<=M;w++){
           total[w]=modpow(row[w],N);
        }
        solid[0]=0;
        for(int w=1;w<=M;w++){
            solid[w]=total[w];
            for(int cut=1;cut<w;cut++){
                solid[w]=(solid[w]-(solid[cut]*total[w-cut])%MOD+MOD)%MOD;
                }
            }
        printf("%lld\n",solid[M]);
      }
      return 0;
}