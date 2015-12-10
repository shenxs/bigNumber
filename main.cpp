#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include"bigNumber.h"
#include"node.h"
#include"list.h"
using namespace std;

int main()
{

    ifstream input("input.dat");
    ofstream output("output.dat");
    bigNumber a,b,c,n;
    cout<<"读入a"<<endl;
    input>>a;
    cout<<"a="<<a<<endl;
    cout<<"读入b"<<endl;
    input>>b;
    cout<<"b="<<b<<endl;
    cout<<"读入n"<<endl;
    input>>n;
    cout<<"n="<<n<<endl;

    clock_t start,end;

    start=clock();
    c=a+b;
    cout<<"c=a+b="<<c<<endl;
    c=c%n;
    cout<<"c=(a+b)%n"<<c<<endl;
    end=clock();
    cout<<"用时:"<<end-start<<"*10^(-6)秒"<<endl;
    cout<<endl;
    start=clock();
    c=a-b;
    cout<<"c=a-b="<<c<<endl;
    c=c%n;
    cout<<"c=(a-b)%n="<<c<<endl;
    end=clock();
    cout<<"用时:"<<end-start<<"*10^(-6)秒"<<endl;
    cout<<endl;
    start=clock();
    c=a*b;
    cout<<"c=a*b="<<c<<endl;
    c=c%n;
    cout<<"c=(a*b)%n="<<c<<endl;
    end=clock();
    cout<<"用时:"<<end-start<<"*10^(-6)秒"<<endl;
    cout<<endl;
    start=clock();
    c=a/b;
    cout<<"c=a/b"<<c<<endl;
    c=c%n;
    cout<<"c=(a/b)%n="<<c<<endl;
    end=clock();
    cout<<"用时:"<<end-start<<"*10^(-6)秒"<<endl;
    cout<<endl;
    start=clock();
    c=a%b;
    cout<<"c=a%"<<"b"<<c<<endl;

    end=clock();
    cout<<"用时:"<<end-start<<"*10^(-6)秒"<<endl;
    cout<<endl;

    start=clock();
    c=a.quickMod(b,n);
    end=clock();
    cout<<"c=(a^b)%n="<<c<<endl;
    cout<<"用时:"<<end-start<<"*10^(-6)秒"<<endl;
    output<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}
