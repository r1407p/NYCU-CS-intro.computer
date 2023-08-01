#include<stdio.h>
#include<math.h>
int arr[513][513];
int n=1;
int x,y,find;
void construct(int ,int ,int);
int main(){
    int r;scanf("%d %d",&r,&find);
    construct(r,0,0);
    int big = pow(2,r);
    for(int i =0;i<big;i++){
        for(int j =0;j<big;j++)printf("%d ",arr[i][j]);
        printf("\n");
    }
    printf("%d %d",x+1,y+1);
}
void construct(int size,int row ,int column){
    if(size ==1){
        if(n==find){x = row;y=column;}
        arr[row][column]=n++;
        if(n==find){x = row;y=column+1;}
        arr[row][column+1]=n++;
        if(n==find){x = row+1;y=column;}
        arr[row+1][column]=n++;
        if(n==find){x = row+1;y=column+1;}
        arr[row+1][column+1]=n++;
    }
    else{
        int now = size-1;
        int temp_length = pow(2,now);
        construct(now,row,column);
        construct(now,row,column+temp_length);
        construct(now,row+temp_length,column);
        construct(now,row+temp_length,column+temp_length);
    }

}
