#include "bigNumber.h"

//默认构造函数
bigNumber::bigNumber()
{
    number.init("0");
}

//默认析构函数
bigNumber::~bigNumber()
{}


bigNumber::bigNumber(string s)
{
    //初始化数字链表
    number.init(s);
}
ostream& operator<<(ostream& output,const bigNumber& b) //定义运算符“<<”重载函数
{
   output<<b.number.toString();
   return output;
}
istream& operator >> (istream& input,bigNumber& b)  //定义重载运算符“>>”
{

    string str;
    input>>str;
    b.number.init(str);
    return input;
}
//等号运算符
bigNumber &bigNumber::operator=(const bigNumber  &des)
{

    this->number.copyList(des.number);
    return *this;
}
bool bigNumber::operator!=(const bigNumber &b) const
{
    bigNumber zero("0");
    if((*this)-b==zero)
        return false;
    else
        return true;

}
bool bigNumber::operator==(const bigNumber &b) const
{
    string x=this->number.toString();
    string y=b.number.toString();
    if(x==y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//加号重载

bool bigNumber::operator>(const bigNumber & b) const
{
    string x=this->number.toString();
    string y=b.number.toString();

    if(x.length()==y.length())
    {
        if(x==y)
        {
            return false;
        }
        else//zhu wei bi jiao
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

bool bigNumber::operator<(const bigNumber &b) const
{
    if(*this==b)
    {
        return false;
    }
    else if(*this>b)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bigNumber bigNumber::operator+(const bigNumber & b) const
{
    bigNumber temp((this->number.add(b.number)).toString());
    return temp;
}

bigNumber bigNumber::operator-(const bigNumber & b)const
{

    bigNumber result;
    if((*this)>b||(*this)==b)//大于或等于就相减
    {
        bigNumber temp((this->number.sub(b.number)).toString());
        result=temp;
    }
    else//暂时不考虑负号
    {
        bigNumber temp((b.number.sub(this->number)).toString());
        result=temp;
    }
    return result;
}


bigNumber  bigNumber::operator*(const bigNumber &b) const
{
    bigNumber result(this->number.multi(b.number).toString());
    return result;
}

bigNumber bigNumber::operator/(const bigNumber &b) const
{
    bigNumber result;
    bigNumber zero("0");
    bigNumber one("1");
    if(b==zero)
    {
        cout<<"除数不能为0"<<endl;
    }
    else if((*this)==b)
    {
        result=one;
    }
    else
    {
        bigNumber temp(this->number.divide(b.number).toString());
        result=temp;

    }

    return result;
}
