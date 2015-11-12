#include "bigNumber.h"

//默认构造函数
bigNumber::bigNumber()
{}

//默认析构函数
bigNumber::~bigNumber()
{}

bigNumber::bigNumber(string s)
{
    //初始化数字链表
    number.init(s);
}
ostream& operator<<(ostream& output,bigNumber& b) //定义运算符“<<”重载函数
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

bigNumber bigNumber::operator=(const bigNumber & des)
{
    this->number.copyList(des.number);
    return *this;
}

