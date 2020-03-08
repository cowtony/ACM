/*
读入字典的单词，再读入形如(ab)(cd)e(sdf)的模板，求该模板有几个单词在字典中

先读入数据，读模板的时候有些麻烦，把每一位字母用一个string存，表示该位可用的字母
起初我的想法是遍历模板所有可能的单词，在字典中查找看能找到不，还写了很帅的递归函数（如下），但是超时
真正的做法是遍历所有的单词，把单词全部代到模板里，看有几个符合

关键词：字符串 
*/

/*
set<string> dictionary;
string character[15];

int search(string *character,string present="")
{
    if(present.length()==L)
        return dictionary.find(present)!=dictionary.end();

    int count=0;
    for(int i=0;i<(*character).length();i++)
        count+=search(character+1,present+(*character)[i]);
    return count;
}

cout<<search(character)<<endl;
//这是一段很经典的代码，可以用递归遍历出模板的所有可能字符串，最终返回找到的单词个数，不忍删去 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int L,D,N;
    cin>>L>>D>>N;
    
    string dictionary[5000]; 
    for(int i=0;i<D;i++)
        cin>>dictionary[i];//读入字典 
    
    while(N--)
    {
        string character[15];
        for(int i=0;i<L;i++)
        {
            char c;
            cin>>c;
            if(c=='(')
            {
                cin>>c;
                do
                {
                    character[i]+=c;
                    cin>>c;
                }while(c!=')');
            }
            else character[i]+=c;
        }//读入数据
        
        int count=0;
        for(int i=0;i<D;i++)
        {
            bool judge=true;
            for(int j=0;j<L;j++)
            {
                char c=dictionary[i][j];
                if(character[j].find(c)==-1)//没找到 
                {
                    judge=false;
                    break;
                }
            }
            if(judge==true)count++;
        }
        cout<<count<<endl;
    }
    
    //while(1);
}
