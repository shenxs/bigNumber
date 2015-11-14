#include"list.h"
#include<string>
using namespace std;
class bigNumber
{
public:
    bigNumber();
    ~bigNumber();

    bigNumber(string s);


 //io流运算符“<<”重载为友元函数
    friend ostream& operator << (ostream&,bigNumber&);
    friend istream& operator >> (istream&,bigNumber&); //声明重载运算符“>>”

 //运算符重载
    bigNumber & operator=(const bigNumber &des);
    bigNumber  operator+(const bigNumber &des)const;
private:
    list number;
};
