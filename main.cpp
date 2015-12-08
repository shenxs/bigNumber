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
    if(a==c)
    {
        cout<<"a 等于c"<<endl;
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
    if(0)
    {
        bigNumber x("2");
        bigNumber y("6");
        bigNumber z("1");
        for(int i=1;i<=10000000;i++)
        {
            x=x*y;
        }
    }
    return 0;
}
