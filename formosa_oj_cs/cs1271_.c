#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Student{
    int number;
    int grade;
    char name[15];
    struct Student* next;
};
typedef struct Student student;
student* creat(student *tail);
void print(student **head,int printtype,int cmptype,int ccp,int num);
int cpp(char *string);
int type(char *string);
int editing(char *string);
void editions(student **head,char *newname,int cmptype,int ccp,char *string);
void edition(student **head,int a,int b,int num,int cmptype,int ccp,char *string);
void edits(student **head,char *string);
void edit(student **head,int a,int b,int num,char *string);
void update(student **head,char *string);
void kills(student **head,int deletetype,int ccp,char *string);
void kill(student **head,int deletetype,int ccp,int num);
void delete(student **head,char *string);
void selects(student **head,char *string);
void output(student **head);
void printstring(student **head,int printtype,int cmptype,char *string);
void printout(student *ptr,int printtype);
int main(){
    int t;scanf("%d",&t);
    student *head = malloc(sizeof(student));
    student *tail = head;
    scanf("%d %d %s",&head->number,&head->grade,head->name);
    for(int i =1;i<t;i++){
        tail = creat(tail);
    }
    /*student *ptr = head;
    while(ptr!=NULL){
        printf("%d",ptr->number);
        ptr = ptr->next;
    }*/
    int k;scanf("%d",&k);
    getchar();
    for(int i =0;i<k;i++){
        output(&head);
    }
}
student* creat(student *tail){
    student *new = malloc(sizeof(student));
    scanf("%d %d %s",&new->number,&new->grade,new->name);
    tail->next = new;
    new->next =NULL;
    return new;   
}
void output(student **head){
    char string[105];gets(string);
    char *p = strtok(string," ");
    if(strcmp(p,"select")==0){
        selects(head,p);
    }else if(strcmp(p,"delete")==0){
        delete(head,p);
    }else if(strcmp(p,"update")==0){
        update(head,p);
    }
}
void selects(student **head,char *string){
    string = strtok(NULL," ");
    int printtype = type(string);
    string = strtok(NULL," ");
    string = strtok(NULL," ");
    int cmptype = type(string);
    string = strtok(NULL," ");
    int ccp = cpp(string);
    string = strtok(NULL," ");
    if(cmptype==1||cmptype==2){
        int num = atoi(string);
        print(head,printtype,cmptype,ccp,num);
    }else if(cmptype==3){
        printstring(head,printtype,cmptype,string);
    }
}
void delete(student **head,char *string){
    string =strtok(NULL," ");
    string =strtok(NULL," ");   
    int deletetype = type(string);
    string = strtok(NULL," ");
    int ccp = cpp(string);
    string = strtok(NULL," ");
    if(deletetype ==1||deletetype==2){
        int num = atoi(string);
        kill(head,deletetype,ccp,num);
    }else if(deletetype ==3){
        kills(head,deletetype,ccp,string);
    }
}
void kill(student **head,int deletetype,int ccp,int num){
    int flag=1;
    if(deletetype==1){
        while(1){
            if(ccp==-1){
                if((*head)->number<num){
                    *head = (*head)->next;
                    flag =0;
                    continue;
                }
            }else if(ccp==0){
                if((*head)->number==num){
                    *head = (*head)->next;
                    flag =0;
                    continue;
                }
            }else if(ccp==1){
                if((*head)->number>num){
                    *head = (*head)->next;
                    flag =0;
                    continue;
                }
            }
            break;
        }
        student *save = *head;
        student **prev = head;
        student *ptr =(*head)->next;
        while(ptr!=NULL){
            if(ccp==-1){
                if(ptr->number<num){
                    (*prev)->next = ptr->next;
                    ptr = (*prev)->next;
                    flag =0;
                    continue;
                }
            }else if(ccp==0){
                if(ptr->number==num){
                    (*prev)->next = ptr->next;
                    ptr = (*prev)->next;
                    flag =0;
                    continue;
                }
            }else if(ccp==1){
                if(ptr->number>num){
                    (*prev)->next = ptr->next;
                    ptr = (*prev)->next;
                    flag =0;
                    continue;
                }
            }
            *prev = ptr;
            ptr = (*prev)->next;
        }
        *head = save;
    }else if(deletetype==2){
        while(1){
            if(ccp==-1){
                if((*head)->grade<num){
                    *head = (*head)->next;
                    flag =0;
                    continue;
                }
            }else if(ccp==0){
                if((*head)->grade==num){
                    *head = (*head)->next;
                    flag =0;
                    continue;
                }
            }else if(ccp==1){
                if((*head)->grade>num){
                    *head = (*head)->next;
                    flag =0;
                    continue;
                }
            }
            break;
        }
        student *save = *head;
        student **prev = head;
        student *ptr = (*head)->next;
        while(ptr!=NULL){
            if(ccp==-1){
                if(ptr->grade<num){
                    (*prev)->next = ptr->next;
                    ptr = (*prev)->next;
                    flag =0;
                    continue;
                }
            }else if(ccp==0){
                if(ptr->grade==num){
                    (*prev)->next = ptr->next;
                    ptr = (*prev)->next;
                    flag =0;
                    continue;
                }
            }else if(ccp==1){
                if(ptr->grade>num){
                    (*prev)->next = ptr->next;
                    ptr = (*prev)->next;
                    flag =0;
                    continue;
                }
            }
            *prev = ptr;
            ptr = (*prev)->next;
        }
        *head = save;
    }
    if(flag)printf("No such data!\n");
    else printf("Delete success!\n");
}
void kills(student **head,int deletetype,int ccp,char *string){
    int flag = 1;
    while(1){
        if(strcmp((*head)->name,string)==0){
            *head =(*head)->next;
            flag =0;
            continue;
        }
        break;
    }
    student *save = *head;
    student* ptr = (*head) ->next;
    student**prev = head;
    while(ptr!=NULL){
        if(strcmp(ptr->name,string)==0){
            (*prev)->next = ptr->next;
            ptr = ptr->next;
            flag =0;
            continue;
        }
        *prev = ptr;
        ptr = ptr->next;
    }
    *head = save;
    if(flag)printf("No such data!\n");
    else printf("Delete success!\n");
}
void update(student **head,char *string){
    string = strtok(NULL," ");
    int updatetype = type(string);
    string = strtok(NULL," ");
    int edittype = editing(string);
    string = strtok(NULL," ");
    if(updatetype ==1||updatetype ==2){
        edit(head,updatetype,edittype,atoi(string),string);
    }
    else if(updatetype ==3){
        edits(head,string);
    }
}
void edit(student **head,int a,int b,int num,char *string){
    string = strtok(NULL," ");
    string = strtok(NULL," ");
    int cmptype = type(string);
    string = strtok(NULL," ");
    int ccp = cpp(string);
    string = strtok(NULL," ");
    if(cmptype!=3)edition( head,a,b,num,cmptype,ccp,string);
}
void edits(student **head,char *string){
    char *newname = string;
    string = strtok(NULL," ");
    string = strtok(NULL," ");
    int cmptype = type(string);
    string = strtok(NULL," ");
    int ccp =cpp(string);
    string = strtok(NULL," ");
    editions(head,newname,cmptype,ccp,string);
}
void edition(student **head,int a,int b,int num,int cmptype,int ccp,char *string){
    student *save = *head;
    int flag =1;
    if(cmptype ==3){
        while(*head!=NULL){
            if(strcmp((*head)->name,string)==0){
                flag =0;
                if(a==1){
                    if(b==1){
                        (*head)->number +=num;
                    }else if(b==0){
                        (*head)->number =num;
                    }else if(b==-1){
                        (*head)->number -=num;
                    }
                }else if(a==2){
                    if(b==1){
                        (*head)->grade +=num;
                    }else if(b==0){
                        (*head)->grade =num;
                    }else if(b==-1){
                        (*head)->grade -=num;
                    }
                }
            }
            *head = (*head)->next;
        }
    }else if(cmptype ==1){
        while(*head!=NULL){
            if(ccp==-1){
                if((*head)->number<atoi(string)){
                    flag =0;
                    if(a==1){
                        if(b==1){
                            (*head)->number +=num;
                        }else if(b==0){
                            (*head)->number =num;
                        }else if(b==-1){
                            (*head)->number -=num;
                        }
                    }else if(a==2){
                        if(b==1){
                            (*head)->grade +=num;
                        }else if(b==0){
                            (*head)->grade =num;
                        }else if(b==-1){
                            (*head)->grade -=num;
                        }
                    }
                }
            }else if(ccp ==0){
                if((*head)->number==atoi(string)){
                    flag =0;
                    if(a==1){
                        if(b==1){
                            (*head)->number +=num;
                        }else if(b==0){
                            (*head)->number =num;
                        }else if(b==-1){
                            (*head)->number -=num;
                        }
                    }else if(a==2){
                        if(b==1){
                            (*head)->grade +=num;
                        }else if(b==0){
                            (*head)->grade =num;
                        }else if(b==-1){
                            (*head)->grade -=num;
                        }
                    }
                }

            }else if(ccp==1){
                if((*head)->number>atoi(string)){
                    flag =0;
                    if(a==1){
                        if(b==1){
                            (*head)->number +=num;
                        }else if(b==0){
                            (*head)->number =num;
                        }else if(b==-1){
                            (*head)->number -=num;
                        }
                    }else if(a==2){
                        if(b==1){
                            (*head)->grade +=num;
                        }else if(b==0){
                            (*head)->grade =num;
                        }else if(b==-1){
                            (*head)->grade -=num;
                        }
                    }
                }

            }
            *head = (*head)->next;
        }
    }else if(cmptype ==2){
        while(*head!=NULL){
            if(ccp==-1){
                if((*head)->grade<atoi(string)){
                    flag =0;
                    if(a==1){
                        if(b==1){
                            (*head)->number +=num;
                        }else if(b==0){
                            (*head)->number =num;
                        }else if(b==-1){
                            (*head)->number -=num;
                        }
                    }else if(a==2){
                        if(b==1){
                            (*head)->grade +=num;
                        }else if(b==0){
                            (*head)->grade =num;
                        }else if(b==-1){
                            (*head)->grade -=num;
                        }
                    }
                }
            }else if(ccp ==0){
                if((*head)->grade==atoi(string)){
                    flag =0;
                    if(a==1){
                        if(b==1){
                            (*head)->number +=num;
                        }else if(b==0){
                            (*head)->number =num;
                        }else if(b==-1){
                            (*head)->number -=num;
                        }
                    }else if(a==2){
                        if(b==1){
                            (*head)->grade +=num;
                        }else if(b==0){
                            (*head)->grade =num;
                        }else if(b==-1){
                            (*head)->grade -=num;
                        }
                    }
                }

            }else if(ccp==1){
                if((*head)->grade>atoi(string)){
                    flag =0;
                    if(a==1){
                        if(b==1){
                            (*head)->number +=num;
                        }else if(b==0){
                            (*head)->number =num;
                        }else if(b==-1){
                            (*head)->number -=num;
                        }
                    }else if(a==2){
                        if(b==1){
                            (*head)->grade +=num;
                        }else if(b==0){
                            (*head)->grade =num;
                        }else if(b==-1){
                            (*head)->grade -=num;
                        }
                    }
                }

            }
            *head = (*head)->next;
        }
    }
    *head = save;
    if(flag)printf("No such data!\n");
    else printf("Update success!\n");
}
void editions(student **head,char *newname,int cmptype,int ccp,char *string){
    student *save = *head;
    int flag =1;
    while(*head!=NULL){
        if(cmptype ==1){
            if(ccp==-1){
                if((*head)->number<atoi(string)){
                    flag =0;
                    strcpy((*head)->name,newname);
                }
            }else if(ccp ==0){
                if((*head)->number=atoi(string)){
                    flag =0;
                    strcpy((*head)->name,newname);
                }
            }else if(ccp ==1){
                if((*head)->number>atoi(string)){
                    flag =0;
                    strcpy((*head)->name,newname);
                }
            }
        }else if(cmptype ==2){
            if(ccp==-1){
                if((*head)->grade<atoi(string)){
                    flag =0;
                    strcpy((*head)->name,newname);
                }
            }else if(ccp ==0){
                if((*head)->grade=atoi(string)){
                    flag =0;
                    strcpy((*head)->name,newname);
                }
            }else if(ccp ==1){
                if((*head)->grade>atoi(string)){
                    flag =0;
                    strcpy((*head)->name,newname);
                }
            }
        }else if(cmptype ==3){
            if(strcmp((*head)->name,string)==0){
                flag =0;
                strcpy((*head)->name,newname);
            }
        }
        *head = (*head)->next;
    }
    *head = save;
    if(flag)printf("No such data!\n");
    else printf("Update success!\n");
}
int editing(char *string){
    if(strcmp(string,"+=")==0){
        return 1;
    }else if(strcmp(string,"=")==0){
        return 0;
    }else if(strcmp(string,"-=")==0){
        return -1;
    }
    return 2;
}
int type(char *string){
    if(strcmp(string,"*")==0)return 0;
    if(strcmp(string,"number")==0)return 1;
    if(strcmp(string,"grade")==0)return 2;
    if(strcmp(string,"name")==0)return 3;
    return -1;
}
int cpp(char *string){
    if(strcmp(string,"<")==0)return -1;
    if(strcmp(string,"==")==0)return 0;
    if(strcmp(string,">")==0)return 1;
    return 2;
}
void print(student **head,int printtype,int cmptype,int ccp,int num){
    student *ptr = *head;
    int flag = 1;
    while(ptr!=NULL){
        if(cmptype==1){
            if(ccp==-1){
                if(ptr->number<num){
                    printout(ptr,printtype);
                    flag =0;
                }
            }else if(ccp==0){
                if(ptr->number==num){
                    printout(ptr,printtype);
                    flag =0;
                }
            }else if(ccp==1){
                if(ptr->number>num){
                    printout(ptr,printtype);
                    flag =0;
                }
            }
        }else if(cmptype==2){
            if(ccp==-1){
                if(ptr->grade<num){
                    printout(ptr,printtype);
                    flag =0;
                }
            }else if(ccp==0){
                if(ptr->grade==num){
                    printout(ptr,printtype);
                    flag =0;
                }
            }else if(ccp==1){
                if(ptr->grade>num){
                    printout(ptr,printtype);
                    flag =0;
                }
            }
        }
        ptr = ptr->next;
    }
    if(flag)printf("No such data!\n");
}
void printstring(student **head,int printtype,int cmptype,char *string){
    student *ptr = *head;
    int flag =1;
    while(ptr!=NULL){
        if(strcmp(ptr->name,string)==0){
            printout(ptr,printtype);
            flag = 0;
        }
        ptr = ptr->next;
    }
    if(flag)printf("No such data!\n");
}
void printout(student *ptr,int printtype){
    if(printtype==0){
        printf("%d %d %s\n",ptr->number,ptr->grade,ptr->name);
    }else if(printtype==1){
        printf("%d\n",ptr->number);
    }else if(printtype==2){
        printf("%d\n",ptr->grade);
    }else if(printtype==3){
        printf("%s\n",ptr->name);
    }
}
