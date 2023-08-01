#include<stdio.h>
#include<math.h>
int isPrime(int n){
    if(n==2||n==3)return 1;
    if(n==1||n%2 == 0)return 0;
    for(int i =3;i<sqrt(n)+1;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main(){
    int t;scanf("%d",&t);
    int temp;
    for(int i =0;i<t;i++){
        scanf("%d",&temp);
        if(isPrime(temp))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}