/*
ID:cowtony1
PROG:barn1
LANG:C++

��S��ţ��е�ţ������ţ������Cͷţ������Ҫ��ľ��������е�ţ��Ҫ��ľ�����M�飬��ľ�����ٶ೤

�϶���ľ��M����ã�Ҳ������M-1����϶
���������ţ��ĳ��ȣ����������M-1��������ʡľ��
ע�⵱M>=Cʱֱ�����C������ 

�ؼ��ʣ�̰��
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    
    int M,S,C;
    cin>>M>>S>>C;
    
    bool cow[201]={0};
    for(int i=0;i<C;i++)
    {
        int t;
        cin>>t;
        cow[t]=true;
    }
    
    vector<int> v;
    int c=0;
    for(int i=1;i<=S;i++)
        if(cow[i]==false)c++;
        else
        {
            v.push_back(c);
            c=0;
        }
    v.push_back(c);
    
    int sum=S-v[0]-v[v.size()-1];
    v.erase(v.begin());
    v.erase(v.end()-1);
    sort(v.begin(),v.end(),greater<int>());

    for(int i=0;i<M-1;i++)
        sum-=v[i];
    
    if(M>=C)cout<<C<<endl;
    else cout<<sum<<endl;
}
