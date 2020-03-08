/*
有一个串，按要求把第i个元素放到第j个位置，这些要求都是同步的，求改变后的串 

先根据要求把第i个元素放到第j个位置
然后删除掉原串中放过的元素
再在新串中按顺序补上还没放的元素

关键词：简单题，排序，STL 
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int m,n;
        cin>>m>>n;
        
        vector<string> v(m),result(m);
        for(int i=0;i<m;i++)
        {
            string s;
            cin>>s;
            v[i]=s;
        }
        
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            result[b-1]=v[a-1];
            v[a-1].clear();
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i].length()==0)
            {
                v.erase(v.begin()+i);
                i--;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(result[i].length()==0)
            {
                result[i]=*v.begin();
                v.erase(v.begin());
            }
        }
        
        cout<<result[0];
        for(int i=1;i<m;i++)
            cout<<' '<<result[i];
        cout<<endl;
    }
} 
