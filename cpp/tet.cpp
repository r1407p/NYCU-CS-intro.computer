#include <iostream>
#include <iomanip>
#include <locale>
using namespace std; 
class A {
	public:
	void f( int y = 10) { cout << y << endl;}
};
int y = 15;
 
void fooB( ) {
	static int counter = 0;
	++counter;
	cout << counter << endl;
}
int main()
{
    int a =10;
    int *b = &a;
    cout <<a<<'\t'<<*b<<endl;
    *b = 100;
    cout <<a<<'\t'<<*b<<endl;
    int *p = NULL;
    cout << p <<endl;
    p = new int[20];
    cout << p <<endl;
    for(int i =0;i<20;i++){
        p[i] = i;
        cout <<p[i]<<endl;
    }
    p = (int*)realloc(p,sizeof(int)*30);
    for(int i =0;i<30;i++){
        p[i] = i;
        cout <<p[i]<<endl;
    }
}
