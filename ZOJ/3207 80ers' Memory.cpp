/*
输入一些字符串，再输入一些字符串，看有多少个是上面出现过的

用个set存下来模拟就可以了

关键词：简单题，STL 
*/
#include<iostream>
#include<set>
using namespace std;

int main()
{
    int N;
    cin>>N;
    set<string> s;
    while(N--)
    {
        string c;
        cin>>c;
        s.insert(c);
    }
    
    int K;
    cin>>K;
    while(K--)
    {
        int n;
        cin>>n;
        int count=0;
        while(n--)
        {
            string c;
            cin>>c;
            if(s.find(c)!=s.end())count++;
        }
        cout<<count<<endl;
    }
}
