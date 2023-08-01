#include<stdio.h>
#include<stdlib.h>
int flag =0;
int arr[250];
int used[1000];
int n =0;
void find(int now,int target,int pivot ,int use);
int main(){
    int t ;scanf("%d",&t);
    for(int i =0;i<t;i++){
        int target;scanf("%d",&target);
        flag =0;
        n =0;
        scanf("%d",&arr[n]);
        while(arr[n]!=0){
            n++;
            scanf("%d",&arr[n]);
        }
        n--;
        find(0,target,0,0);
        if(flag)printf("finish\n");
        else printf("no solution\n");
    }
}
void find(int now,int target,int pivot ,int use){
    if(now==target){
        for(int i =0;i<use;i++){
            int temp = used[i];
            printf("%d ",arr[temp]);
        }
        flag =1;
        printf("\n");
        return;
    }
    else if(now<target){
        if(pivot==n){
            used[use] = pivot;
            find(now+arr[pivot],target,pivot,use+1);
        }
        else{
            used[use] = pivot;
            find(now+arr[pivot],target,pivot,use+1);
            find(now,target,pivot+1,use);
        }
    }
    return; 
}