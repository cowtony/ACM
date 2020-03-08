/*
输入许多电话号码，判断会不会准备打某一个电话时拨到别的电话上

题意为判断会不会有的号是另一个号的开头，如911和9112345
先读入，再排序
然后判断前一个是不是后一个的字串，且子串位置在开头
trie是啥？ 

关键词：字符串排序 
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s[10000];   
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>s[i];
            
        sort(s,s+n);
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i+1].find(s[i])==0)
            {
                cout<<"NO"<<endl;
                goto end;
            }
        }
        cout<<"YES"<<endl;
        end:;
    }
}
