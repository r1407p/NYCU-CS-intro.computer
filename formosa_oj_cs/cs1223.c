#include<stdio.h>
void tower(int ,char,char,char);
int main(){
    int t;char a ='A',b ='B',c ='C';
    while(scanf("%d",&t)!=EOF){
        tower(t,a,b,c);
        printf("finish\n");
    }
}
void tower(int n,char from,char aux, char to){
    if(n==1)printf("Move ring 1 from %c to %c\n",from,to);
    else{
        tower(n-1,from,to,aux);
        printf("Move ring %d from %c to %c\n",n,from,to);
        tower(n-1,aux,from,to);
    }
}