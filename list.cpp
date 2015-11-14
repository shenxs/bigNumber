#include"list.h"
//默认构造函数
list::list()
{
    head=NULL;
    tail=NULL;
    length=0;
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
    while(head!=NULL)
    {
        node* temp=head;
        head=head->next;
        delete temp;
    }
    head=tail=NULL;
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

void list::addAThead(int n)
{
    node * temp=new node(n);
    if(this->length==0)
    {
        head=temp;
        tail=temp;
        length++;
    }
    else
    {
        temp->next=head;
        head->pre=temp;
        head=temp;
        length++;
    }
}

void list::copyList(const list  &des)
{
    string temp=des.toString();
    this->init(temp);
}

list list::add(list des) const
{
    node *t1=des.tail;//尾部指针

    node *t2=this->tail;

    int content=0;
    int jingwei=0;
    list temp;
    while(t1!=NULL||t2!=NULL||jingwei!=0)
    {
        if(t1!=NULL)
        {
            content+=t1->value;
            t1=t1->pre;
        }
        if(t2!=NULL)
        {
            content+=t2->value;
            t2=t2->pre;
        }
        content+=jingwei;
        if(content>9)
            {
                jingwei=1;
                temp.addAThead(content-10);
                content=0;
            }
        else
        {
            jingwei=0;
            temp.addAThead(content);
            content=0;
        }
    }
    return temp;

}

