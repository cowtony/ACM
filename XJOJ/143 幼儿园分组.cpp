/*
读入幼儿园小朋友的好朋友列表，把他们分成两组，要求每个人都至少有一个好朋友在另一个组
输出其中一组

直接构造就可以，用个set存下另一个组的人
然后从第一个小朋友开始，看他在不在另一个组
不在的话看他的朋友是不是都不在另一个组
如果都不在就随便拉他一个朋友过去
就可以了

关键词：模拟，STL 
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
    set<int> group;
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        vector<int> friends;
        int k;
        while(cin>>k && k>0)
            friends.push_back(k);
            
        if(group.find(i)==group.end())
        {
            for(int j=0;j<friends.size();j++)
                if(group.find(friends[j])!=group.end())
                    goto end;
            
            group.insert(friends[0]);
        }
        end:;
    }

    cout<<group.size()<<endl;
    set<int>::iterator it=group.begin();
    cout<<*it;
    for(it++;it!=group.end();it++)
        cout<<' '<<*it;
        
    //while(1);
}
