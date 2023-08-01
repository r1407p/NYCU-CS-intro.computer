#include<stdio.h>
void matrix(long long int a[2][2],long long int b[2][2]);
int main (){
    int t ;scanf("%d",&t);
    for(int i =0;i<t;i++){
        long long int init[2][2]={{1,1},{1,0}};
        long long int I[2][2]={{1,0},{0,1}};
        long long int temp ;scanf("%d",&temp);
        while(temp!=0){
            if(temp%2)matrix(init,I);
            matrix(init,init);
            temp/=2;
        }
        printf("%d\n",I[1][0]%10000007);
    }
}
void matrix(long long int a[2][2],long long int b[2][2]){
    long long int ans[2][2];
    for(int i =0;i<2;i++){
        for(int j = 0;j<2;j++){
            ans[i][j]=0;
            for(int k=0;k<2;k++){
                ans[i][j] +=a[i][k]*b[k][j];
            }
        }
    }
    for(int i =0;i<2;i++){
        for(int j=0;j<2;j++){
            b[i][j]=ans[i][j]%10000007;
        }
    }
}
   