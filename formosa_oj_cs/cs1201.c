#include<stdio.h>
int main (){
    int a,b;scanf("%d %d",&a,&b);
    int arr[a][b];
    int ans[a][b];
    for(int i = 0;i<a;++i){
        for(int j =0;j<b;++j){
            scanf("%d",&arr[i][j]);
            ans[i][j] = 0;
        }
    }
    int downx,upx,downy,upy;
    for(int i = 0;i<a;++i){
        for(int j =0;j<b;++j){
            if(arr[i][j] ==1){
                if(i==0){
                    downx=0;
                    upx =1;
                }
                else if(i ==a-1){
                    downx =a-2;
                    upx =a-1;
                }
                else{
                    downx=i-1;
                    upx = i+1;
                }
                if(j==0){
                    downy=0;
                    upy =1;
                }
                else if(j ==b-1){
                    downy =b-2;
                    upy =b-1;
                }
                else{
                    downy=j-1;
                    upy = j+1;
                }
                for(int q = downx;q<=upx;q++){
                    for(int w= downy;w<=upy;w++){
                        if(ans[q][w]==-1)continue;
                        ans[q][w]+=1;
                    }

                }
                ans[i][j] =-1;  
            }      
        }
    }
    for(int i =0;i<a;++i){
        for(int j =0;j<b;++j)printf("%d ",ans[i][j]);
        printf("\n");
    }
}