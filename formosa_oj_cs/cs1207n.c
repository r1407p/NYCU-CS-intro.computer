#include<stdio.h>
int min(int,int);
int max(int,int);
int main(){
    int temp;scanf("%d",&temp);
    for(int i =0;i<temp;++i){
        int t;scanf("%d",&t);
        long long int sum=0;
            for(int j =0;j<t;j++){
                int arr[500][4];
                for(int k=0;k<4;++k)scanf("%d",&arr[j][k]);
                sum+=(arr[j][2]-arr[j][0])*(arr[j][3]-arr[j][1]);
                for(int k  =0;k<j;++k){
                    int x1 =max(arr[j][0],arr[k][0]);
                    int y1 =max(arr[j][1],arr[k][1]);
                    int x2 =min(arr[j][2],arr[k][2]);
                    int y2 =min(arr[j][3],arr[k][3]);
                    if(x1<=x2 && y1<=y2)sum -=(x1-x2)*(y1-y2);
                }
        }

        printf("%lld\n",sum);
    }
}
int min(a,b){
    if(a<b)return a;
    else return b;
}
int max(a,b){
    if(a>b)return a;
    return b;
}