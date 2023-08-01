#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void output();
struct dictionary{
    char name[111];
    int size;
    struct dictionary *down;
    struct dictionary *same;
};
typedef struct dictionary dic;
dic root = {"",0};
int main(){
    int t;scanf("%d",&t);
    for(int i =0;i<t;i++){
        char temp[111];int siz;
        scanf("%s %d",temp,&siz);
        input(&root,temp+1,siz);
    }    
    int k;scanf("%d",&k);
    for(int i =0;i<k;i++){
        char temp[111];
        scanf("%s",temp);
        output(root,temp);
    }
}
dic *creat(char nam[],int siz){
    dic *new = (dic *)malloc(sizeof(dic));
    strcpy(new->name,nam);
    new->size = siz;
    return new;
}
void input(dic *current,char temp[] ,int size){
    int i =0;
    while(temp[i]!='/'&&temp[i]!='\0')i++;
    char string[111];
    strncpy(string,temp,i);
    if(!current->down){
        if(temp[i]=='\0') {
            current->down = creat(string,size);
            return;
        }
        else {
            current->down = creat(string,0);
            return input(current->down,temp+i+1,size);
        }
    }
    else{
        dic *find = current->down;
        while(find){
            if(strcmp(find->name,string==0))break;
        }
        if(find){
            
        }else{

        }
    }
}
void find(dic *current,char temp[]){
    int i =0;
    while(temp[i]!='/'&&temp[i]!='\0')i++;
    char string[111];
    strncpy(string,temp,i);
    while(current){
        if(strcmp(current->name,string)==0){
            return output(*current,temp);
        }
        else{
            current = current->same;
        }
    }
}
void output(dic current,char temp[]){
    int i =0;
    while(temp[i]!='/'&&temp[i]!='\0')i++;
    char string[111];
    strncpy(string,temp,i);
    if(strcmp(current.name,string)==0){
        if(temp[i]=='\0'||temp[i+1]=='\0'){
            printout(current.down);
            return;
        }else{
            find(current.down,temp+i+1);
            return;
        }
    }else{
        printf("invalid path\n");
    }
}
void printout(dic* now){
    dic* current=now; 
    int path =0;
    int file =0;
    int siz =0;
    while(current){
        if(current->size!=0){
            file++;
            siz+=current->size;
        }else{
            path++;
        }
        current = current->same;
    }
    printf("%d %d %d\n",path,file,siz);
    return;
}