#include<stdio.h>
#include<string.h>
struct ID{
    char string[21];
    int num;
};
struct ID id[21];
int isvalid(char string[]);
int main(){
    int pivot = 0;
    for(int l =0;l<10;l++){
        char temp[21];
        gets(temp);
        int flag = 0;
        for(int i =0;i<pivot;i++){
            if(strcmp(temp,id[i].string)==0){
                flag =1,id[i].num++;
                break;
            }
        }
        if(flag)continue;
        else{
            strcpy(id[pivot].string,temp);
            id[pivot].num =1;
            pivot++;
        }
    }
    for(int i =0;i<pivot;i++){
            char result;
            if(isvalid(id[i].string))result = 'T';
            else result = 'F';
            printf("%s (%c, %d)\n",id[i].string,result,id[i].num);
    }
}
int isvalid(char string[]){
    if(string[0]<'A')return 0;
    if(string[0]>'Z')return 0;
    if(string[1]!='1'&&string[1]!='2')return 0;
    int sum = 0;
    int arr[26] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    int temp = arr[string[0]-'A'];
    //printf("%d ",temp);
    sum+=temp/10;
    temp%=10;
    sum+=temp*9;
   // printf("%d ",sum);
    for(int i =1;i<9;i++){
        sum +=(9-i)*(string[i]-'0');
    }
    sum+=(string[9]-'0');
    //printf("%d\n",sum);
    if(sum%10==0)return 1;
    return 0;
}