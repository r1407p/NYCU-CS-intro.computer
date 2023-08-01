#include<iostream>
#include<vector>
#include<string>
using namespace std;
class student{
    public:
        string name;
        int number;
        int score;
        student();
        //student(int number,string name,int score);
      //  student(int number,string name);
};/*
student::student(int number,string name,int score){
    this->name = name;
    this->number = number;
    this->score = score;
}
student::student(int number,string name){
    this->name = name;
    this->number = number;
    this->score =0;
}*/
int main(){
    student a;
    a.number = 100;
    a.name = "soifjw";
    a.score = 98;
    cout<<a.number<<endl;
    cout<<a.name<<endl;
    cout<<a.score<<endl;
    a.number = 0;
    a.name = "rrrrr";
    a.score = 100;
    cout<<"hello world"<< endl;
    cout<<a.number<<endl;
    cout<<a.name<<endl;
    cout<<a.score<<endl;
    return 0;
}
