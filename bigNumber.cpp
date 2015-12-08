#include "bigNumber.h"

bigNumber::bigNumber()
{
    number.init("0");
}

bigNumber::~bigNumber()
{
    this->number.~list();
}

bigNumber::bigNumber(string s)
{
    number.init(s);
}
ostream& operator<<(ostream& output,const bigNumber& b)
{
   output<<b.number.toString();
   return output;
}
istream& operator >> (istream& input,bigNumber& b)
{

    string str;
    input>>str;
    b.number.init(str);
    return input;
}
void bigNumber::binary()
{
    //to be continue
}
void bigNumber::show()
{
    int l=this->number.length;
    cout<<"位数:"<<l<<endl;
    cout<<"数字:"<<*this<<endl;
}


bigNumber &bigNumber::operator=(const bigNumber & des)
{
    this->number.init(des.number.toString());
    return *this;
}
bool bigNumber::operator!=(const bigNumber &b) const
{
    if((*this)==b)
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
    else if((*this)<b)
    {
         result=zero;
    }
    else
    {
        bigNumber temp(this->number.divide(b.number).toString());
        result=temp;

    }

    return result;
}

bigNumber bigNumber::operator^(const bigNumber &b) const
{
    bigNumber two("2");
    bigNumber one("1");
    bigNumber zero("0");
    bigNumber result;
    result.number.init(this->number.toString());//先将结果初始化为底数
    string moming=(*this).number.toString();

    if(b==zero&&(*this)==zero)
    {
        cout<<"0的0次没有意义"<<endl;
        result=zero;
    }
    else if(b==zero)
    {
        result=one;
    }
    else
    {
        bigNumber aim=b;
        result=one;
        bigNumber second;
        bigNumber x;
        while(aim!=zero)
        {
            second=one;
            aim=aim-second;
            x.number.init(moming);
            while(second<aim||second==aim)
            {
                aim=aim-second;
                second=second*two;
                x=x*x;
            }
            result=result*x;
        }
    }

    return result;
}

bigNumber bigNumber::operator%(const bigNumber & b) const
{
    return ((*this)- ((*this)/b)*b);
}
