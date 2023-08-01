#include<stdio.h>
int arr[9];
int max;
int main(){
    int t;scanf("%d",&t);
    for(int i =0;i<t;i++){
        scanf("%d",&max);
        recur(max);
    }
}
void recur(int n){
    if(n == 0){
        for(int i =0;i<max;++i)printf("%d",arr[i]);
        printf("\n");
        return;
    }
    for(int i =1;i<max+1;++i){
        int flag =1;
        for(int j =0;j<max-n;++j){
            if(arr[j]==i)flag =0;
        }
        if(flag){        
            arr[max-n]=i;
            recur(n-1);
        }
    }
}