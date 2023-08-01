#include<iostream>
using namespace std;

class father{
public:
    father(int a,int b,int c);
    father();
    int get_a();
    int get_b();
    int get_c();
    void set_a(int a);
    void set_b(int b);
    void set_c(int c);
    int a;
protected:
    int b;
private:
    int c;
};
class son:public father{
    /*son(int a,int b,int c){
        this->a = a;
        this->b = b;
        //this->c = c;
        set_c(c);
    }*/
};
int main(){
    father fff(1,2,3);
    cout <<fff.a<<endl;
    //cout <<fff.b;
    cout <<fff.get_b()<<endl;
    //cout <<fff.c;
    cout <<fff.get_c()<<endl;
    son sss;
    sss.a = 4;
    sss.set_b(5);
    sss.set_c(6);
    cout <<sss.a<<endl;
    cout <<sss.get_b()<<endl;
    //cout <<fff.c;
    cout <<sss.get_c()<<endl;


}






father::father(int a,int b,int c){
    this->a = a;
    this->b = b;
    this->c = c;
    cout <<"father construct with a,b,c"<<endl;
}
father::father(){
    cout <<"father construct"<<endl;
}
int father::get_a(){return a;}
int father::get_b(){return b;}
int father::get_c(){return c;}
void father::set_a(int a){
    this->a = a;
}
void father::set_b(int b){
    this->b = b;
}
void father::set_c(int c){
    this->c = c;
}