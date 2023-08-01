#include<stdio.h>
int main (){
    int n,q;scanf("%d %d",&n,&q);
    int arr[n];
    for(int i =0;i<n;i++)scanf("%d",arr+i);
    int temp;
    while(scanf("%d",&temp)!=EOF){
        int flag =1;
        for(int j =0;j<n;j++){
            if (temp ==arr[j]){
                printf("YES\n");
                flag =0;
                break;
            }
        }
        if(flag)printf("NO\n");
    }
}