#include<stdio.h>
int main(){
    int a,b,c,a1,b1,c1;
    scanf("(%d,%d,%d) (%d,%d,%d)",&a,&b,&c,&a1,&b1,&c1);
    if(a>a1)printf("Bob");
    else if(a<a1)printf("Alice");
    else{
        if(b>b1)printf("Bob");
        else if(b<b1)printf("Alice");
        else{
            if(c>c1)printf("Bob");
            else if(c<c1)printf("Alice");
        }
    }
    return 0;
}