#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct shopping{
    int priority[11];
    int money[11];
    char name[11][11];
}shopping;
int main(){
    int T;scanf("%d",&T);
    for(int i =0;i<T;i++){
        int pocket ,item;scanf("%d %d",&pocket,&item);
        for(int j = 0;j<item;++j){
            scanf("%d %d %s",&shopping.priority[j],&shopping.money[j],&shopping.name[j]);
        }
        for(int j =0;j<item-1;++j){
            for(int k =0;k<item-1-j;++k){
                if(shopping.priority[k]<shopping.priority[k+1]){
                    {int temp = shopping.priority[k];
                    shopping.priority[k] = shopping.priority[k+1];
                    shopping.priority[k+1] =temp;
                    }{int temp = shopping.money[k];
                    shopping.money[k] = shopping.money[k+1];
                    shopping.money[k+1] =temp;
                    }{char temp[11];
                    strcpy(temp,shopping.name[k]);
                    strcpy(shopping.name[k],shopping.name[k+1]);
                    strcpy(shopping.name[k+1],temp);  
                    }
                }    
            }
        }
        int sum =0;
        int n=0;
        char temp[11][11];
        for(int q = 0;q<item;q++){
            if(pocket-shopping.money[q]>=0){
                sum +=shopping.money[q];
                pocket -= shopping.money[q];
                strcpy(temp[n],(tolower(shopping.name[q])));
                n++;
            }
        }
        for(int q =0;q<n;++q){
            for(int w =0;w<n-q-1;++w){
                if(strcmp(tolower(temp[w]),tolower(temp[w+1]))==1){
                    char temp1[11];
                    strcpy(temp1,temp[w]);
                    strcpy(temp[w],temp[w+1]);
                    strcpy(temp[w+1],temp1);
                }
            }
        }
        printf("%d",sum);
        for(int q =0;q<n;q++)printf(" %s",temp[q]);
        printf("\n");
        
    }
}
