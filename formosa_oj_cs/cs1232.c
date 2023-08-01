#include<stdio.h>
#define MAX 10
long long  determinant(int,int[MAX][MAX]);
int main(){
    int size;
    while(scanf("%d",&size)!=EOF){
        int arr[MAX][MAX]={{0}};
        for(int i=0;i<size;i++){
            for(int j =0;j<size;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        long long  ans = determinant(size,arr);
        ans %= 100000007;
        if(ans < 0)ans += 100000007;
        printf("%lld\n",ans);
    }     
}
long long determinant(int n,int arr[MAX][MAX]){
    int b[MAX][MAX]={{0}};
    long long sum =0;
    int x =0,p =0;
    if(n ==1)return arr[0][0];
    for(int i =0; i<n;i++){
        for(int c =0 ;c<n-1;++c){
            for(int j = 0;j<n-1;++j){
                if (c<i) p =0;
                else p=1;
                b[c][j] = arr[c+p][j+1];
            }
        }
        if(i%2 ==0)x =1;
        else x = -1;
        sum += arr[i][0]*determinant(n-1,b)*x; 
    }
    return sum;
}
