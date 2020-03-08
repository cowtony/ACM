/*
对windows消息队列的处理，读入消息，为名称，数据，优先级，get的时候输出最大的

其实就是优先队列，用STL一做就行了
但是用cin什么的会超时

关键词：STL，优先队列 
*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct Message
{
    char Name[100];
    int Data;
    int Priority;
    
    bool operator<(const Message &a)const
    {
        return a.Priority<Priority;
    }
};

int main()
{
    char message[4];
    priority_queue<Message> v;
    
    while(scanf("%s",&message)!=EOF)
    {
        if(strcmp(message,"PUT")==0)
        {
            Message temp;
            scanf("%s%d%d",&temp.Name,&temp.Data,&temp.Priority);
            v.push(temp);
        }
        else
        {
            if(v.size()==0)printf("EMPTY QUEUE!\n");
            else 
            {
                printf("%s %d\n",v.top().Name,v.top().Data);
                v.pop();
            }
        }
    }
} 
