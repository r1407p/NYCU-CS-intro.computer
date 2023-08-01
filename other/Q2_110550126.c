#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct dictionary{
    char name[111];
    int size;
    int pivot;
    struct dictionary *(path[500]);
};
typedef struct dictionary dic;
dic root = {"",0,0};
dic *creat(char nam[],int siz);
void output(dic current,char temp[]);
void input(dic *current,char temp[],int siz);
int main(){
    int t;scanf("%d",&t);
    for(int i =0;i<t;i++){
        char temp[111];int siz;
        scanf("%s %d",temp,&siz);
        input(&root,temp+1,siz);
       // printf("%d",root.pivot);
    }
   /* for(int i =0;i<root.pivot;i++){
        printf("%s\n",root.path[i]->name);
        for(int j =0;j<root.path[i]->pivot;j++){
            printf("    %s\n",root.path[i]->path[j]->name);
        }
    }*/
    int k;scanf("%d",&k);
    for(int i =0;i<k;i++){
        char temp[111];
        scanf("%s",temp);
        output(root,temp);
    }
}
void input(dic *current,char temp[],int siz){
    int i =0;while(temp[i]!='/'&&temp[i]!='\0')i++;
    char string[111];
    strncpy(string,temp,i);
    string[i]='\0';
    //printf("%s\n",string);
    for(int j =0;j<current->pivot;j++){
        if(strcmp(current->path[j]->name,string)==0){
            return input(current->path[j],temp+i+1,siz);
        }
    }
    if(temp[i]=='\0'){
        current->path[current->pivot] = creat(string,siz);
        current->pivot++;
        return;
    }else{
        current->path[current->pivot] = creat(string,-1);
        current->pivot++;
        return input(current->path[current->pivot-1],temp+i+1,siz);
    }
}
dic *creat(char nam[],int siz){
    dic *new = (dic *)malloc(sizeof(dic));
    strcpy(new->name,nam);
    new->size = siz;
    new->pivot = 0;
    return new;
}
void output(dic current,char temp[]){
    int n =0;while(temp[n]!='/'&&temp[n]!='\0')n++;
    char string[111];
    strncpy(string,temp,n);
    string[n]='\0';
    //printf("%s\n",string);
    int path=0;
    int file=0;
    int siz =0;
    if(temp[n]=='\0'||temp[n+1]=='\0'){
        if(strcmp(current.name,string)==0){
            for(int i =0;i<current.pivot;i++){
                if(current.path[i]->size!=-1){
                    siz+=current.path[i]->size;
                    file++;
                }else{
                    path++;
                }
            }
            if(path==0&&file==0)printf("invalid path\n");
            else printf("%d %d %d\n",path,file,siz);
            return;
        }
        else{
            printf("invalid path\n");
            return;
        }
    }else{
        int k =0;while(temp[n+k+1]!='/'&&temp[n+k+1]!='\0')k++;
        char string2[111];
        strncpy(string2,temp+n+1,k);
        string2[k]='\0';
       // printf("%s\n",string2);
        for(int i =0;i<current.pivot;i++){
            //printf("%s\n",current.path[i]->name);
            if(strcmp(current.path[i]->name,string2)==0){    
                return output(*current.path[i],temp+n+1);
            }
        }
        printf("invalid path\n");
        return;
    }
}