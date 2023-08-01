#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct shopping{
    int priority;
    int cash;
    char name[12];
}buy[11];
typedef struct shopping shop;
int compare(const shop* a,const shop* b);
int main(){
    int t;scanf("%d",&t);
    char list[12][12],pivot;
    for(int i =0;i<t;i++){
        pivot =0;
        int money,item;scanf("%d %d",&money,&item);
        int save = money;
        for(int i =0;i<item;i++){
            scanf("%d %d %s",&buy[i].priority,&buy[i].cash,buy[i].name);
            //printf("%d %d %s",buy[i].priority,buy[i].cash,buy[i].name);
        }
        qsort(buy,item,sizeof(shop),compare);
        /*for(int i =0;i<item;i++){
            printf("%d\n",buy[i].priority);
        }*/
        for(int i =0;i<item;i++){
            if(money-buy[i].cash>=0){
                strcpy(list[pivot],buy[i].name);
                money-=buy[i].cash;
                pivot++;
            }
        }
        qsort(list,pivot,sizeof(char)*12,strcmp);
        printf("%d ",save-money);
        for(int i =0;i<pivot;i++){
            printf("%s ",list[i]);
        }
        printf("\n");
    }
}
int compare(const shop* a,const shop* b){
    return -a->priority + b->priority;
}