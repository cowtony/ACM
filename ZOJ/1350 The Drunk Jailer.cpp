/*
有n牢房起初是关着的，监狱长先把1的倍数号反转（全部打开），再把2的倍数号反转，以此类推直到n，求最后有几个牢房是开着的

用bool数组直接模拟就可以了，有点像筛法

关键词：简单题，模拟 
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        bool cell[101]={false};
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j+=i)
                cell[j]=!cell[j];
                
        int prisoner=0;
        for(int i=1;i<=n;i++)
            if(cell[i]==true)prisoner++;
            
        cout<<prisoner<<endl;
    }
} 
