#include<stdio.h>
#include<math.h>
int main(){
    int a,b;scanf("%d %d",&a,&b);
    int rate = pow(2,a-1);
    int size = rate*2;
    int num_1 = rate*rate;
    int num_2 = rate*size;
    for(int i=0;i<size;i++){
        if(i<rate){
            for(int j =0;j<size;++j){
                if(j<rate)printf("%d ",j+1+rate*i);
                else printf("%d ",j-rate+1+rate*i+num_1);
            }
            printf("\n");
        }
        else{
            for(int j =0;j<2*rate;++j){
                if(j<rate)printf("%d ",j+1+rate*(i-rate)+num_2);
                else printf("%d ",j-rate+1+rate*(i-rate)+num_2+num_1);
            }
            printf("\n");
        }
    }
    int row =0;
    int column=0;
    if(b<=num_1);
    else if(b<=num_2){
        column +=rate;
        b-=num_1;
    }
    else if(b<=num_1+num_2){
        row+=rate;
        b-=num_2;
    }
    else{
        column+=rate;
        row+=rate;
        b-=num_1;
        b-=num_2;
    }
    int temprow = (b-1)/rate;
    b-=temprow*rate;
    row+=(temprow+1);
    column+=b;
    printf("%d %d",row,column);
}