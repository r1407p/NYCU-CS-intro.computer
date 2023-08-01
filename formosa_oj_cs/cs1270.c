#include<stdio.h>
#include<math.h>
#include<string.h>
long long int power(long long int ,long long int);
int main(){
    int t;
    scanf("%d",&t);
    char string[100000];
    getchar(); 
    long long int ans;
    for(int i =0;i<t;++i){
        gets(string);
        char *p = strtok(string," ");
        if(strcmp(p,"sum")==0){
            ans =0;
            p = strtok(NULL," ");
            while(p!=NULL){
                ans+=atoi(p);
                p = strtok(NULL," ");
            }
            ans%= 10000;
            if(ans<0)ans+=10000;
            printf("%d\n",ans);
        }
        else if(strcmp(p,"sub")==0){
            p = strtok(NULL," ");
            ans = atoi(p);
            p = strtok(NULL," ");
            while(p!=NULL){
                ans-=atoi(p);
                p = strtok(NULL," ");
            }
            ans%= 10000;
            if(ans<0)ans+=10000;
            printf("%d\n",ans);
        }
        else if(strcmp(p,"pow")==0){
            p = strtok(NULL," ");
            ans = atoi(p);
            p = strtok(NULL," ");
            while(p!=NULL){
                ans =power(ans,atoi(p));
                p = strtok(NULL," ");
                ans%= 10000;
                if(ans<0)ans+=10000;
            }
            printf("%d\n",ans);
        }
    }
}
long long int power(long long int a,long long int b){
    a%=10000;
    long long int temp=1;
    while(b!=0){
        if(b%2)temp*=a;
        b/=2;
        a*=a;
        a%=10000;
        temp%=10000;
    }
    return temp;
}