/*
输入两个数字串，输出他们的乘积

典型的高精度计算，可以先把其中一个数与0至9的乘积分别存起来
然后直接加就行了
进位也可以等到最后进，没必要每次都进位

关键词：高精度计算 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    char a[101],b[101];
    int result[201];
    int k[10][101];//存放b分别乘以0到9的值
    
    while(cin>>a>>b)
    {
        memset(result,0,sizeof(result));
        memset(k,0,sizeof(k));
        
        for(int j=0;j<10;j++)
            for(int i=0;i<strlen(a);i++)
                k[j][i]=j*(a[i]-'0');

        for(int i=0;i<strlen(b);i++)
            for(int j=0;j<strlen(a);j++)
                result[j+i]+=k[b[i]-'0'][j];
                
        for(int i=strlen(a)+strlen(b)-2;i>0;i--)
            if(result[i]>=10)
            {
                result[i-1]+=result[i]/10;
                result[i]%=10;
            }
        for(int i=0;i<strlen(a)+strlen(b)-1;i++)
            cout<<result[i];
        cout<<endl;
    } 
    return 0;
}
