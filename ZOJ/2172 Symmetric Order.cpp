/*
输入许多名字，交叉输出，就是第一个，第三个。。。直到末尾，再从后向前输出

用vector的插入，读数据的时候就插着读
然后直接输出

关键词：STL，简单题 
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n;
    int c=1;
    while(cin>>n)
    {
        if(n==0)break; 
                   
        vector<string> v;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            v.insert(v.begin()+(i+1)/2,s);
        }
        
        cout<<"SET "<<c++<<endl;
        for(int i=0;i<n;i++)
            cout<<v[i]<<endl;
    } 
}

