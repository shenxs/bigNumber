#include"list.h"


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
}

void list::init(string s)
{
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
