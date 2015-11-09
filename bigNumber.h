#include"list.h"
#include<string>
using namespace std;
class bigNumber
{
public:
    bigNumber();
    ~bigNumber();

    bigNumber(string s);
    void display();


 //运算符“<<”重载为友元函数
    friend ostream& operator << (ostream&,bigNumber&);
    friend istream& operator >> (istream&,bigNumber&); //声明重载运算符“>>”
private:
    list number;
};
