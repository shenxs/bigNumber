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
    list(int);//每个节点都为0 ,将链表初始化为长度为n的链表
    list(string);//以字符串构造
    ~list();

    void addATtail(int n);//在链表的末尾增加
    void addAThead(int n);//在链表的头部增加
    void init(string s);//初始化一个链表 string ->list of int
    void show();//显示list的信息,方便调试
    void show() const ;

    string toString();//把链表中的value值拼接为一个string
    string toString() const;
    list & operator=(const list &des);//等号重载,方便阅读代码
    list sublist(int ,int ) const;//取出[int,int)的子串
    bool operator>=(const list &des);//比较所代表数字的大小


    list add(const list &des) const;
    list sub(const list &des) const;
    list multi(const list &des) const;
    list multi(int) const;//只在除法中使用,int乘链表所代表数字,返回一个链表
    list divide(const list &des) const;

    node *head;//头指针
    node *tail;//尾指针
    int length;//数字既链表的长度
};
//注释会说谎,但是代码不会
#endif
