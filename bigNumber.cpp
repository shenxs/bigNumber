#include "bigNumber.h"

//默认构造函数
bigNumber::bigNumber()
{
    number.init("0");
}

//默认析构函数
bigNumber::~bigNumber()
{
    number.~list();
}


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
bigNumber &bigNumber::operator=(const bigNumber & des)
{
    this->number.copyList(des.number);
    return *this;
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

bigNumber bigNumber::operator+(const bigNumber & b) const
{
    bigNumber temp((this->number.add(b.number)).toString());
    return temp;
}

