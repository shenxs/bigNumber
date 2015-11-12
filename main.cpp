#include<iostream>
#include<string>
#include"bigNumber.h"
#include"node.h"
#include"list.h"
using namespace std;


int main()
{

    bigNumber test;
    cout<<"请输入数字"<<endl;
    cin>>test;

    bigNumber test2;
    cin>>test2;

    test=test2;
    cout<<test;


    return 0;
}
