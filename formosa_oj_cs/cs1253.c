#include<stdio.h>
#include<string.h>
void print(const char a[],const char b[],int A,int B);
char move(char a,int move,int flag);
int main(){
    int  t;scanf("%d",&t);
    for(int i =0;i<t;i++){
        int a,b;scanf("%d %d",&a,&b);
        char word[11];scanf("%s",word);
        getchar();
        char string[1000];
        gets(string);
        char divided[2]=" ";
        char *temp = strtok(string,divided);
        while(temp!=NULL){
            if(strcmp(temp,"end")==0){
                printf("\n");
                break;
            }
            print(temp,word,a,b);
            temp = strtok(NULL, divided);
        }
    }
}
void print(const char a[],const char b[],int A,int B){
    int length = strlen(a);
    int flag = strcmp(a,b);
    if(flag ==0)printf("%s ",a);
    else if(flag >0){
        for(int i =0;i<length;i++){
            printf("%c",move(a[i],B,-1));
        }
        printf(" ");
    }else{
        for(int i =0;i<length;i++){
            printf("%c",move(a[i],A,+1));
        }
        printf(" ");
    }
}
char move(char a,int move,int flag){
    if(flag>0){
        if(a+move<='z')return a+move;
        return (char)(a+move-26);
    }else{
        if(a-move>='a')return a-move;
        return (char)(a-move+26);
    }
}