#include<stdio.h>
int main(){
    int ans[10],guess[10];
    for(int i =0;i<10;i++)scanf("%d",ans+i);
    for(int j =0;j<10;j++)scanf("%d",guess+j);
    int A =0;
    for(int k =0;k<10;k++){
        if(ans[k]==guess[k])A++;
    }
    printf("%dA%dB",A,10-A);
}