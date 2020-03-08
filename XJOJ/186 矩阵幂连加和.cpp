/*
对于方阵A，求S=A+A^2+A^3+A^4+...+A^k 

对求和也是不断二分
如求S＝A1+A2+...+A8，二分成求A1+A2+A3+A4+A4*(A1+A2+A3+A4)，A8＝A4^2；在求A4的时候同时把A1+A2+A3+A4求出。
对于奇数，如A7,等式则为A1+A2+A3+A3*(A1+A2+A3+A3*A1)。注意取模。

关键词：二分，递归，数学题 
*/
#include<iostream>
using namespace std;

int n,K,m;

struct Matrix
{
    int element[30][30];
    
    Matrix(){memset(element,0,sizeof(element));}
    friend istream& operator >>(istream& input,Matrix& t)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                input>>t.element[i][j];
        return input;
    }
    friend ostream& operator <<(ostream& output,Matrix& t)
    {
        for(int i=0;i<n;i++)
        {
            output<<t.element[i][0];
            for(int j=1;j<n;j++)
                output<<' '<<t.element[i][j];
            output<<endl;
        }
        return output;
    }
    Matrix operator *(Matrix t)
    {
        Matrix temp;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                    temp.element[i][j]+=(element[i][k]*t.element[k][j])%m;
                temp.element[i][j]%=m;
            }
        return temp;
    }
    void operator +=(Matrix t)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                element[i][j]=(element[i][j]+t.element[i][j])%m;
    }
    void operator *=(Matrix t){*this=*this*t;}
}A,S,present;

void calculate(int t)
{
    if(t==1)return;
    
    calculate(t/2);
    S+=present*S;
    present*=present;
    
    if(t%2==1)
    {
        present*=A;
        S+=present;
    }
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    cin>>n>>K>>m;
    cin>>A;
    S=present=A;
    calculate(K);
    
    cout<<S;
    
    //while(1);
}
