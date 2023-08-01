#include<stdio.h>
struct Family{
    char name[35];
    int kidnum;
    int parentnum;
    int unnum;
    struct Family *kid[50];
    struct Family *parent[2];
    struct Family *un[50];
};
typedef struct Family family;
family root = {"Dong",0,0,0};
int main(){
    int t;scanf("%d",&t);
    for(int i =0;i<t;i++){
        char a[35],b[35];
        scanf("%s %s",a,b);
        find(a,b,0);
    }
}
void find(const char a[],const char b[],int n){
    
}