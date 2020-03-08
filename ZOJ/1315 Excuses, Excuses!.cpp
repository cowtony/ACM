/*
先输入几个单词作为关键字，再输入几个句子，输出关键字出现次数最多的句子

这道题很复杂，读入数据就比较要求技巧
另外将读入的句子转成单词也比较麻烦
转成单词以后和关键字比较就行了
输出格式上要求每个testcase间空一行，以前有的题要求最后一个testcase不要输出多余的空行
这道题没要求，不仅没要求而且那样输出了还算presentation error 
<ctype.h>是啥？ 

关键词：字符串，很复杂很考技巧的题 
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int calculate(string key[],int k,string excuse)
{
    vector<string> word(71);
    int count=0;
    while(excuse.length()>0)
    {
        if(excuse[0]>='A' && excuse[0]<='Z')
            excuse[0]=excuse[0]-'A'+'a';
        if(excuse[0]>='a' && excuse[0]<='z')
            word[count]+=excuse[0];
        else count++;
        excuse.erase(excuse.begin());
    }
    
    int c=0;
    vector<string>::iterator it;
    for(it=word.begin();it!=word.end();it++)
        for(int i=0;i<k;i++)
            if(key[i]==*it){c++;break;}
    
    return c;
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    int k,e;
    int set=1;
    while(cin>>k>>e)
    {
        cout<<"Excuse Set #"<<set++<<endl;
                    
        string key[20];
        for(int i=0;i<k;i++)
        {
            cin>>key[i];
            for(int j=0;j<key[i].length();j++)
                if(key[i][j]>='A' && key[i][j]<='Z')
                    key[i][j]=key[i][j]-'A'+'a';
        }
        cin.ignore();
        
        int excuse[20]={0};
        string s[20];
        int max=0;
        for(int i=0;i<e;i++)
        {   
            char ex[71];
            
            cin.getline(ex,71);
            s[i]=ex;
            
            excuse[i]=calculate(key,k,s[i]);
            if(excuse[i]>max)max=excuse[i];
        }
        for(int i=0;i<e;i++)
            if(max==excuse[i])
                cout<<s[i]<<endl;
                
        cout<<endl;
    }
    //while(1);
}
