#include"list.h"

//默认构造函数
list::list()
{
    head=NULL;
    tail=NULL;
    length=0;
}
list::~list()
{
    if(!(head==NULL&&tail==NULL))
    {
        while(head!=tail)
        {
            node *temp=head->next;
            delete head;
            head=temp;
        }
        delete tail;
    }
    length=0;

}
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



const string list::toString() const
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

void list::copyList(const list  des)
{
    this->init(des.toString());
}
