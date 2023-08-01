
#include <iostream>
#include <typeinfo>
using namespace std;

template<class T ,int ccc>
class a{
public:
    a(){
        cout << "aaaaaa:"<< ccc <<typeid(ccc).name()<<endl;
    }
};
class b:a<double,100>{
public:
    b(){
        cout << "bbbbb:"<<endl;
    }
};
template<class G,int n>
class c:a<G,n-1>{
public:
    c(){
        cout <<"cccccccc:"<<n<<typeid(n).name()<<endl;
    }
};

int main(){
    a<int,12> qw;
    b we;
    c <float,22>er;
}