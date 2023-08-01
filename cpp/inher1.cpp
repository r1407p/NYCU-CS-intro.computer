#include<iostream>
using namespace std;
class T1{
public:
    T1(){cout<<"T1"<<endl;}
    ~T1(){{cout<<"`~T1"<<endl;}}
    int getpro1(){cout <<"getT1pro"<<endl;return pro1;}
    int getpri1(){cout <<"getT1pri"<<endl;return pri1;}
    void setpro1(int pro1){cout <<"setT1pro"<<endl;this->pro1 = pro1;};
    void setpri1(int pri1){cout <<"setT1pri"<<endl;this->pri1 = pri1;};
    int pub1;
protected:
    int pro1;
private:
    int pri1;
};
class T2:public T1{
public:
    T2(){cout<<"T2"<<endl;}
    ~T2(){cout<<"`~T2"<<endl;}
    int getpro2(){cout <<"getT2pro"<<endl;return pro2;}
    int getpri2(){cout <<"getT2pri"<<endl;return pri2;}
    void setpro2(int pro2){cout <<"setT2pro"<<endl;this->pro2 = pro2;};
    void setpri2(int pri2){cout <<"setT2pri"<<endl;this->pri2 = pri2;};
    int pub2;
protected:
    int pro2;
private:
    int pri2;

};
class T3:protected T2{
public:
    T3(){cout <<"T3"<<endl;}
    ~T3(){cout<<"`~T3"<<endl;}
    int pub3;
    int getpro1(){return pro3;}
    int getpri1(){return pri3;}
    void setpro1(int pro3){this->pro3 = pro3;};
    void setpri1(int pri3){this->pri3 = pri3;};
protected:
    int pro3;
private:
    int pri3;
};

int main(){
    T1 t11;
    T2 t22;
    T3 t33;
    t11.pub1 = 10;
    t11.setpro1(20);
    t11.setpri1(30);
    cout << t11.pub1<<'\t'<< t11.getpro1()<<'\t'<<t11.getpri1()<<endl;
//    t22.pub1 = 110;//if protected this will not used by main
//    t22.setpro1(120);//if protected this will not used by main
//    t22.setpri1(130);//if protected this will not used by main
    t22.pub2=  210;
    t22.setpro2(220);
    t22.setpri2(230);
//   cout << t22.pub1<<'\t'<< t22.getpro1()<<'\t'<<t22.getpri1()<<endl;//if protected this will not used by main
    cout << t22.pub2<<'\t'<< t22.getpro2()<<'\t'<<t22.getpri2()<<endl;
    T1 copy = t11;
    cout << "~~~~~~~~~~~"<<endl;
    cout << copy.pub1<<'\t'<< copy.getpro1()<<'\t'<<copy.getpri1()<<endl;



}