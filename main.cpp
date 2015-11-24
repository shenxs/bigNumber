#include<iostream>
#include<string>
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
    c=a+b;
    cout<<"c=a+b="<<a<<"+"<<b<<"="<<c<<endl;

    bigNumber e,d;
    cout<<"请输入e,d"<<endl;
    cin>>e>>d;
    cout<<"e="<<e<<endl;
    cout<<"d="<<d<<endl;
    if(e==d)
    {
        cout<<"e equals d"<<endl;
    }
    else
    {
        cout<<"e not equals d"<<endl;
    }
    return 0;
}
