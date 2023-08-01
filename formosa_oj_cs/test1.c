#include<stdio.h>
int mn(int,int);
int mx(int,int);
int hour[4]={8,4,2,1};
int min[6]={32,16,8,4,2,1};
int temphour[4]={0};
int sum =0;
int light;
void hours(int now ,int target,int point,int time);
void mins(int now,int target,int point,int time,int hour);
int main(){
    int t ;scanf("%d",&t);
    for(int i =0;i<t;++i){
        sum =0;
        scanf("%d",&light);
        int temp =light-6;
        for(int j =mx(temp,0) ; j<=mn(light,4);j++){
            hours(0,j,0,0);
        }
        printf("%d\n",sum);
    }
}
void hours(int now ,int target,int point,int time){
    if(now >=target){
        if(time<12){
            mins(0,light-target,0,0,time);
        }
    }
    else if(point>3)return;
    else{
        hours(now,target,point+1,time);
        hours(now+1,target,point+1,time+=hour[point]);
    }
}
void mins(int now,int target,int point,int time,int hour){
    if(now >=target){
        if(time<60){
            sum+=time;
            sum+=hour*60;
        }
    }
    else if(point>5)return;
    else{
        mins(now,target,point+1,time,hour);
        mins(now+1,target,point+1,time+=min[point],hour);
    }
}
int mn(int a,int b){
    if(a>b)return b;
    return a;
}
int mx(int a,int b){
    if(a>b)return a;
    return b;
}