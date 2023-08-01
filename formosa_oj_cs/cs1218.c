#include<stdio.h>
#include<math.h>
long long int bigmod(int,int,int);
int main(){
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        a %= c;
        long long int ans = bigmod(a,b,c);
        printf("%lld\n",ans);
    }
}
long long int  bigmod(int a,int b,int c){
    if(b==0)return 1;
    if(b==1)return a;
    long result = bigmod(a,b/2,c);
    if(b%2)return result*result*a %c;
    else return result*result%c;
}


