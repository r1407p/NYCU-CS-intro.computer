#include<stdio.h>
#include<math.h>
int main(){
    int num,t;scanf("%d %d",&num,&t);
    printf("%d\n",num);
    for(int i =0;i<t;++i){
        if(num %10 == 0){
            num /= 10;
            printf("%d\n",num);
        }
        else{
            int pivot = num%10;
            num /= 10;
            int temp = num;
            int dig=0;
            while(temp != 0){
                dig++;
                temp/=10;
            }
            num += pivot*pow(10,dig);
            printf("%d\n",num);
        }
    }
    return 0;
}