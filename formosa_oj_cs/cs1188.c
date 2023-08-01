#include<stdio.h>
int main(){
    int ans[9];
    int guess[9];
    int A=0,B=0;
    for(int i =0;i<9;++i)scanf("%d",ans+i);
    for(int i =0;i<9;++i)scanf("%d",guess+i);
    for(int i =0;i<9;++i){
        if(ans[i]==guess[i]){
            ++A;
            ans[i]=-1;
            guess[i]=-1;
        }
    }
    for(int i =0;i<9;++i){
        for(int j =0;j<9;++j){
            if(ans[i]==-1)break;
            if(ans[i]==guess[j]){
                ans[i]=-1;
                guess[j]=-1;
                ++B;
                break;
            }
        }
    }
    printf("%dA%dB",A,B);
}