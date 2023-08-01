#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int quotient(int n1, int n2);
int main() {
  stack<int> temp;
  temp.push(0);
  cout << temp.top();
  temp.push(1);
  cout << temp.top();

  temp.pop();

  
  cout << temp.top();


}