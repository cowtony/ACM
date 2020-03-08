/*
对许多字符串进行排序，排序的主键是某一个字符串右边字母小于左边字母的个数 

用到了sort，自定义比较函数，程序就很简洁了

关键词：排序，STL，字符串 
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool compare(string s1,string s2)
{
    int c1=0,c2=0;
     
    for(int i=0;i<s1.length();i++)
        for(int j=i+1;j<s1.length();j++)
            if(s1[i]>s1[j])c1++;
    
    for(int i=0;i<s2.length();i++)
        for(int j=i+1;j<s2.length();j++)
            if(s2[i]>s2[j])c2++;
    
    return c1<c2;
}

int main()
{
    int testcase;
    cin>>testcase;
    
    while(testcase--)
    {
        vector<string> s;

        int n,m;
        cin>>n>>m;
        
        for(int i=0;i<m;i++)
        {        
            string temp;
            cin>>temp;
            s.push_back(temp);
        }
        
        sort(s.begin(),s.end(),compare);
        
        for(int i=0;i<m;i++)
            cout<<s[i]<<endl;
        
        if(testcase>0)cout<<endl;
    }
}
