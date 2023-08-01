#include<stdio.h>
int main(){
    int t;scanf("%d",&t);
    for(int i =0;i<t;++i){
        int temp ;scanf("%d",&temp);
        char arr[temp][100];
        for(int j = 0;j<temp ;++j){
            scanf("%s",arr+j);
        }
        for(int j = temp-1;j>=0;--j){
            int k =0; 
            while(arr[j][k]!='\0'){
                printf("%c",arr[j][k]);
                ++k;
            }
            printf(" ");
        }
        printf("\n");
    }
}