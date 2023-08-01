#include<stdio.h>

void matrix(long long int a[6][6],long long int b[6][6],int size);
long long int init[6][6]={{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
long long int base[6][6]={{0,0,0,0,0,0},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
int main(){
    int t;scanf("%d",&t);
    long long int start[t];for(int i =0;i<t;i++)scanf("%lld",start+(t-i-1));
    for(int i =0;i<t;i++)scanf("%lld",&base[0][i]);
    long long int target;scanf("%d",&target);
    if(target<t){
        printf("%d",start[t-target-1]);
        return 0;
    }
    target -=(t-1);
    while(target!=0){
        if(target%2)matrix(base,init,t);
        matrix(base,base,t);
        target/=2;
    }
    long long end[t];
    for(int i =0;i<t;i++){
        end[i]=0;
        for(int j =0;j<t;j++){
            end[i]+=init[i][j]*start[j]%10000007;
        }
    }
    printf("%lld",end[0]%10000007);
}
void matrix(long long int a[6][6],long long int b[6][6],int size){
    int temp[6][6]={0};
    for(int i =0;i<size;i++){
        for(int j =0;j<size;j++){
            for(int k =0;k<size;k++)temp[i][j]+=a[i][k]*b[k][j]%10000007;
        }
    }
    for(int i =0;i<size;i++){
        for(int j=0;j<size;j++)b[i][j]=temp[i][j]%10000007;
    }
}