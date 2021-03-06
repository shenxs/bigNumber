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
    string temp="";
    for(int i=0;i<n;i++)
    {
        temp+='0';
    }
    this->init(temp);
}
list::list(string s)
{
    this->~list();
    int l=s.length();
    for (int i = 0; i < l; ++i)
    {
        int n=s[i]-'0';
        if(n>=0&&n<=9)
        {
            addATtail(s[i]-'0');
        }
        else
        {
            cout<<"构造字段包含非数字字符"<<endl;
        }
    }
}
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
void list::addAThead(int n)
{
    node * temp=new node(n);
    if(length==0)
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

void list::init(string s)
{
    this->~list();
    int l=s.length();
    for (int i = 0; i < l; ++i)
    {
        int n=s[i]-'0';
        if(n>=0&&n<=9)
        {
            addATtail(s[i]-'0');
        }
        else
        {
            cout<<"构造字段包含非数字字符"<<endl;
        }
    }
}

void list::show()
{
    cout<<"头节点值"<<this->head->value<<endl;
    cout<<"头节点pre"<<this->head->pre<<endl;
    cout<<"尾节点next"<<this->tail->next<<endl;
    cout<<"list的长度"<<this->length<<endl;
    cout<<"list内容"<<this->toString()<<endl;
}


void list::show()const
{
    cout<<"头节点值"<<this->head->value<<endl;
    cout<<"头节点pre"<<this->head->pre<<endl;
    cout<<"尾节点next"<<this->tail->next<<endl;
    cout<<"list的长度"<<this->length<<endl;
    cout<<"list内容"<<this->toString()<<endl;
}

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


list & list::operator=(const list &des)
{
    this->init(des.toString());
    return *this;
}

bool list::operator>=(const list &des)
{
    string x=this->toString();
    string y=des.toString();

    if(x.length()==y.length())
    {
        if(x==y)//两个字符串相等
        {
            return true;
        }
        else//逐位比较
        {
            int l=x.length();
            for(int i=0;i<l;i++)
            {
                if(x[i]>y[i])
                    return true;
                if(x[i]<y[i])
                    return false;
            }
            cout<<"如果你在程序运行时看到这条信息,代表程序员又要去debug了"<<endl;
            return false;
        }
    }
    else if(x.length()>y.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}
list list::sublist(int start,int end ) const
{
    list temp;
    string str=this->toString();
    string sub_string=str.substr(start,end);
    temp.init(sub_string);
    return temp;
}
list list::add(const list &des) const
{
    bool tiaoshi=false;
    node *t1=des.tail;//尾部指针
    node *t2=this->tail;

    int content=0;//每一位的计算结果
    int jingwei=0;//进位
    list result;//局部变量,存结果
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
                result.addAThead(content-10);
        }
        else
        {
            jingwei=0;
            result.addAThead(content);
        }
        content=0;
    }
    if(tiaoshi)
    {
        cout<<"list::add结果"<<result.toString()<<endl;
    }
    return result;
}

list list::sub(const list &des) const
{
    node *t1=des.tail;//尾部指针
    node *t2=this->tail;

    int content=0;//每一位的计算结果
    int jingwei=0;//进位
    list result;//结果
    while(t1!=NULL||t2!=NULL||jingwei!=0)
    {
        if(t1!=NULL)
        {
            content-=t1->value;
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
                result.addAThead(content+10);
        }
        else
        {
            jingwei=0;
            result.addAThead(content);
        }
        content=0;
    }
    //如果链表的一开始有大量的0 要去除
    while(result.length>1&&result.head->value==0)
    {
        node * tempNode=result.head;
        result.head=result.head->next;
        result.head->pre=NULL;
        delete tempNode;
        result.length=result.length-1;
    }
    return result;
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
        x_long=*this;
        x_short=des;
    }
    else
    {
        x_long=des;
        x_short=*this;
    }
    int l=x_short.length;
    list temp_list;//用于储存每一次乘法的结果
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
            temp_list.addAThead(content);
            content=0;
            if(x_long_pointer!=NULL)
                x_long_pointer=x_long_pointer->pre;
        }
        //根据位数在末尾添加相应个数的0
        for(int j=0;j<i;j++)
        {
            temp_list.addATtail(0);
        }
        x_short_pointer=x_short_pointer->pre;
        result=result.add(temp_list);
        temp_list.~list();
    }
    //整理result 防止出现乘0之后出现一大串0
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

list list::multi(int n) const
{
    if(n==0)
    {
        list temp;
        temp.init("0");
        return this->multi(temp);
    }
    char char_n;
    string temp;
    while(n!=0)
    {
        char_n=(n%10)+'0';
        temp=char_n+temp;
        n/=10;
    }
    list list_of_n;
    list_of_n.init(temp);
    return this->multi(list_of_n);
}

list list::divide(const list&des)const
{
    bool tiaoshi=false;
    int l_of_long=this->length;//被除数
    int l_of_short=des.length;//除数

    list result;//结果
    node *divide_pointer=this->head;//指向被除数的某一位的一个指针
    for(int i=0;i<(l_of_short);i++)
    {
        divide_pointer=divide_pointer->next;
    }
    int cishu=l_of_long-l_of_short+1;//要计算的位数(首位可能为0)也就是要做循环的次数
    //todo完成链表的=重载
    list jian_shu=this->sublist(0,l_of_short);//余数
    list bei_jian_shu;
    list yu_shu;
    int shang;
    for(int i=0;i<cishu;i++)
    {
        shang=0;//商
        while((jian_shu.sub((des.multi(shang))))>=des)
        {
            shang=shang+1;
        }

        result.addATtail(shang);
        bei_jian_shu=des.multi(shang);
        yu_shu = jian_shu.sub(bei_jian_shu);
        jian_shu=yu_shu;
        if(tiaoshi)
        {
            cout<<endl<<"商"<<shang<<endl;
            cout<<"减数"<<jian_shu.toString()<<endl;
            cout<<"被减数"<<bei_jian_shu.toString()<<endl;
            cout<<"余数"<<yu_shu.toString()<<endl<<endl;
        }if(divide_pointer!=NULL)
        {
            //需要判断jian_shu是否为0
            //否则会出现开头为0的数字
            if(jian_shu.head->value==0)
            {
                jian_shu.head->value=divide_pointer->value;
            }
            else
            {
                jian_shu.addATtail(divide_pointer->value);
            }
            divide_pointer=divide_pointer->next;
        }

    }

    //todo去除掉首位的0
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

