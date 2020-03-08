/*
用小于K的数位构成一个最小的十进制数，是M的倍数

广度优先搜索，深度是数字的位数，广度是该位是几
每次把原来的数字乘以十再加上新的个位，所以余数也是原来的余数乘以十再加个位
但是还要做一些优化，因为M<1000，所以余数不会超过一千，队列的长队也不会超过一千
记录下出现过的余数，如果以后遇见相同余数的数字直接舍弃不用入队

关键词：广度优先搜索 
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct State
{
    vector<int> data;
    int mod;
    State(int i,int m)
    {
        data.push_back(i);
        mod=m;
    }
    void output()
    {
        for(int i=0;i<data.size();i++)
            cout<<data[i];
    }
};

int main()
{
    int K,M;
    cin>>K>>M;
    
    bool flag[1001]={false};
    
    queue<State> q;
    for(int i=1;i<K;i++)
    {
        State s(i,i%M);
        if(s.mod==0)
        {
            s.output();
            return 0;
        }
        else if(flag[s.mod]==false)
        {
            q.push(s);
            flag[s.mod]=true;
        }
    }
        
    while(q.size()>0)
    {
        for(int i=0;i<K;i++)
        {
            State s=q.front();
            s.data.push_back(i);
            s.mod=(s.mod*10+i)%M;
            
            if(s.mod==0)
            {
                for(int i=0;i<s.data.size();i++)
                    cout<<s.data[i];
                return 0;
            }
            else if(flag[s.mod]==false)
            {
                q.push(s);
                flag[s.mod]=true;
            }
        }
        q.pop();
    }
}
