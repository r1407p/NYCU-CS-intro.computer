#include<stdio.h>
int main (){
    int atm1 = 0;
    int atm2 = 0;
    int time[201],i =0;
    while(scanf("%d",time+i)!=EOF)i++;
    for(int j = 0;j<i-1;j++){
        if(atm1<atm2)atm1+=time[j];
        else atm2+=time[j];
    }
    int temp ;
    if(atm1<atm2)temp = atm1;
    else temp = atm2;
    temp +=time[i-1];
    printf("%dm%ds\n",temp/60,temp%60);
}