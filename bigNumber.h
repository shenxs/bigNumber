#include"list.h"
#include<string>
using namespace std;
class bigNumber
{
public:
    bigNumber();//无参构造方法,默认为0
    bigNumber(string s);//以字符串初始化
    ~bigNumber();

 //io流运算符重载为友元函数
    friend ostream& operator << (ostream&,bigNumber&);//输出流重载
    friend istream& operator >> (istream&,bigNumber&); //输入流重载

 //运算符重载
    bigNumber &operator=(const bigNumber &des);
    friend bigNumber operator+( bigNumber &b1,bigNumber &b2);

private:
    list number;
};
