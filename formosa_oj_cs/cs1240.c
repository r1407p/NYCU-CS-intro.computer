#include<stdio.h>
int main(){
    int a,b,c;scanf("%d %d %d",&a,&b,&c);
    int arr[a][b];
    int q,w,e;
    int downx,upx,downy,upy;
    for(int o =0;o<a;o++){
        for(int p =0;p<b;p++)arr[o][p] =0;
    }
    for(int i = 0;i<c;++i){
        scanf("%d %d %d",&q,&w,&e);
        int r =q/2;
        if(w-r<=0)downx =0;
        else downx = w-r;
        if (w+r>=a)upx = a-1;
        else upx = w+r;
        if(e-r<=0)downy =0;
        else downy = e-r;
        if (e+r>=a)upy = a-1;
        else upy = e+r;
        for(int j =downx;j<=upx;++j){
            for(int k = downy;k<=upy;++k){
                arr[j][k] = arr[j][k]+1;
            }
        }
    }
    int t =0;
    for(int i =0;i<a;i++){
        for(int j =0;j<b;j++){
            if(arr[i][j]>0&&arr[i][j]<3)++t;;
        }
    }
    printf("%d",t);
}