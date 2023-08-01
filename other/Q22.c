#include<stdio.h>
int main(){
    long int a,b;scanf("%ld %ld",&a,&b);
    long int max=0;
    printf("%ld %ld ",a,b);
    if(a>b){
        int temp = a;
        a= b;
        b= temp;
    }
    for(int i=a;i<=b;++i){
        int temp = i;
        int t=1;
        while(temp!=1){
            if(temp%2==0){
                temp/=2;
                ++t;
            }
            else{
                temp = temp*3+1;
                ++t;
            }
        }
        if(t>max)max =t;
    }
    printf("%ld",max);
}