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
    friend ostream& operator << (ostream&,const  bigNumber&);//输出流重载
    friend istream& operator >> (istream&,bigNumber&); //输入流重载
    bigNumber int2bigNumber(int);//int类型到bigNumber类型的转换
    void binary();//二进制输出
    void input_Binary();
    void show();//显示内容和长度
 //比较运算符重载
    bigNumber & operator=(const bigNumber & b);
    bigNumber & operator=(int b);
    bool      operator==(const bigNumber &b) const;
    bool      operator==(int b) const;
    bool      operator!=(const bigNumber &b) const;
    bool      operator>(const bigNumber  &b) const;
    bool      operator<(const bigNumber  &b) const;

//加减乘除
    bigNumber operator+(const bigNumber &b) const;
    bigNumber operator-(const bigNumber &b) const;
    bigNumber operator*(const bigNumber &b) const;
    bigNumber operator/(const bigNumber &b) const;
    bigNumber operator^(const bigNumber &b) const;//指数运算重载
    bigNumber operator^(int b) const;//指数运算重载
    bigNumber operator%(const bigNumber &b) const;
private:
    list number;
};
//代码如诗
