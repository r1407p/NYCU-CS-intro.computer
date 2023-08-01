#include<stdio.h>
int map[21][21];
int bfs[441][2];
int front=0;
int last=1;
int temp = 1;
int current=1;
int a,b;
int targetx,targety;
void extend();
int main(){
    scanf("%d %d",&a,&b);
    for(int i =0;i<a;++i){
        for(int j =0;j<b;++j){
            scanf("%d",&map[i][j]);
            if(map[i][j]==-3){
                targetx = i;
                targety =j;
            }
            if(map[i][j]==-2){
                bfs[0][0] = i;
                bfs[0][1] = j;
            }
        }
    }
    extend();
    for(int i=0;i<a;i++){
        for(int j = 0;j<b;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("%d",current);
}
void extend(){
    while(1){
        while(temp>front){
            int x = bfs[front][0];
            int y = bfs[front][1];
            if(x>0&&map[x-1][y]==0){
                bfs[last][0]=x-1;
                bfs[last][1]=y;
                last++;
                map[x-1][y]=current;
                printf("%d\n",map[x-1][y]);
            }else if(map[x-1][y]==-3)return;
            if(x<a-1&&map[x+1][y]==0){
                bfs[last][0]=x+1;
                bfs[last][1]=y;
                last++;
                map[x+1][y]=current;
            }else if(map[x+1][y]==-3)return;
            if(y>0&&map[x][y-1]==0){
                bfs[last][0]=x;
                bfs[last][1]=y-1;
                last++;
                map[x][y-1]=current;
            }else if(map[x][y-1]==-3)return;
            if(y<b-1&&map[x][y+1]==0){
                bfs[last][0]=x;
                bfs[last][1]=y+1;
                last++;
                map[x][y+1]=current;
            }else if(map[x][y+1]==-3)return;
            front++;
        }
        temp = last;
        current++;
    }
}
