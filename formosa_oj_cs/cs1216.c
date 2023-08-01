#include<stdio.h>
int GCD(int a,int b){
    while(a!=0){
        int temp = a;
        a = b%a;
        b = temp;
    }
    return b;

}
int main (){
    int a,b;scanf("%d %d",&a,&b);
    printf("%d",GCD(a,b));
}