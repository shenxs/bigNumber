#include<iostream>
#include<string>
#include"bigNumber.h"
#include"node.h"
#include"list.h"
using namespace std;


int main()
{

    bigNumber a,b,c;
    a+b;
    cout<<"请输入a"<<endl;
    cin>>a;
    cout<<"a="<<a<<endl;
    cout<<"输入b"<<endl;
    cin>>b;
    cout<<"b="<<b<<endl;
    c=a+b;
    cout<<a+b<<endl;
    cout<<"c=a+b="<<a<<"+"<<b<<"="<<c<<endl;
    cout<<a<<b<<endl;
    c=a-b;
    cout<<"c=a-b="<<a-b<<endl;

    cout<<a<<endl;
    cout<<a<<endl;
    if(a==c)
    {
        cout<<"a equals c"<<endl;
    }
    else if (a>c)
    {
        cout<<"a大于c"<<endl;
    }
    else if (a<c)
    {
        cout<<"a小于c"<<endl;
    }
    else
    {
        cout<<"怎么可能?!哪里错了"<<endl;
    }
    return 0;
}
