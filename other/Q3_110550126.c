#include<stdio.h>
int can1(int n);
int main(){
    int n ;scanf("%d",&n);
    printf("%d\n",can1(n));
}
int can1(int n){
    int arr[100005];
    int pivot =0;
    int temp = 0;
    while(1){
        while(n>0){
            temp+=(n%10)*(n%10);
            n/=10;
        }
        if(temp==1)return 1;
        for(int i =0;i<pivot;i++){
            if(temp==arr[i])return 0;
        }
        arr[pivot++] = temp;
        n = temp;
        temp = 0;
    }
}



    