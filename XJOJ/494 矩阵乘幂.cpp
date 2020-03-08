/*
输入一个方阵，输出他的M次方%2011的方阵

直接写个矩阵类，硬做。取模不能等到结果再取，要边算边取

关键词：数学题 
*/
#include<iostream>
#include<cstring>
using namespace std;

int n,m;

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
                    temp.element[i][j]+=(element[i][k]*t.element[k][j])%2011;
                temp.element[i][j]%=2011;
            }
        return temp;
    }
    void operator *=(Matrix t){*this=*this*t;}
};

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        Matrix fuck,result;
        cin>>fuck;
        result=fuck;

        for(int i=1;i<m;i++)
            result=result*fuck;
        
        cout<<result<<endl;
    }
    
    //while(1);
}
