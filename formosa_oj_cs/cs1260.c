#include<stdio.h>
#include<stdlib.h>
int main(){
    int t;scanf("%d",&t);
    int **arr = malloc(t*sizeof(int **));
    for(int i =0;i<t;i++){
        int k;scanf("%d",&k);
        arr[i] = malloc(k*sizeof(int *));
        for(int j =0;j<k;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int l ;scanf("%d",&l);
    for(int i =0;i<l;i++){
        int a,b;scanf("%d %d",&a,&b);
        printf("%d\n",arr[a][b]);
    }
}