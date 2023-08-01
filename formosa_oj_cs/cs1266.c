#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Link{
    int value;
    struct Link* right;
    struct Link* left;
};
typedef struct Link link;
void what(link *TP);
link * left(link *TP);
link * right(link *TP);
void insert(int k ,link *TP);
int main(){
    link *TP  = malloc(sizeof(link));
    TP->value = 1;
    TP->right = TP;
    TP->left  = TP;
    int t ;scanf("%d",&t);
    for(int i =0;i<t;i++){
        char string[100];
        scanf("%s",string);
        if(strcmp(string,"WHAT")==0){
            what(TP);
        }else if(strcmp(string,"LEFT")==0){
            TP =left(TP);
        }else if(strcmp(string,"RIGHT")==0){
            TP =right(TP);
        }else if(strcmp(string,"INSERT")==0){
            int k ;scanf("%d",&k);
            insert(k,TP);
        }
    }
}
void what(link *TP){
    printf("%d\n",TP->value);
}
link * right(link *TP){
    return TP->right;
}
link * left(link *TP){
    return TP->left;
}
void insert(int k,link *TP){
    link *next = malloc(sizeof(link));
    next = TP->right;
    link *new = malloc(sizeof(link));
    new->value = k;
    new->right = TP->right;
    TP->right = new;
    new->left = TP;
    if(new->right ==TP)TP->left = new;
    if(new->right == next);next->left = new;
}