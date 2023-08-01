#include<stdio.h>

int main(){
    int arr[3];scanf("%d %d %d",arr,arr+1,arr+2);
    for(int i =0;i<2;i++){     //sorting
        int flag = 1;
        for(int j = 0;j<2-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
                flag = 0;
            }
        }
        if(flag)break;
    }
    if(arr[0]+arr[1]<=arr[2])printf("OOPS");   // legel
    else{
        int a = arr[0]*arr[0];
        int b = arr[1]*arr[1];
        int c = arr[2]*arr[2];
        if(a+b==c)printf("right triangle");
        else if (a+b<c)printf("obtuse triangle");
        else printf("acute triangle");
    }

}