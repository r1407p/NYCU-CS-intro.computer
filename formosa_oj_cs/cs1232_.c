#include<stdio.h>
#define MAX 10
long long determinant(int,int[MAX][MAX]);
int main(){
    int size;
    while(scanf("%d",&size)!=EOF){
        long long sum;
        int arr[MAX][MAX] = {{0}};
        for(int i =0;i<size;++i){
            for(int j =0;j<size;++j){
                scanf("%d",&arr[i][j]);
            }
        }
        sum = determinant(size,arr);
        sum %= 100000007;
        if(sum < 0)sum += 100000007;
        printf("%lld\n",sum);
    }
}
long long determinant(int n ,int arr[MAX][MAX]){
    int b[MAX][MAX]={{0}};
    long long sum =0;
    int pivot=0,extra=0;//up or down
    if(n==1) 
        return arr[0][0];
    for(int first =0;first <n;++first){
        for(int i =0;i<n-1;++i){
            for(int j =0;j<n-1;++j){
                if(i<first)extra =0;
                else extra = 1;
                b[i][j]=arr[i+extra][j+1];
            }
        }
        if(first %2 ==1)pivot =-1;
        else pivot =1;
        sum += (arr[first][0]*determinant(n-1,b)*pivot)%100000007;
    }
    return sum;
}