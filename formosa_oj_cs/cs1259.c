#include<stdio.h>
int main(){
    int vertex,edge;scanf("%d %d",&vertex,&edge);
    int map[105][105]={0};
    int node[105]={0};
    int queue[1000000];
    int head = 0,tail=1;
    int current=1;
    int turn=0;
    for(int i =0;i<edge;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b]=1,map[b][a]=1;
    }//complete the road matrix
    int start,target;scanf("%d %d",&start,&target);
    queue[0] = start;//set the first detecting
    while(tail>head){
		if(head==current){
            current = tail;
            turn++;
        }
        if(queue[head]==target){//find the target;
            printf("%d",turn);
            return 0;
        }
        if(node[queue[head]]==1){//if the node has walked then skip
            head++;
            continue;
        }
        node[queue[head]]=1;//set the nod has been walked
        for(int i=0;i<vertex;i++){
            if(map[queue[head]][i]==1){//if the road is valid
                queue[tail]=i;
                tail++;
            }
        }
        head++;
    }
    printf("Oops");
}
/*while(tail>head){
        if(queue[head]==target){//find the target;
            printf("%d",turn);
            return 0;
        }
        if(node[queue[head]]==1){//if the node has walked then skip
            head++;
            continue;
        }
        node[queue[head]]=1;//set the nod has been walked
        for(int i=0;i<vertex;i++){
            if(map[queue[head]][i]==1){//if the road is valid
                queue[tail]=i;
                tail++;
            }
        }
        head++;
        if(head==current){
            current = tail;
            turn++;
        }
    }*/