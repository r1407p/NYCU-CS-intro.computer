#include<stdio.h>
int main(){
    int width,hight;
    int arr[200];
    while(scanf("%d %d",&width,&hight)!=EOF){
        for(int i =0;i<width;i++)arr[i]=0;
        for(int i =0;i<hight;i++){
            int temp = 0;
            while(temp<width){
                int brick;scanf("%d",&brick);
                temp+=brick;
                arr[temp]++;
            }
        }
        int max = 0;
        for(int i =0;i<width;i++){
            if(arr[i]>max)max = arr[i];
        }
        printf("%d\n",hight-max);
    }
}

