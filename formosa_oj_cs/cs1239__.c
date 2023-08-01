#include<stdio.h>
#include<math.h>
ans =0;
void place(int a,int at[],int max);
int  canplace(int a,int b,int at[]);
int main(){
    int tttt;scanf("%d",&tttt);
    for(int i =0;i<tttt;i++){
        int t ;scanf("%d",&t);
        for(int i =0;i<t;i++){
            int at[t];
            at[0] =i;
            place(1,at,t);
        }
    }
    printf("%d",ans);
}
int  canplace(int a,int b,int at[]){
    for(int i =0;i<a;i++){
        int x = abs(a-i);
        int y = abs(at[i]-b);
        if(x==y)return 0 ;
        if(y==0)return 0 ;
    }
    return 1;
}
void place(int a,int at[],int max){
    if(a==max){
        for(int i =0;i<max;i++){
            printf("%d ",at[i]+1);
        }
        printf("\n");
        ans++;
        return; 
    }
    for(int i =0;i<max;i++){
        if(canplace(a,i,at)){
            at[a]=i;
            place(a+1,at,max);
        }
    }
}
