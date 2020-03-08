/*
n个台阶，每步最多走M个台阶，求有多少种走法

用动态规划的思想，其实n个台阶的走法就是n-1,n-2...n-M个台阶的走法和，代表最后一步的M种走法
其实这也就是更一般性的斐波那契数列，每一项是前M项的和
怎样求项数很大的斐波那契值？
对于二阶数列，有[F(n) F(n-1)]=[F(n-1) F(n-2)]*A
其中A是二阶方阵，同样对于三阶数列，也有类似式子
A的一般表达形式是第一列为1，对角线上方一层为1，其余为0
递推，有[F(n) F(n-1) ...]=[F[0] F[-1] ...]*A^n
注意负项数默认值为0，F[0]=1，所以F(n)=A^n的左上角元素 
剩下的问题就是怎样快速求解A^n
把n写成二进制形式，比如n=21=16+4+1
那么A^21=A^16*A^4*A^1
拿一个while循环让A每次自己平方，然后碰到n二进制的1就给result上乘个A
复杂度是O(log2 N)

关键词：数学，矩阵，好题，有思想，顶级斐波那契，动态规划 
*/
#include<iostream>
using namespace std;

struct Matrix
{
    int n;
    long long value[30][30];
    
    Matrix(int a=0):n(a){memset(value,0,sizeof(value));}
    
    void Init()
    {
        for(int i=0;i<n;i++)
        {
            value[i][0]=1;
            if(i+1<n)value[i][i+1]=1;
        }
    }
    
    Matrix Pow(long long k)
    {
        Matrix result(n);
        for(int i=0;i<n;i++)
            result.value[i][i]=1;
                
        Matrix temp=*this;
        
        while(k>0)
        {
            if(k%2==1)result*=temp;
            temp*=temp;
            k/=2;
        }
        return result;
    }
    
    void operator *=(Matrix t)
    {
        Matrix result(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                    result.value[i][j]+=(value[i][k]*t.value[k][j])%9876543;
                result.value[i][j]%=9876543;
            }
        *this=result;
    }
};

int main()
{
    long long n;
    int M;
    cin>>n>>M;
    
    Matrix A(M);
    A.Init();
    A=A.Pow(n);
    
    cout<<A.value[0][0]<<endl;
}
