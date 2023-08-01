#include<iostream>
#include<ctime>
using namespace std;
int XXX();
int main(){
    int a=0,b=0,c=0,d=0;
    for(int i =0;i<100;i++){
        int temp = XXX();
        cout <<temp<<endl;
        if(temp==1)a++;
        else if(temp==2)b++;
        else if(temp==3)c++;
        else if(temp==4)d++;
    }
    cout <<"================"<<endl;
    //cout << a <<'\t'<< b <<'\t'<< c <<'\t'<< d <<endl;
    cout <<"1:"<<a<<endl;
    cout <<"2:"<<b<<endl;
    cout <<"3:"<<c<<endl;
    cout <<"4:"<<d<<endl;

}

int XXX(){
    int temp;
    temp = rand()%10;
    if(temp==0)return 1;
    if(temp<=2)return 2;
    if(temp<=5)return 3;
    return 4;
}