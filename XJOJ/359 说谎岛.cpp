/*
问每个人两个问题，每个人回答一真一假。求最后结果的可能性有多少种

用并查集的思想，建立vertex并查集，初始时互相毫无关系
还有answer数组表示每个题的答案
如果两个题不在同一集合，就合并集合，并且顺便把答案也规整一下（小重点）
如果两个题在同一集合，就判断一下是否矛盾
最后假设剩有t个集合，可能性就是2^t
答案很大，要用高精度 

关键词：位运算，并查集，高精度 
*/
#include<iostream>
#include<set>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    
    bool answer[201]={false};
    int vertex[201];
    for(int i=1;i<=M;i++)
        vertex[i]=i;
        
    for(int i=0;i<N;i++)
    {
        int q1,q2;
        bool a1,a2;
        cin>>q1>>a1>>q2>>a2;
        
        if(vertex[q1]!=vertex[q2])
        {
            bool inverse=!((a1^a2)^(answer[q1]^answer[q2]));
            int t=vertex[q2];
            
            for(int i=1;i<=M;i++)
                if(vertex[i]==t)
                {
                    vertex[i]=vertex[q1];
                    answer[i]=inverse^answer[i];
                }
        }
        else if((a1^a2)==(answer[q1]^answer[q2]))
        {
            cout<<"NO ANSWER"<<endl;
            return 0;
        }
    }
    
    set<int> s;
    for(int i=1;i<=M;i++)
        s.insert(vertex[i]);
    
    int digit[10000]={1};
    int length=1;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<length;j++)
            digit[j]*=2;
        for(int j=0;j<length;j++)
            if(digit[j]>9)
            {
                digit[j+1]+=digit[j]/10;
                digit[j]%=10;
            }
        if(digit[length]>0)length++;
    }
    for(int i=length-1;i>=0;i--)
        cout<<digit[i];
}
