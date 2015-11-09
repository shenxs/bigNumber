#include"node.h"
#include<iostream>
using namespace std;
node::node()
{
    pre=NULL;
    next=NULL;
}


node::~node()
{}

node::node(int n)
{
    value=n;
    pre=NULL;
    next=NULL;
}
