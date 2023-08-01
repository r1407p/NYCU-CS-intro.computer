#include<stdio.h>

int t;
int queen[13];
int kill(int,int);//row and col
void dorecurrsion(int);
int main(){
    int T;scanf("%d",&T);
    for(int i =0;i<T;++i){
        scanf("%d",&t);
        dorecurrsion(0);
    }
}
void dorecurrsion(int n){
    for(int i =0;i<t;++i){
        if(kill(n,i)){
            queen[n]=i;
            if(n == t-1){
                for(int j = 0;j<t;++j)printf("%d ",queen[j]+1);
                printf("\n");
            }
            else dorecurrsion(n+1);
        }
    }

}
int kill(int row ,int col){
    int i;
    int rowx,colx;
    i = 0;
    while(i<row){
        if(queen[i]== col)return 0;
        rowx = abs(i-row);
        colx = abs(queen[i]-col);
        if(rowx == colx)return 0;
        i++;
    }
    return 1;
}

