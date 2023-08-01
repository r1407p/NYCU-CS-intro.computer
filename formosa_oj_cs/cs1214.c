#include<stdio.h>
int map[20][20];
int a,b;
void bfs(int x,int y,int now);
int target(int x,int y);
int main(){
    scanf("%d %d",&a,&b);
    int targetx,targety;
    int startx,starty;
    for(int i =0;i<a;++i){
        for(int j =0;j<b;++j){
            scanf("%d",&map[i][j]);
            if(map[i][j]==-3){
                targetx= i;
                targety= j;
            }
            else if(map[i][j]==-2){
                startx = i;
                starty = j;
            }
        }
    }
    bfs(startx,starty,1);
    printf("%d\n",target(targetx,targety));
}
void bfs(int x,int y,int now){
    if(x-1>=0&&map[x-1][y]!=-1){
        if(map[x-1][y]==0||map[x-1][y]>now){
            map[x-1][y]=now;
            bfs(x-1,y,now+1);
        }
    }
    if(x+1<a&&map[x+1][y]!=-1){
        if(map[x+1][y]==0||map[x+1][y]>now){
            map[x+1][y]=now;
            bfs(x+1,y,now+1);
        }
    }
    if(y-1>=0&&map[x][y-1]!=-1){
        if(map[x][y-1]==0||map[x][y-1]>now){
            map[x][y-1]=now;
            bfs(x,y-1,now+1);
        }
    }
    if(y+1<b&&map[x][y+1]!=-1){
        if(map[x][y+1]==0||map[x][y+1]>now){
            map[x][y+1]=now;
            bfs(x,y+1,now+1);
        }
    }
}
int target(int x,int y){
    int min = 9999999;
    if(x-1>=0){
        if(map[x-1][y]!= -1){
            if(map[x-1][y]<min)min = map[x-1][y];
        }
    }
    if(x+1<a){
        if(map[x+1][y]!=-1){
            if(map[x+1][y]<min)min = map[x+1][y];
        }
    }
    if(y+1<b){
        if(map[x][y+1]!= -1){
            if(map[x][y+1]<min)min = map[x][y+1];
        }
    }
    if(y-1>=0){
        if(map[x][y-1]!=-1){
            if(map[x][y-1]<min)min = map[x][y-1];
        }
    }
    return min+1;
}
