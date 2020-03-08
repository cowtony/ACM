/*
读入英文句子，字典顺序输出每个单词出现了多少次 

用map很好实现，麻烦就在于怎样把读入的数据转化成一个一个的单词

关键词：map，字符串 
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    map<string,int> m;
    
    string s;
    while(getline(cin,s))
    {
        s.push_back(' ');
        string word;
        while(s.length()>0)
        {
            char c=s[0];
            s.erase(s.begin());
            
            if(c>='a' && c<='z')
                word.push_back(c);
            else
            {
                if(word.size()>0)m[word]++;
                word.clear();
            }
        }
    }

    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        cout<<(*it).first<<' '<<(*it).second<<endl;
        
    //while(1);
}
