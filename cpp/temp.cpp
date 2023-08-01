#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//int s =0;

class X{
    public:
    int x;
    string n;
    X(){n = "z";x = 0;}
    X(string n,int x){
        this->n = n;
        this->x = x;
    }
    X(const X &a){
        this->n = "copy of \t"+(&a)->n;
        this->x = a.x;
    }
    ~X(){cout <<n <<endl;}
    X& operator = (const X &a){
        this->n = "assign\t"+a.n+"\tto\t"+this->n;
        return *this;
    }
    void p() const{
        cout <<"X:\t"<<n<<"\t"<<x<<endl;
    }
};
void q03_1(X x){
    x.p();
}
void q03_2(const X &x){
    x.p();
}
int main(){
    cout << (unsigned char)
}



