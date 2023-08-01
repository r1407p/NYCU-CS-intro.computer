#include<stdio.h>
int main(){
    int t;scanf("%d",&t);
    int max=0,max2=0;
    int temp;
    for(int i =0;i<t;i++){
        scanf("%d",&temp);
        if(temp>max){
            max2 =max;
            max = temp;
        }
        else if (temp>max2) max2 = temp;    
    }
    printf("%d",max2);
}