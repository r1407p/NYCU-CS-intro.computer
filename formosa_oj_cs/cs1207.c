#include<stdio.h>
int min(int,int);
int max(int,int);
int main(){
    int temp;scanf("%d",&temp);
    for(int i =0;i<temp;++i){
        int t;scanf("%d",&t);
        int sum =0;
        int arr[131073][100]={{0}};
        for(int j = 0;j<t;++j){
            int x1,y1,x2,y2;scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1+=65536;
            y1+=65536;
            x2+=65536;
            y2+=65536;
            for(int i =x1;i<x2;++i){
                int y =0;
                int flag =1;
                while(flag){
                    if(arr[i][y]==0){
                        arr[i][y]=y1;
                        arr[i][y+1]=y2;
                        flag =0;
                    }
                    else{
                        if(y1>=arr[i][y]&&y1<=arr[i][y+1]){
                            arr[i][y+1]=min(y2,arr[i][y+1]);
                            flag = 0;
                        }
                        else if(y2>=arr[i][y]&&y2<=arr[i][y+1]){
                            arr[i][y]=max(y1,arr[i][y]);
                            flag = 0;
                        }
                        else if(y1<arr[i][y]&&y2>arr[i][y+2]){
                            arr[i][y]=y1;
                            arr[i][y+1]=y2;
                            flag = 0;
                        }
                        else{
                            y+=2;
                        }
                    }

                    
                }
            }
        }
        for(int j =0;j<131073;++j){
            int n =0;
            if(arr[j][n]!=0){
                sum+=arr[j][n+1]-arr[j][n];
                n+=2;
            }
        }
        printf("%d\n",sum);
    }
}


int min(int a,int b){
    if(a<b)return a;
    else return b;
}
int max(int a,int b){
    if(a>b)return a;
    return b;
}