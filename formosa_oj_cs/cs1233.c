#include<stdio.h>
void check(int ,int ,int ,int [],int []);
int n=0;
int flag =0;
int main(){
    int t;scanf("%d",&t);
    for(int i =0;i<t;i++){
    int target;scanf("%d",&target);
    int arr[22]={0};
    n =0;
    flag =0;
    int temp;
    while(1){
        scanf("%d",&temp);
        if(temp==0)break;
        else arr[n]=temp;
        n++;
    }
    int sum =0;
    int anss[22]={0};
    check(0,sum,target,arr,anss);
    if(flag)printf("finish\n");
    else printf("no solution\n");
    }
}
void check(int now,int sum,int target,int arr[],int ans[]){
    if(now>n)return;
    if(sum>target)return;
    if(sum == target){
        for(int i =0;i<n;i++){
            if(ans[i]==0)printf("X");
            else printf("O");
        }
        flag =1;
        printf("\n");
        return;
    }
    {
        int temp =sum+arr[now];
    ans[now]=1;
    check(now+1,temp,target,arr,ans);
    }
    ans[now]=0;
    check(now+1,sum,target,arr,ans);
}