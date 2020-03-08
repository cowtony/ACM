#include<iostream>
#include<string>
using namespace std;

class High_Precision
{
public:
    int length;//长度 
    int sign;//符号 
    int digit[1000];//十进制数位 
    
    High_Precision(int p=0);//构造函数，赋初值p 
    friend istream& operator>>(istream&,High_Precision&);//输入 
    friend ostream& operator<<(ostream&,High_Precision&);//输出 
    bool operator ==(const High_Precision& n);
    bool operator ==(const int& n);
    bool operator !=(const High_Precision& n);
    bool operator !=(const int& n);
    bool operator >=(const High_Precision& n);
    bool operator >=(const int& n);
    bool operator <=(const High_Precision& n);
    bool operator <=(const int& n);
    bool operator >(const High_Precision& n);
    bool operator >(const int& n);
    bool operator <(const High_Precision& n);
    bool operator <(const int& n);//大小判断 
    High_Precision abs();
    
    High_Precision operator +(const High_Precision& n)
    {
        High_Precision result;
        
        if(sign*n.sign<0)
        {
            result=minus(n);
            if(result.length==0)result.sign=0;
            else if(abs()>)
        }
        else
        {
            result=plus(n);
            if(sign==-1 && n.sign==-1)result.sign=-1;
            else if(sign==1 && n.sign==1)result.sign=1;
            else result.sign=sign+n.sign;
        }
        
        return result;
    }
    
    High_Precision minus(const High_Precision& n)
    {
        if((*this).abs()<n.abs())return n.minus(*this);
        
        High_Precision result;
        if((*this).abs()==n.abs())return result;
        
        result.length=length;
        for(int i=0;i<length;i++)
            result.digit[i]=digit[i]-n.digit[i];
        for(int i=0;i<length;i++)
        {
            if(result.digit[i]<0)
            {
                result.digit[i+1]+=result.digit[i]%10;
                result.digit[i]=-result.digit[i]%10;
            }
            while(result.digit[result.length]<0)result.length++;
        }
        return result;
    }
    
private:
    int compare(High_Precision n);
    High_Precision plus(const High_Precision& n)
    {
        High_Precision result;
        result.length=max(length,n.length);
        for(int i=0;i<result.length;i++)
            result.digit[i]=digit[i]+n.digit[i];//相加 
        for(int i=0;i<result.length;i++)
        {
            if(result.digit[i]>9)
            {
                result.digit[i+1]+=result.digit[i]/10;
                result.digit[i]%=10;
            }
        }//进位 
        while(result.digit[result.length]>0)result.length++;

        return result;
    }
};

int main()
{
    High_Precision h(0),a;
    while(cin>>a)
    {
        if(a>h)cout<<"a>h"<<endl;
        if(a>=h)cout<<"a>=h"<<endl;
        if(a<h)cout<<"a<h"<<endl;
        if(a<=h)cout<<"a<=h"<<endl;
        if(a==h)cout<<"a==h"<<endl;
        if(a!=h)cout<<"a!=h"<<endl;
    }
        
    
    
    while(1);
}


High_Precision::High_Precision(int p)
{
    memset(digit,0,sizeof(digit));
        
    if(p<0){sign=-1;p=-p;}
    else if(p>0)sign=1;
    else sign=0;
        
    length=0;
    while(p)
    {
        digit[length++]=p%10;
        p/=10;
    }
}
istream& operator>>(istream& input,High_Precision& n)
{
    string s;
    input>>s;
        
    if(s[0]=='-')
    {
        n.sign=-1;
        s.erase(s.begin());
    }
    else n.sign=1;

    n.length=s.length();
    for(int i=0;i<n.length;i++)
        n.digit[i]=s[n.length-1-i]-'0';

    if(s.length()==1 && s[0]=='0')
    {
        n.sign=0;
        n.length=0;
        n.digit[0]=0;
    }
    
    return input;
}
ostream& operator <<(ostream& output,High_Precision& n)
{
    if(n.sign==-1)output<<'-';
    if(n.sign==0)output<<0;
    for(int i=n.length-1;i>=0;i--)
        output<<n.digit[i];
    return output;
}
inline int High_Precision::compare(High_Precision n)
{
    if(sign>n.sign)return 1;
    else if(sign<n.sign)return -1;
    if(length>n.length)return 1*sign;
    if(length<n.length)return -1*sign;
        
    for(int i=length-1;i>=0;i--)
    {
        if(digit[i]>n.digit[i])return 1*sign;
        if(digit[i]<n.digit[i])return -1*sign;
    }
    return 0;
}
inline bool High_Precision::operator ==(const High_Precision& n)
{
    return compare(n)==0;
}
inline bool High_Precision::operator ==(const int& n)
{
    return compare(High_Precision(n))==0;
}
inline bool High_Precision::operator !=(const High_Precision& n)
{
    return compare(n)!=0;
}
inline bool High_Precision::operator !=(const int& n)
{
    return compare(High_Precision(n))!=0;
}
inline bool High_Precision::operator >=(const High_Precision& n)
{
    return compare(n)>=0;
}
inline bool High_Precision::operator >=(const int& n)
{
    return compare(High_Precision(n))>=0;
}
inline bool High_Precision::operator <=(const High_Precision& n)
{
    return compare(n)<=0;
}
inline bool High_Precision::operator <=(const int& n)
{
    return compare(High_Precision(n))<=0;
}
inline bool High_Precision::operator >(const High_Precision& n)
{
    return compare(n)>0;
}
inline bool High_Precision::operator >(const int& n)
{
    return compare(High_Precision(n))>0;
}
inline bool High_Precision::operator <(const High_Precision& n)
{
    return compare(n)<0;
}
inline bool High_Precision::operator <(const int& n)
{
    return compare(High_Precision(n))<0;
}
High_Precision High_Precision::abs()
{
    High_Precision result=*this;
    if(result.sign==-1)result.sign=1;
    return result;
}
