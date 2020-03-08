/*
把给的32位二进制数转化为IP地址形式输出

读入32位，分成四节分开算
定义niu[]数组可以节省计算2^n的时间

关键词：简单题，进制转换 
*/
#include<iostream>
using namespace std;

int main()
{
    int n,sum;
    char a;
    int niu[8]={128,64,32,16,8,4,2,1};
    
    //freopen("aaa.txt","r",stdin);
    
    cin>>n;
    while(n--)
    {
        for(int i=0;i<4;i++)
        {
            sum=0;
            for(int j=0;j<8;j++)
            {
                cin>>a;
                if(a=='1')sum+=niu[j];
            }
            cout<<sum;
            if(i<3)cout<<".";
        }
        cout<<endl;
    }

    //while(1);
    return 0;
}

