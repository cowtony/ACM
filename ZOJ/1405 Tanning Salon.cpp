/*
salon里有n张床，有一个顾客列表，表明顾客的进和出的顺序，如果某个顾客进来时没有位子，他就走了
求有多少顾客walk away？

用一个set类表示一个沙龙里的位子
用string类表示队列字符串
每次从队头提取一个字符（人），判断沙龙里是否有这个人
有的话就让沙龙里的这个人离开
没有的话再判断salon里是否满员，没满就把这个人加到沙龙里
满了就count++，并且把队列里的表示这个人离开的字符也删掉

关键词：模拟，STL，队列 
*/
#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int bed;
    while(cin>>bed)
    {
        if(bed==0)break;
        
        string Queue;
        cin>>Queue;
            
        set<char> salon;
        int count=0;
        while(Queue.size()>0)
        {
            char next=Queue[0];
            Queue.erase(Queue.begin());//提取队列的下一个人 
            
            if(salon.find(next)!=salon.end())//如果找到了salon里有相同的人 
                salon.erase(next);//这个人离开 
            else if(salon.size()<bed)//如果salon里还有空位
                salon.insert(next);
            else//满了 
            {
                Queue.erase(Queue.begin()+Queue.find(next));
                count++;
            }
        }
        
        if(count==0)cout<<"All customers tanned successfully."<<endl;
        else cout<<count<<" customer(s) walked away."<<endl;
    }
}
