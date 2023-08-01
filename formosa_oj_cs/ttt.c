#include<stdio.h>
int main(){
    int t;scanf("%d",&t);
    int arr[10001]={0};
    int a,b,c;
    int max=0;
    for(int i=0;i<t;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(c>max)max =c;
        for(int j = a;j<c;j++){
            if(arr[j]<b)arr[j]=b;
        }
    }
    int current = arr[0];
    if(arr[1]==0)printf("1 %d ",current);
    for(int i =1;i<max+1;i++){
        if(arr[i]==current)continue;
        else{
            printf("%d %d ",i,arr[i]);
            current = arr[i];
        }
    }
}