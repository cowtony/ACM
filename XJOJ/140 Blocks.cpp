/*
要把N单位个立方体包装成长方体，求最小表面积

枚举分解N的长宽高，记录下面积最小的解法即可

关键词：枚举，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int C,N;
    cin>>C;
    while(cin>>N)
    {
        int surface=INT_MAX;
        for(int i=1;i*i*i<=N;i++)
            for(int j=i;i*j*j<=N;j++)
                if(N%(i*j)==0)
                {
                    int k=N/(i*j);
                    surface=min(surface,i*j+j*k+i*k);
                }
        cout<<2*surface<<endl;
    }
}
