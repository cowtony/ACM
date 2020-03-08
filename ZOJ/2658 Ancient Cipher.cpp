/*
把原文通过先替换字母，然后交换字母位置的方式加密，输入密文和原文，输出原文是否可以加密成该密文

读入密文和原文字符串
把它们放入multiset中
然后开始删除set的第一个元素，直到删空为止
删除某元素时会返回一共删了几个元素，代表字符串中有几个这样相同的字母
把返回的值加入vector中排序
两个字符串会得到两个vector，当且仅当这两个vector完全相同时才输出yes

关键词：密码，字符串，STL 
*/
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        multiset<char> encrypt,original;
        while(s1.length()>0)
        {
            encrypt.insert(s1[0]);
            s1.erase(s1.begin());
        }
        while(s2.length()>0)
        {
            original.insert(s2[0]);
            s2.erase(s2.begin());
        }
        
        vector<int> a,b;
        while(encrypt.size()>0)
            a.push_back(encrypt.erase(*encrypt.begin()));
        while(original.size()>0)
            b.push_back(original.erase(*original.begin()));
            
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        if(a==b)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
