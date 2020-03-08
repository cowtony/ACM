/*
密码翻译，矩阵索引加密，很常用的，具体翻译方法看原题，输入密文和key，输出明文

题不要求算法，但是需要很高的技巧才能实现
熟练运用STL的东西能更方便的编这道题
主要的key中字母排位可以用map实现

关键词：字符串，密码，STL，map 
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;

struct Code
{
    int length;
    string plaintext;
};

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        string key,ciphertext;
        cin>>key>>ciphertext;
        
        map<char,Code> m;
        for(int i=0;i<key.length();i++)
        {
            Code c;
            c.length=ciphertext.length()/key.length();
            if(i<ciphertext.length()%key.length())
                c.length++;
            m[key[i]]=c;
        }
            
        map<char,Code>::iterator it;
        int point=0;
        for(it=m.begin();it!=m.end();it++)
        {
            int length=(*it).second.length;
            string s;
            for(int i=0;i<length;i++,point++)
                s.push_back(ciphertext[point]-'A'+'a');
            
            (*it).second.plaintext=s;
        }
        
        for(int i=0;i<ciphertext.length();i++)
        {
            string &s=m[key[i%key.length()]].plaintext;
            cout<<s[0];
            s.erase(s.begin());
        }
        cout<<endl;
    }
    //while(1);
}
