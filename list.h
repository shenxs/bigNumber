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
    //将链表初始化为长度为n的链表
    //每个节点都为0
    list(int);
    ~list();
    //在链表的末尾增加
    void addATtail(int n);
    //在链表的头部增加
    void addAThead(int n);
    //初始化一个链表
    //string ->list of int
    void init(string s);
    //list of int ->string
    //将一个链表表示的数字拼接为一个字符串
    string toString();
    //从另一个链表拷贝
    void copyList(list  des);
    //加法
    //list->list
    //将两个链表相加
    list add(list  &des) ;

    node *head;//头指针
    node *tail;//尾指针
    int length;//数字既链表的长度
};

#endif
