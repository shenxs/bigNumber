#ifndef LIST_H
#define LIST_H
#include"node.h"
#include<string>
#include<iostream>
using namespace std;
class list
{
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    ~list(){}
    void addATtail(int n);
    void init(string s);
    string toString();
private:
    node *head;
    node *tail;
};

#endif
