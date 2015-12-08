#include<iostream>
#include<string>
#include<time.h>
#include"bigNumber.h"
#include"node.h"
#include"list.h"
using namespace std;

int main()
{

    bigNumber a,b,c;
    cout<<"请输入a"<<endl;
    cin>>a;
    cout<<"a="<<a<<endl;
    cout<<"输入b"<<endl;
    cin>>b;
    cout<<"b="<<b<<endl;

    c=a%b;
    cout<<"c=a%"<<"b="<<c<<endl;

    cout<<"a转化为二进制:"<<endl;
    a.binary();

    a.input_Binary();

    c=a+b;
    cout<<"c=a+b="<<c<<endl;
    c=a-b;
    cout<<"c=a-b="<<c<<endl;
    c=a*b;
    cout<<"c=a*b="<<c<<endl;
    c=c*c;
    cout<<"c=c*c="<<c<<endl;
    c=a/b;
    cout<<"c=a/b="<<c<<endl;
    clock_t start,end;
    start=clock();
    c=a^b;
    end=clock();
    cout<<"用时"<<end-start<<"×10^(-6)秒"<<endl;
    cout<<"c=(a^b)="<<c<<endl;
    return 0;
}
