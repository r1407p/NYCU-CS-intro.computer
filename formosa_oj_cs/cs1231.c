#include<stdio.h>
int main(){
    int a,b,t;
    scanf("%d %d %d",&a,&b,&t);
    int arr[100][100]={{0}};
    for(int i =0;i<t;++i){
        int x,y,z;
        scanf("%d %d %d",&z,&x,&y);
        z /=2;
        int xd,xu,yd,yu;
        if(x-z<0)xd = 0;
        else xd = x-z;
        if(x+z>=a-1) xu =a-1;
        else xu = x+z; 
        if(y-z<0)yd = 0;
        else yd = y-z;
        if(y+z>=b-1) yu =b-1;
        else yu = y+z; 
        for(int j =xd;j<=xu;++j){
            for(int k = yd;k<=yu;++k){
                arr[j][k] = 1;
            }
        }
    }
    int qwe = 0;
    for(int j =0;j<a;++j){
        for(int k = 0;k<b;++k){
            if(arr[j][k] == 0)++qwe;
        }
    }
    printf("%d",qwe);
}