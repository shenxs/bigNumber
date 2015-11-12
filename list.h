#ifndef LIST_H
#define LIST_H
#include"node.h"
#include<string>
#include<iostream>
using namespace std;
class list
{
public:
    list();
    ~list();
    //在链表的末尾增加
    void addATtail(int n);
    //初始化一个链表
    //string ->list of int
    void init(string s);
    //list of int ->string
    //将一个链表表示的数字拼接为一个字符串
    string toString();
    const string toString() const;
    void copyList( list  des);

private:
    node *head;//头指针
    node *tail;//尾指针
    int length;//数字既链表的长度
};

#endif
