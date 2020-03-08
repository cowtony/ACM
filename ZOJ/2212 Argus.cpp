/*
输入任务的代号和运行的时间间隔，按时间顺序输出前n个运行的任务代号
时间相同则用代号排序

优先队列
每“运行一个任务”，就插入一个新任务，时间是刚才任务加上时间间隔

关键词：优先队列，STL 
*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct Query
{
    int ID;
    int period;
    int sum;
    bool operator <(const Query &a)const
    {
        if(a.sum!=sum)return sum>a.sum;
        else return ID>a.ID;
    }
};

int main()
{
    priority_queue<Query> pqueue;
    
    string s;
    while(cin>>s)
    {
        if(s=="#")break;
        
        Query temp;
        cin>>temp.ID>>temp.period;
        temp.sum=temp.period;
        pqueue.push(temp);
    }
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Query temp=pqueue.top();
        pqueue.pop();
        cout<<temp.ID<<endl;
        
        temp.sum+=temp.period;
        pqueue.push(temp);
    }
    
    //while(1); 
}

