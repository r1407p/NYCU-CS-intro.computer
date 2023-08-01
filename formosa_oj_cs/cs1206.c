#include<stdio.h>

int main(){
    int t;scanf("%d",&t);
    int x[t+1];
    int y[t+1];
    for(int i =0; i<t;++i)scanf("%d %d",x+i,y+i);
    x[t] = x[0]; y[t] = y[0];
    double sum = 0;
    for(int i=0;i<t;++i){
        sum +=x[i]*y[i+1];
        sum -=y[i]*x[i+1];
    }
    if(sum <0)sum = -sum;
    sum/=2;
    printf("%.1f",sum);
}