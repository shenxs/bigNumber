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
    void show();//调试显示所有的list信息
    void show() const ;
    string toString();
    string toString() const;
    list & operator=(const list &des);
    list sublist(int ,int ) const;
    void copyList(const list &des);
    bool operator>=(const list &des);
    list add(const list &des) const;
    list sub(const list &des) const;
    list multi(const list &des) const;
    list multi(int) const;//只在除法中使用,int参数只能使用10以内的整数
    list divide(const list &des) const;
    node *head;//头指针
    node *tail;//尾指针
    int length;//数字既链表的长度
};

#endif
