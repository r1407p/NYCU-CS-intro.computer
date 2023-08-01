#include<stdio.h>
int t;
char arr[100];
void dfs(int,int,int,int);
int main(){
    scanf("%d",&t);
    int max = t*2;
    dfs(0,0,0,max);
    return 0;
}
void dfs(int open,int close,int now,int max){
    if(open<close||open>t)return;
    if(now ==max){
        arr[max]='\0';
        printf("%s\n",arr);
        return;
    }
    arr[now] ='(';dfs(open+1,close,now+1,max);
    arr[now] =')';dfs(open,close+1,now+1,max);
}