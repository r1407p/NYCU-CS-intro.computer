#include<stdio.h>
int main(){
    int guess[2];scanf("%d %d",guess,guess+1);
    int ans[2];scanf("%d %d",ans,ans+1);
    int A = 0,B =0;
    for(int i =0;i<2;i++){
        if(guess[i]==ans[i])A++;
    }
    if(guess[0]==ans[1])B++;
    if(guess[1]==ans[0])B++;
    printf("%dA%dB",A,B);
}