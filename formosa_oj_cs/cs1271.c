#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct Grade{
    int number;
    int grade;
    char name[105];
    struct Grade* next;
};
typedef struct Grade grade;
grade root ;
grade *head  = &root,*tail = &root;
void creat();
void select(char *string);
void output();
int printing(int type,int cmp,int cmptype,char * string);
int printtype(char *  string);
int cmptypes(char *string);
int printout(int type,int cmp,int cmptype,int flag);
void prints(grade* ,int );
int printing(int type,int cmp,int cmptype,char * string);
int main(){
    int t;scanf("%d",&t);
    scanf("%d %d %s",&root.number,&root.grade,root.name);
    for(int i =1;i<t;i++){
        creat();
    }
    grade *ptr = &root;
    while(ptr!=NULL){
        printf("%d %s %d\n",ptr->number,ptr->name,ptr->grade);
        ptr = ptr->next;
    }
    int k;scanf("%d",&k);
    getchar();
    for(int i =0;i<k;i++){
        output();
    }
}
void creat(){
    grade *new = malloc(sizeof(grade));
    scanf("%d %d %s",&new->number,&new->grade,new->name);
    tail->next = new;
    tail = tail->next;
    tail->next = NULL;
}
void output(){
    char *string;gets(string);
    string = strtok(string," ");
    if(strcmp(string,"select")==0){
        select(string);
    }else if(strcmp(string,"delete")==0){
        //delete(string);
    }else if(strcmp(string,"update")==0){
        //update(string);
    }
}
void select(char *string){
    string = strtok(NULL," ");
    int type = printtype(string);
    string = strtok(NULL," ");
    string = strtok(NULL," ");
    int cmp = printtype(string);
    string = strtok(NULL," ");
    int cmptype = cmptypes(string);
    string = strtok(NULL," ");
    int ok=0;
    int flag;
    switch(cmp){
        case 2:
            flag = atoi(string);
            ok = printout(type,cmp,cmptype,flag);
            break;
        case 3:
            ok = printing(type,cmp,cmptype,string);
            break;
        case 4:
            flag = atoi(string);
            ok = printout(type,cmp,cmptype,flag);
            break;
    }
    if(ok==0){
        printf("No such data!");
    }
}
int printtype(char *  string){
    if(strcmp(string,"*")==0)return 1;
    else if(strcmp(string,"number")==0)return 2;
    else if(strcmp(string,"name")==0)return 3;
    else if(strcmp(string,"grade")==0)return 4;
    else return 0;
}
int cmptypes(char *string){
    if(strcmp(string,">")==0)return 1;
    else if(strcmp(string,"==")==0)return 2;
    else if(strcmp(string,"<")==0)return 3;
    return 0;
}
int printout(int type,int cmp,int cmptype,int flag){
    int ok =0;
    grade *ptr = &root;
    if(cmp==2){
        if(cmptype==1){
            while(ptr!=NULL){
                if(ptr->number>flag){
                    prints(ptr,type);
                    ok =1;
                }
                ptr = ptr->next;
            }
        }else if(cmptype==2){
            while(ptr!=NULL){
                if(ptr->number==flag){
                    prints(ptr,type);
                    ok =1;
                }
                ptr = ptr->next;
            }
        }else if(cmptype==3){
            while(ptr!=NULL){
                if(ptr->number<flag){
                    prints(ptr,type);
                    ok =1;
                }
                ptr = ptr->next;
            }
        }
    }else if(cmp==4){
        if(cmptype==1){
            while(ptr!=NULL){
                if(ptr->grade>flag){
                    prints(ptr,type);
                    ok=1;
                }
                ptr = ptr->next;
            }
        }else if(cmptype==2){
            while(ptr!=NULL){
                if(ptr->grade==flag){
                    prints(ptr,type);
                    ok=1;
                }
                ptr = ptr->next;
            }
        }else if(cmptype==3){
            while(ptr!=NULL){
                if(ptr->grade<flag){
                    prints(ptr,type);
                    ok=1;
                }
                ptr = ptr->next;
            }
        }
    }
    return ok;
}
void prints(grade *ptr,int type){
    if(type ==1){
        printf("%d %d %s\n",ptr->number,ptr->grade,ptr->name);
    }else if(type ==2){
        printf("%d\n",ptr->number);
    }else if(type==3){
        printf("%s\n",ptr->name);
    }else if(type==4){
        printf("%d\n",ptr->grade);
    }
}
int printing(int type,int cmp,int cmptype,char * string){
    int ok =0;
    grade *ptr = &root;
    if(cmp==3){
        if(cmptype ==2){
            while(ptr!=NULL){
                if(strcmp(string,ptr->name)==0){
                    prints(ptr,type);
                    ok =1;
                }
                ptr = ptr->next;
            }
        }
    }
    return ok;
}