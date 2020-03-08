/*
输入许多灯的开关状态，输出让他们相间亮所需的最少改变数

两种情况，101010...和01010...
分别算两种情况所需的数目，输出最少的

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        bool light[10000];
        for(int i=0;i<n;i++)
            cin>>light[i];
            
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(light[i]!=i%2)a++;
            if(light[i]!=(i+1)%2)b++;
        }
        
        if(a>b)cout<<b<<endl;
        else cout<<a<<endl;
    }
}
