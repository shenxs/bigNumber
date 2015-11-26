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
    this->~list();
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
    while(length>0)
    {
        node* temp=tail;
        tail=tail->pre;
        delete temp;
        length--;
    }
    head=NULL;//删除最后一个节点后将头指针置空
}
//在链表的尾部增加
void list::addATtail(int n)
{
    node *temp=new node(n);
    if(length==0)
    {
        head=tail=temp;
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
        int n=s[i]-'0';
        if(n>=0&&n<=9)
            addATtail(s[i]-'0');
        else
        {
            cout<<"构造字段包含非数字字符"<<endl;
        }
    }
}
//转化为字符串
string list::toString()
{
    string str="";
    node *cur=head;
    while(cur!=NULL)
    {
        str+=cur->value+'0';
        cur=cur->next;
    }
    return str;
}
string list::toString() const
{
    string str="";
    node *cur=head;
    while(cur!=NULL)
    {
        str+=cur->value+'0';
        cur=cur->next;
    }
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

void list::copyList(const list &des)
{
    string temp=des.toString();
    this->init(temp);
}

list list::add(const list &des) const
{
    bool tiaoshi=false;
    node *t1=des.tail;//尾部指针

    node *t2=tail;

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
        }
        else
        {
            jingwei=0;
            temp.addAThead(content);
        }
        content=0;
    }
    if(tiaoshi)
    {
        cout<<"list::add结果"<<temp.toString()<<endl;
    }
    return temp;
}

//减法即a+(-b) 进位对应为-1
list list::sub(const list &des) const
{
    node *t1=des.tail;//尾部指针

    node *t2=tail;

    int content=0;
    int jingwei=0;
    list temp;
    while(t1!=des.head->pre||t2!=head->pre||jingwei!=0)
    {
        if(t1!=NULL)
        {
            content+=(-1)*(t1->value);
            t1=t1->pre;
        }
        if(t2!=NULL)
        {
            content+=t2->value;
            t2=t2->pre;
        }
        content+=jingwei;
        if(content<0)
        {
                jingwei=-1;
                temp.addAThead(content+10);
        }
        else
        {
            jingwei=0;
            temp.addAThead(content);
        }
        content=0;
    }
    //如果链表的一开始有大量的0 要去除
    while(temp.length>1&&temp.head->value==0)
    {
        node * tempNode=temp.head;
        temp.head=temp.head->next;
        temp.head->pre=NULL;
        delete tempNode;
        temp.length=temp.length-1;
    }
    return temp;
}

list list::multi(const list &des) const
{
    bool tiaoshi=false;
    //模拟手算乘法;
    //先判断长度,以减少计算次数
    list result;
    list x_long,x_short;//两个乘数,一长一短
    if(this->length>des.length)
    {
        x_long.copyList(*this);
        x_short.copyList(des);
    }
    else
    {
        x_long.copyList(des);
        x_short.copyList(*this);
    }
    int l=x_short.length;
    list *result_array=new list[l];
    node * x_long_pointer;
    node * x_short_pointer=x_short.tail;
    if(tiaoshi)
    {
        cout<<"long"<<x_long.toString()<<endl;
        cout<<"short"<<x_short.toString()<<endl;
    }
    //短乘数每一位和长乘数相乘
    for(int i=0;i<l;i++)
    {
        int content=0;
        int jinwei=0;
        x_long_pointer=x_long.tail;
        while(x_long_pointer!=NULL||jinwei!=0)
        {
            content+=jinwei;
            if(x_long_pointer!=NULL)
                content+=(x_short_pointer->value) * (x_long_pointer->value);
            jinwei=content/10;
            content=content%10;
            result_array[i].addAThead(content);
            content=0;
            if(x_long_pointer!=NULL)
                x_long_pointer=x_long_pointer->pre;
        }
        //根据位数在末尾添加相应个数的0
        for(int j=0;j<i;j++)
        {
            result_array[i].addATtail(0);
        }
        x_short_pointer=x_short_pointer->pre;
        if(tiaoshi)
        {
            cout<<"result_array["<<i<<"]="<<result_array[i].toString()<<endl;
        }
    }
    //将所有的乘的结果相加
    for(int i=0;i<l;i++)
    {
        result.copyList(result.add(result_array[i]));
    }
    //清理战场
    delete [] result_array;
    //整理result
    while(result.length>1&&result.head->value==0)
    {
        node * tempNode=result.head;
        result.head=result.head->next;
        result.head->pre=NULL;
        delete tempNode;
        result.length=result.length-1;
    }

    if(tiaoshi)
    {
        result.show();
    }
    return result;
}

void list::show()
{
    cout<<"头节点值"<<this->head->value<<endl;
    cout<<"头节点pre"<<this->head->pre<<endl;
    cout<<"尾节点next"<<this->tail->next<<endl;
    cout<<"list的长度"<<this->length<<endl;
    cout<<"list内容"<<this->toString()<<endl;
}
