#include <stdio.h>
#include <stdlib.h>
void generatePrimes(int primes[],int q){
    int count=0;
    int num=2;
    while(count<q){
        int isPrime=1;
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                isPrime=0;
                break;
            }
        }
            if(isPrime){
                primes[count++]=num;
            }
            num++;
        }
}
    
    void waiter(int numbers[],int n,int q){
        int*primes=(int*)malloc(q*sizeof(int));
        generatePrimes(primes,q);
        
        int*A=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)A[i]=numbers[i];
        
        int aSize=n;
        
        for(int i=0;i<q;i++){
        int prime=primes[i];
        
        int*B=(int*)malloc(aSize*sizeof(int));
        int Btop=-1;
        
        
        int*nextA=(int*)malloc(aSize*sizeof(int));
        int nextSize=0;
        
    
            for(int j=aSize-1;j>=0;j--){
                if(A[j]%prime==0){
                    B[++Btop]=A[j];
                }else{
                    nextA[nextSize++]=A[j];
                }
            }
            for(int j=Btop;j>=0;j--)printf("%d\n",B[j]);
                
            for(int j=0;j<nextSize;j++)
                A[j]=nextA[j];
            aSize=nextSize;
        
        free(B);
        free(nextA);
}
    for(int i=aSize-1;i>=0;i--)printf("%d\n",A[i]);
    free(A);
    free(primes);
    }


int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    
    int *numbers=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",&numbers[i]);
    
    waiter(numbers,n,q);
    free(numbers);
    return 0;
}