/*
ID:cowtony1
PROG:lamps
LANG:C++
��N����������ŵĵƣ�����1���Ըı����еƵ�״̬������2���Ըı����������Ƶ�״̬��
����3���Ըı�����ż���Ƶ�״̬������4���Ըı�1+3k��״̬
��֪����C�β�����һЩ�Ƶ�ĩ״̬�������п��ܵ�״̬

ÿ�����������ε���û�������й���2^4=16�ַ���
����Ϊ����123����û��������ֻ��0=123,1=23,2=13,3=12,4=1234,14=234,24=134,34=124����״̬
��c=0ʱ��ֻ�в�������һ��
��c=1ʱ��ֻ��1,2,3,4����
��c=2ʱ��ֻ��4���״̬���У����Կ����棩
��c=3ʱ����ʵ��c=1+2�������κ�һ�ֶ��У���ʵc>=3���κ�һ�ֶ���
�������в�������С��������6�����Ե���һ��������һѭ����
Ȼ�����ͼ���~

�ؼ��ʣ����㷨��ö�� 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string state[8];
bool on[6]={0},off[6]={0};

bool check(int n)
{
    for(int i=0;i<6;i++)
    {
        if(on[i]==true && state[n][i]=='0')return false;
        if(off[i]==true && state[n][i]=='1')return false;
    }
    return true;
}

int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    
    int N,C;
    cin>>N>>C;
    
    int n;
    while(cin>>n && n!=-1)
        on[(n-1)%6]=true;
    while(cin>>n && n!=-1)
        off[(n-1)%6]=true;

    state[0]="111111";
    state[1]="000000";
    state[2]="010101";
    state[3]="101010";
    state[4]="011011";
    state[5]="100100";
    state[6]="110001";
    state[7]="001110";
    
    vector<string> v;
    switch(C)
    {
        default:
            if(check(4))v.push_back(state[4]);
        case 2:
            if(check(5))v.push_back(state[5]);
            if(check(6))v.push_back(state[6]);
            if(check(7))v.push_back(state[7]);
        case 1:
            if(check(1))v.push_back(state[1]);
            if(check(2))v.push_back(state[2]);
            if(check(3))v.push_back(state[3]);
            if(C==1){if(check(4))v.push_back(state[4]);break;}
        case 0:
            if(check(0))v.push_back(state[0]);
    }
    sort(v.begin(),v.end());
    
    if(v.size()==0)cout<<"IMPOSSIBLE"<<endl;
    else for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<N;j++)
            cout<<v[i][j%6];
        cout<<endl;
    }
}
