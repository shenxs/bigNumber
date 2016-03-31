#include "bigNumber.h"

bigNumber::bigNumber()
{
    number.init("0");
}
//dhsdjdfk

bigNumber::~bigNumber()
{
    this->number.~list();
}

bigNumber::bigNumber(string s)
{
    number.init(s);
}
bigNumber::bigNumber(const bigNumber &b)
{
    this->number.init(b.number.toString());
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
bigNumber bigNumber::int2bigNumber(int n)
{
    string str;
    if(n==0)
    {
        str="0";
    }
    else
    {
        while(n!=0)
        {
            str+=(n%10)+'0';
            n/=10;
        }
    }
    bigNumber temp(str);
    return temp;

}
void bigNumber::input_Binary()
{
    bigNumber two("2");
    string str;
    this->number.init("0");
    cout<<"请输入一个二进制数"<<endl;
    cin>>str;
    int l=str.length();
    for(int i=0;i<l;i++)
    {

        if(str[i]=='1')
        {
            int zhishu=l-i-1;
            bigNumber temp=two^zhishu;
            (*this)=(*this)+temp;
        }
    }
 }
void bigNumber::binary()
{
    string str;
    bigNumber two("2");
    bigNumber one("1");
    bigNumber temp;
    temp.number.init((*this).number.toString());
    while(temp>one)
    {
        str=(temp%two).number.toString()+str;
        temp=temp/two;
    }
    if(temp==one)
        str="1"+str;

    cout<<str<<endl;
}
void bigNumber::showLength()
{
    int l=this->number.length;
    cout<<"位数:"<<l<<endl;
}


bigNumber &bigNumber::operator=(const bigNumber & des)
{
    this->number=des.number;
    return *this;
}
bigNumber &bigNumber::operator=(int b)
{

    bigNumber temp;
    temp=temp.int2bigNumber(b);

    this->number=temp.number;
    return *this;

}
bool bigNumber::operator!=(const bigNumber &b) const
{
    if((*this)==b)
        return false;
    else
        return true;
}
bool bigNumber::operator!=(int b) const
{

    bigNumber temp;
    temp=temp.int2bigNumber(b);
    return (*this)!=temp;
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
bool bigNumber::operator==(int b)const
{
    bigNumber temp;
    temp=temp.int2bigNumber(b);

    return (*this)==temp;
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
        result=1;
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

    if(b==0&&(*this)==0)
    {
        cout<<"0的0次没有意义"<<endl;
        result=0;
    }
    else if(b==0)
    {
        result=one;
    }
    else
    {
         bigNumber aim=b;
        result=one;
        bigNumber second;
        bigNumber x;
        while(aim!=0)
        {
            second=one;
            aim=aim-second;
            x=(*this);
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
bigNumber bigNumber::operator^(int b) const
{
    string str;
    if(b==0)
    {
        str="0";
    }
    else
    {
        while(b!=0)
        {
            str+=(b%10)+'0';
            b/=10;
        }
    }
    bigNumber temp;
    temp.number.init(str);
    return (*this)^temp;
}

bigNumber bigNumber::operator%(const bigNumber & b) const
{
    return ((*this)- ((*this)/b)*b);
}

bigNumber bigNumber::quickMod(const bigNumber &b ,const bigNumber &c)
{

    bigNumber A,B,C;
    bigNumber zero("0");
    bigNumber two("2");
    A=(*this);
    B=b;
    C=c;
    bigNumber ans;

    ans=1;
    A=A%C;
    while(B>zero)
    {
        if(B%two==1)
            ans=(ans*A)%C;
        B=B/two;
        A=(A*A)%C;
    }
    return ans;
}
