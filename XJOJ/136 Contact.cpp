/*
有一个01串，统计出所有长度在A与B之间的前N个频度的子串

因为子串最长长度为12，所以所有的子串可以枚举出来，为了区分0和00这样的子串，给所有的串前加前导1
开一个数组，长度为2^14，这样就可以存下所有子串的频度
利用位运算可以快速扫过所有的子串，统计完之后用优先队列排序
输出格式比较麻烦

关键词：字符串，STL 
*/
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

struct Info
{ 
    int frequentness;
    string s;
    Info(int a=0,string b=""):frequentness(a),s(b){}
    bool operator <(const Info &a)const
    {
        if(frequentness==a.frequentness)
            if(s.length()==a.s.length())
            {
                for(int i=0;i<s.length();i++)
                    if(s[i]!=a.s[i])return s[i]>a.s[i];
            }
            else return s.length()>a.s.length();
        else return frequentness<a.frequentness;
    }
};

string translate(int n)
{
    string s;
    while(n>1)
    {
        s+=(n&1)+'0';
        n>>=1;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    int A,B,N;
    cin>>A>>B>>N;
    
    int code[200000];
    int length=0;
    char c;
    while(cin>>c)code[length++]=c-'0';
    
    if(B>length)B=length;
    
    int F[13]={0};
    int count[16384]={0};
    
    for(int i=A;i<=B;i++)
    {
        for(int j=0;j<i;j++)
            F[i]=(F[i]<<1)+code[j];
        
        for(int j=i;j<length;j++)
        {
            count[F[i]|(1<<i)]++;
            F[i]=(F[i]<<1)+code[j];
            F[i]&=(1<<i)-1;
        }
        count[F[i]|(1<<i)]++;        
    }
    
    priority_queue<Info> pq;
    for(int i=0;i<16384;i++)
        if(count[i]>0)pq.push(Info(count[i],translate(i)));
    
    for(int i=0;i<N && pq.empty()==false;i++)
    {
        int count=1;
        if(pq.empty()==true)break;
        Info inf=pq.top();pq.pop();
        
        cout<<inf.frequentness<<endl;
        cout<<inf.s;
        while(pq.top().frequentness==inf.frequentness && pq.empty()==false)
        {
            inf=pq.top();pq.pop();
            count++;
            if(count%6==1)cout<<endl<<inf.s;
            else cout<<' '<<inf.s;
        }
        cout<<endl;
    }
}
