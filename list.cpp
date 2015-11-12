#include"list.h"
//默认构造函数
list::list()
{
    node *temp=new node(0);
    head=tail=temp;
    length=1;
}
list::list(int n)
{
    head=NULL;
    tail=NULL;
    length=0;
    string temp="";
    for(int i=0;i<n;i++)
    {
        temp+='0';
    }
    this->init(temp);
}
//析构函数
list::~list()
{
    if(this->length!=0)
    {
        while(head!=tail)
        {
            node *temp=head;
            head=temp->next;
            delete temp;
        }
        delete tail;
    }
    length=0;
}
//在链表的尾部增加
void list::addATtail(int n)
{
    node *temp=new node(n);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->pre=tail;
        tail->next=temp;
        tail=temp;
    }
    length++;
}
//初始化链表
void list::init(string s)
{
    this->~list();
    int l=s.length();
    for (int i = 0; i < l; ++i)
    {
        addATtail(s[i]-'0');
    }
}
//转化为字符串
string list::toString()
{
    string str="";
    node *cur=head;
    while(cur!=tail)
    {
        str+=cur->value+'0';
        cur=cur->next;
    }
    if(tail!=NULL)
        str+=tail->value+'0';
    return str;
}

string list::toString() const
{
    string str="";
    node *cur=head;
    while(cur!=tail)
    {
        str+=cur->value+'0';
        cur=cur->next;
    }
    if(tail!=NULL)
        str+=tail->value+'0';
    return str;
}

void list::copyList(const list  &des)
{
    string temp=des.toString();
    this->init(temp);
}

list list::add(const list des)
{
    node *h1=des.head;//头指针
    node *t1=des.tail;//尾部指针

    node *h2=this->head;
    node *t2=this->tail;

    int max=0;
    if(this->length>des.length)
        max=this->length;
    else
        max=des.length;

    //初始化一个链表长度为最长的链表加1
    //防止出现进位出现
    list temp(++max);
    node *t3=temp.tail;

    int content=0;//每一位的计算容器
    int jingwei=0;
    while(!(h1==t1&&h2==t2))
    {
        if(t2==NULL)
            cout<<"t空"<<endl;

        content = t1->value+t2->value+jingwei;
        if(content>9)
        {
            content-=10;
            jingwei=1;
        }
        t3->value=content;

        t1=t1->pre;
        t2=t2->pre;
        t3=t3->pre;
    }


    //todo 检验最高位是否为0

    return temp;
}

