/*
一个数列，先写出每两项的和，再写出每两项的差，组成一个长度相等的新数列。再对前一半执行相同操作，以此类推
已知生成数列，求原数列

例如数列
5   2   3   2   5   7   9   6
7   5   12  15  3   1   -2  3
12  27  2   -3  3   1   -2  3
39  -15 2   -3  3   1   -2  3
往回推的时候先把第四行前两项用solute还原
再把第三行的1,3和2,4项还原
不仅要还原，还要把1,3和2,4的位置变成1,3,2,4，这就是sort的功能
实现比较需要技巧，但是不难理解

关键词：数学题 
*/
#include<iostream>
using namespace std;

void solute(int &s,int &d)
{
    int a,b;
    a=(s+d)/2;
    b=(s-d)/2;
    s=a;d=b;
}//把两数的和与差换为原数 

void sort(int start[],int length)
{
    int *p=new int [length];
    for(int i=0;i<length;i+=2)
        p[i]=start[i/2];
    for(int i=1;i<length;i+=2)
        p[i]=start[length/2+i/2];
    for(int i=0;i<length;i++)
        start[i]=p[i];
    delete p;
}//把原序列前一半变为奇数项，后一半变为偶数项 

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        
        int zip[256];
        for(int i=0;i<n;i++)
            cin>>zip[i];
            
        for(int i=1;i<n;i*=2)
        {
            for(int j=0;j<i;j++)
                solute(zip[j],zip[j+i]);
            sort(zip,i*2);
        }
                
        for(int i=0;i<n-1;i++)
            cout<<zip[i]<<' ';
        cout<<zip[n-1]<<endl;
    }
}
