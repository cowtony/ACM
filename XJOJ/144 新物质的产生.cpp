/*
输入许多化学式，和已有的化学药品，字典顺序输出通过这些化学式可以产生多少新药品

读入数据是个很麻烦的问题，但是不难，一点一点编就能做出来
读完数据以后就模拟，一个一个的枚举。一遍一遍的重复直到某一次遍历所有化学式都没有新物质产生了

关键词：模拟，字符串，STL 
*/
#include<iostream>
#include<set>
#include<vector> 
using namespace std;

int main()
{
    //freopen("10","r",stdin);
    
    set<string> have;//表示现在有的药品 
    set<string> news;//存下最初的，因为最后只要求输出新生成的 
    vector<string> reactant[2][400];//[0][i]表示第i个化学式的反应物列表，[1][i]表示第i个化学式的生成物列表 
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s,a;
        cin>>s;
        bool flag=0;
        
        while(s.length()>0)
        {
            char c=*s.begin();
            s.erase(s.begin());
            
            if(c=='=')
            {
                reactant[flag][i].push_back(a);
                a.clear();
                flag=1;
            }
            else if(c=='+')
            {
                reactant[flag][i].push_back(a);
                a.clear();
            }
            else a.push_back(c);
        }
        reactant[flag][i].push_back(a);
    }//读入化学式 
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        have.insert(s);
    }//读入已有化学药品
    news=have;
    
    bool judge[400]={false};
    bool flag=true;
    while(flag==true)
    {
        flag=false;
        for(int i=0;i<n;i++)
        {
            if(judge[i]==false)
            {
                for(int j=0;j<reactant[0][i].size();j++)
                    if(have.find(reactant[0][i][j])==have.end())goto end;
                //判断是不是反应物都有    
                for(int j=0;j<reactant[1][i].size();j++)
                    have.insert(reactant[1][i][j]);
                //把生成物也加到目前所有的列表    
                flag=true;
                judge[i]=true;
            }
            end:;
        }
    }
    
    set<string>::iterator it;
    for(it=news.begin();it!=news.end();it++)
        have.erase(*it);
    
    cout<<have.size()<<endl;
    for(it=have.begin();it!=have.end();it++)
        cout<<*it<<endl;
        
    //while(1);
}
