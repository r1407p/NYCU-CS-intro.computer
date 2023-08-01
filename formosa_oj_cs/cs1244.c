#include<stdio.h>
#include<string.h>

int main(){
    int t;scanf("%d",&t);
    char name[t][1010];
    for(int i =0;i<t;i++){
        scanf("%s",&name[i]);
    }
    char order[5];
    while(scanf("%s",&order)!=EOF){
        int a,b;scanf("%d %d",&a,&b);
        char temp;temp = getchar();
        if(strcmp(order,"add")==0){
            strcat(name[a],name[b]);
            puts(name[a]);
        }
        else if(strcmp(order,"sub")==0){
            int i=0; 
            while(name[a][i]!='\0'){
                if(name[a][i]==name[b][0]){
                    int k = i;
                    while(name[a][k]!='\0'){
                        name[a][k]=name[a][k+1];
                        k++;
                    }   
                }
                i++;
            }
            puts(name[a]);
        }
        else if(strcmp(order,"eq")==0){
            if(strcmp(name[a],name[b])==0)printf("same\n");
            else printf("different\n");
        }
        else printf("Oops\n");
    }
}