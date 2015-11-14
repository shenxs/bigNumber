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

    cout<<"输入b"<<endl;

    cin>>b;
    c=b+a;
    cout<<c<<endl;
    return 0;
}
