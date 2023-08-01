#include<stdio.h>
                    // x y z  |  a2  a3()
                    // 1 0 0  |  a1  a2
                    // 0 1 0  |  a0  a1
void matrix(long long int a[3][3],long long int b[3][3]);
int main(){
    long long int t;scanf("%d",&t);          
    for(int i =0;i<t;++i){
        long long int base[3][3]={{},{1,0,0},{0,1,0}};
        long long int init[3][3]={{1,0,0},{0,1,0},{0,0,1}};
        long long int current[3];
        scanf("%d %d %d",&current[2],&current[1],&current[0]);
        scanf("%d %d %d",&base[0][0],&base[0][1],&base[0][2]);
        long long int find;scanf("%d",&find);
        while(find!=0){
            if(find%2){
                matrix(base,init);
            }
            matrix(base,base);
            find/=2;
        }
        long long int ans[3]={0};
        for(int i =0;i<3;i++){
            for(int j=0;j<3;j++){
                ans[i]+=(init[i][j]*current[j])%10000007;
            }
        }
        printf("%d\n",ans[2]%10000007);
    }
}
void matrix(long long int a[3][3],long long int b[3][3]){
    long long int temp[3][3];
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            temp[i][j]=0;
            for(int k =0;k<3;k++){
                temp[i][j] +=(a[i][k]*b[k][j])%10000007;
            }
        }
    }
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            b[i][j]=temp[i][j]%10000007;
        }
    }
}

