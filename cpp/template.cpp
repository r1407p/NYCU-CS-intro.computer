#include <iostream>
#include <typeinfo>
using namespace std;
/////////
template <typename T>
T sss(const T& a,const T& b){
    if(a>b)return a;
    return b;
}
///////////////
template<class T,int Size,typename R> //帶一個參數
void print(T t,R q)
{
 cout<<t<<":"<<Size<<endl <<"R:"<<q<<endl;
 }
/////////
template<class T>
class test{
public:
    test(T num){
        this->num = num;
    }
    T num;
    void print(){
        cout << typeid(num).name()<<endl;
    }
};
int main(){
    int a = 1;
    int b= 10;
    long long a1 = 234325;
    long long b1 = 234134;
    double c = 5.5;
    double d = 3.5;
    float e = 3.4;
    float f = 5.5e6;
    try{
        cout << typeid(sss(e,f)).name();
        cout <<endl;
    }catch(int error){
        cout << "error"<<endl;
    }
    int data=100;
    print<int,32767,double>(data,c);

    test<long long> doit(4);
    doit.print();
    cout << endl;

    test<double> * ttt = new test<double>(54.5);
    cout <<ttt->num<<endl;
    ttt->print();
    cout << endl;

    
}
