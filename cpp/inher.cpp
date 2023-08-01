#include<iostream>

using namespace std;
class shape{
public:
    ~shape(){cout <<"shape!!!!!!!!!"<<endl;}
    shape(){cout <<"shape"<<endl;};
    double getarea()const;
protected:
    double area=0;//
};
class rectangle:public shape{
public:
    rectangle(int a,int b);
    rectangle();
    ~rectangle(){cout <<"rectangle!!!"<<endl;};
    double getarea()const;
    double getlength()const {return length[0];}
    double getwidth()const {return length[1];}
protected:
    double length[2];
};
class circle:public shape{
public:
    circle(){cout <<"circle"<<endl;};
    ~circle(){cout <<"circle!!"<<endl;}
    double getarea()const;
    double getradius()const{return radius;}
protected:
    double radius;
};
int main(){
    rectangle(3,5);
    shape a;
    rectangle b(2,5);
    cout <<b.getarea()<<endl;
    circle c;
}
rectangle::rectangle(int a,int b){
    cout <<"rectangle"<<endl;
    length[0] = a ;
    length[1] = b ;
    area = a*b;
}
double shape::getarea()const{
    return area;
}
double rectangle::getarea()const{
    return area;
}

