#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<fstream>
class complex{
public:
    complex(double a,double b);
    complex() ;
    complex(double a) ;
    complex operator+(const complex obj);
    complex operator-(const complex obj);


    friend ostream& operator << (ostream& out,const complex& obj);
private:
    double a;
    double b;
};

int main(){
    cout << "hello"<<endl;
    complex a;
    complex b(1);
    complex c(3,4);
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
}







complex::complex(double a,double b){
    this->a = a;
    this->b = b;
}
complex::complex():complex(0,0){}
complex::complex(double a):complex(a,0){}


ostream& operator << (ostream& out,const complex& obj){
    out <<"the complex number is: "<<   obj.a;
    if(obj.b<0)out <<obj.b;
    else out <<" + "<<obj.b;
    out << 'i';
    return out;
}
complex complex::operator+(const complex obj){

}