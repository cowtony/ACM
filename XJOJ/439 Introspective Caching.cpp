/*
给出高速缓冲cache的容量c，还有数据的种类n，以及未来需要读取的a个数据
刚开始的时候cache是空的，从缓冲读取数据不要时间，如果要读的数据缓冲里没有，则费一个时间，求最少时间

用结构体数组存下第i个数据的编号以及出现下一个该数据的时间
用两个set作为cache，一个以ID排序，一个以next排序
如果cache满了就删掉下次出现最晚的那个元素，然后加入新元素
如果现有元素在cache内有，那么要更新该元素的下次出现时间 
细心做，很难想，复杂得很，对时间要求也很高

关键词：贪心，模拟，STL，复杂 
*/
#include<iostream>
#include<set>
using namespace std;

struct Info
{
    int next;
    int ID;
    
    bool operator <(const Info& i)const
    {
        if(next==i.next)return ID<i.ID;
        else return next<i.next;
    }
};

int main()
{
    int c,n,a;
    cin>>c>>n>>a;
    
    Info access[100000];
    for(int i=0;i<a;i++)
        scanf("%d",&access[i].ID);

    int next[100000]={0};   
    for(int i=a-1;i>=0;i--)
    {
        if(next[access[i].ID]>i)
            access[i].next=next[access[i].ID];
        else access[i].next=a;
        next[access[i].ID]=i;
    }
    
    set<Info> m;
    set<int> s;
    int time=0;
    for(int i=0;i<a;i++)
        if(s.find(access[i].ID)==s.end())
        {
            if(s.size()==c)
            {
                set<Info>::reverse_iterator rit=m.rbegin();
                s.erase((*rit).ID);
                m.erase(*rit);
            }
            time++;
            s.insert(access[i].ID);
            m.insert(access[i]);
        }
        else 
        {
            for(set<Info>::iterator it=m.begin();it!=m.end();it++)
                if((*it).ID==access[i].ID){m.erase(*it);break;}
            m.insert(access[i]);
        }
    
    cout<<time<<endl;
    //while(1);
} 
