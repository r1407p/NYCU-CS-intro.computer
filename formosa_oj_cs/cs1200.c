#include<stdio.h>
int main(){
    int a,b;scanf("%d %d",&a,&b);
    int arr[a][b];
    for(int i =0;i<a;i++){
        for(int j =0;j<b;j++)arr[i][j] =1;
    }
    int t;scanf("%d",&t);
    for(int i =0;i<t;i++){
        int tempx,tempy;scanf("%d %d",&tempx,&tempy);
        for(int j = tempx-1;j<=tempx+1;++j){
            for(int k  =tempy -1;k<=tempy+1;++k){
                if(j>=0&&j<a&&k>=0&&k<b)arr[j][k]=0;
            }
        }
    }
    int sum =0;
    for(int i =0;i<a;i++){
        for(int j =0;j<b;j++){
            if(arr[i][j]==1)sum++;
            }
        }
    printf("%d",sum);
}
