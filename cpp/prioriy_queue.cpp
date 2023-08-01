#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> test;
    test.push(5);
    test.push(3);
    test.push(6);
    test.push(9);
    test.push(0);
    for(int i =0;i<5;i++){
        cout << test.top()<<endl;
        test.pop();
    }
    cout << "+++++++++++++\n";
    priority_queue<int, vector<int>, greater<int> > test2;
    test2.push(5);
    test2.push(3);
    test2.push(6);
    test2.push(9);
    test2.push(0);
    for(int i =0;i<5;i++){
        cout << test2.top()<<endl;
        test2.pop();
    }

}