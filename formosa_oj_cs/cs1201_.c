#include<stdio.h>
int main(){
    int a,b;scanf("%d %d",&a,&b);
    int arr[a][b];
    for(int i =0;i<a;++i){
        for(int j =0;j<b;++j){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1)arr[i][j]=-1;
        }
    }
    for(int i =0;i<a;++i){
        for(int j =0;j<b;++j){
            if(arr[i][j]==-1){
                for(int q = i-1;q<=i+1;++q){
                    for(int k =j-1;k<=j+1;++k){
                        if(q>=0&&q<a&&k>=0&&k<b){
                            if(arr[q][k]!=-1)
                            arr[q][k]++;
                        }
                    }
                }
            }
        }
    }
    for(int i =0;i<a;++i){
        for(int j =0;j<b;++j){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}