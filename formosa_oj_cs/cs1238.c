#include<stdio.h>
int low,high;
void increase(int n );
int main(){
    int t;scanf("%d",&t);
    for(int i =0;i<t;++i){
        scanf("%d %d",&low,&high);
        for(int i=1;i<=9;i++) increase(i);
        printf("\n");
    }
}
void increase(int n ){
    int ans = n;
    while(ans<=high){
        if(ans>=low)printf("%d ",ans);
        ++n;
        if(n>9)return;
        ans = ans*10+n;
    }
}