#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;
class complex{
private:
    double real;
    double fake;
public:
    complex();
    complex(double real);
    complex(double real,double fake);
    ~complex(){};
    double get_real();
    double get_fake();
    bool operator != (const complex& obj);
    bool operator == (const complex& obj);
    bool operator > (const complex& obj);
    bool operator < (const complex& obj);
    bool operator >= (const complex& obj);
    bool operator <= (const complex& obj);
    complex operator+(const complex& obj);
    complex operator-(const complex& obj);
    complex operator*(const complex& obj);
    complex operator/(const complex& obj);
    complex& operator=(const complex& obj);
    complex& operator+=(const complex& obj);
    complex& operator-=(const complex& obj);
    complex& operator*=(const complex& obj);
    complex& operator/=(const complex& obj);
    friend istream& operator >>(istream& in ,complex& obj);
    friend ostream& operator <<(ostream& out ,const complex& obj);
};
double complex::get_fake(){
    return fake;
}
double complex::get_real(){
    return real;
}
complex::complex():complex(0,0){}
complex::complex(double real):complex(real,0){}
complex::complex(double real,double fake){
    this->real = real;
    this->fake = fake;
}
int main(){
    complex a(1,1);
    complex b(5,10);
    complex c(3.4,53);
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
    cout <<a+b<<endl;
    cout <<a-b<<endl;
    cout <<a*b<<endl;
    cout <<a/b<<endl;
    cout << (a>b) <<endl;
    cout << (a>=b) <<endl;
    cout << (a<b) <<endl;
    cout << (a<=b) <<endl;
    cout << (a==b) <<endl;
    cout << (a!=b) <<endl;
    c+=b+=a;
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
    a-=b-=c;
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
    cin >>a>>b>>c;
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
    a/=b/=c;
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
    a*=b*=c;
    cout <<a<<endl;
    cout <<b<<endl;
    cout <<c<<endl;
}



bool complex::operator != (const complex& obj){
    if(real!=obj.real||fake!=obj.fake)return true;
    return false;
}
bool complex::operator == (const complex& obj){
    if(real==obj.real&&fake==obj.fake)return true;
    return false;
}
bool complex::operator > (const complex& obj){
    if(real>obj.real)return true;
    else if(real==obj.real&&fake>obj.fake)return true;
    return false;
}
bool complex::operator < (const complex& obj){
    if(real<obj.real)return true;
    else if(real==obj.real&&fake<obj.fake)return true;
    return false;
}
bool complex::operator >= (const complex& obj){
    if(real>obj.real)return true;
    else if(real==obj.real&&fake>=obj.fake)return true;
    return false;
}
bool complex::operator <= (const complex& obj){
    if(real<obj.real)return true;
    else if(real==obj.real&&fake<=obj.fake)return true;
    return false;
}
complex complex::operator+(const complex& obj){
    complex temp(real+obj.real,fake+obj.fake);
    return temp;
}
complex complex::operator-(const complex& obj){
    complex temp(real-obj.real,fake-obj.fake);
    return temp;
}
complex complex::operator*(const complex& obj){
    complex temp(real*obj.real-fake*obj.fake,real*obj.fake+fake*obj.real);
    return temp;
}
complex complex::operator/(const complex& obj){
    complex temp(real/obj.real,fake/obj.fake);
    return temp;
}
complex& complex::operator=(const complex& obj){
    real = obj.real;
    fake = obj.fake;
    return *this;
}
complex& complex::operator+=(const complex& obj){
    real += obj.real;
    fake += obj.fake;
    return *this;
}
complex& complex::operator-=(const complex& obj){
    real -= obj.real;
    fake -= obj.fake;
    return *this;
}
complex& complex::operator*=(const complex& obj){
    double temp = real*obj.real-fake*obj.fake;
    double temp2 = real*obj.fake+fake*obj.real;
    real = temp;
    fake = temp2;
    return *this;
}
complex& complex::operator/=(const complex& obj){
    real /= obj.real;
    fake /= obj.fake;
    return *this;
}
istream& operator >>(istream& in ,complex& obj){
    in >>obj.real >>obj.fake;
    return in;
}
ostream& operator <<(ostream& out ,const complex& obj){
    out <<"the complex number is: "<<   obj.real;
    if(obj.fake<0)out <<obj.fake;
    else out <<" + "<<obj.fake;
    out << 'i';
    return out;
}