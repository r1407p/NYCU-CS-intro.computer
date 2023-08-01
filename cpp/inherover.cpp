#include<iostream>
using namespace std;
class shape{
public:
    shape(){
        cout <<"s.no"<<endl;
    };
    shape(double area){
        this->area =area;
        cout <<"s.1"<<endl;
    }
    virtual void printout(){
        cout <<"shape"<<endl;
    }
    double area;
protected:
    int pro1;
private:
    int pri1;
};
class circle: public shape{
public:
    void printout() override{
        cout <<"circle"<<endl;
    }
    circle(){
        cout << "c.no"<<endl;
    }
    circle(double area):shape(area){
        cout << "c.1"<<endl;
    }
};
class rec: public shape{
public:
    void printout(){
        cout <<"rec"<<endl;
    }
    void call(){
        cout << "rec.call"<<endl;
    }
    rec(){
        cout << "r.no"<<endl;
    }
    rec(double area){
        this->area = area;
        cout << "r.1"<<endl;
    }
};
int main(){
    shape a(10);
    //a.printout();
    circle b(10);
    b.printout();
    rec c(20);
    c.printout();
    cout << "++++++++++++++++++"<<endl;
    shape *aa,*bb,*cc;
    aa = new shape;
    bb = new circle;
    cc = new rec;

    aa->printout();
    bb->printout();
    cc->printout();
    circle *dd;
    dd = new circle;
    dd->printout();
}
