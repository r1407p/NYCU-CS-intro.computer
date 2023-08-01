#include<stdio.h>
#include<math.h>
int arr[1000000]={2,3};
int n =1;
int main(){
    int t;scanf("%d",&t);
    for(int i=3;i<t;i+=2){
        if(isprime(i)){
            n++;
        }
    }
    for(int i=0;i<n;i++)printf("%d  ",arr[i]);
    printf("%d",n);
}
int isprime(int nn){
    for(int i=0;i<n;i++){
        if(nn%arr[i]==0)return 0;
        else{
            arr[n]=nn;
        }
    }
}