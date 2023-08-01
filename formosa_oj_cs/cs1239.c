#include<stdio.h>
int t;
int arr[12][12];
int ans[12];
void dorecursion(int n,int now){
    if(n ==now){
        for(int u=0;u<n;u++)printf("%d ",ans[u]+1);
        printf("\n");
        return;
    }
    for(int i =0;i<n;i++){
        if(now ==0){
            for(int j = 0;j<n;j++){  //初始化矩陣
                for(int k =0;k<n;++k)arr[j][k] =0;}}
        if(arr[now][i]==0){
            ans[now]=i;//標記殺人範圍
            for(int q=0;q<n;++q){
                arr[now][q]=1;
                arr[q][i]=1;
            }
            for(int q =now,w=i;q<n&&w<n;++q,++w)arr[q][w]=1;
            for(int q =now,w=i;q<n&&w>=0;++q,--w)arr[q][w]=1;
            for(int q =now,w=i;q>=0&&w<n;--q,++w)arr[q][w]=1;
            for(int q =now,w=i;q>=0&&w>=0;--q,--w)arr[q][w]=1;
            arr[now][i] = 2;
            for(int j = 0;j<n;j++){ 
                for(int k =0;k<n;++k)printf("%d",arr[j][k]);
                printf("\n");}
            printf("\n");
            dorecursion(n,now+1);
        }
    }
}   

int main(){
    int t ;scanf("%d",&t);
    for(int i =0;i<t;++i){
        int n;scanf("%d",&n);
        dorecursion(n,0);       
    }
}