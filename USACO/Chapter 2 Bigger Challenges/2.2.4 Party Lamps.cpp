/*
ID:cowtony1
PROG:lamps
LANG:C++
有N个起初是亮着的灯，操作1可以改变所有灯的状态，操作2可以改变所有奇数灯的状态，
操作3可以改变所有偶数灯的状态，操作4可以改变1+3k的状态
已知做了C次操作和一些灯的末状态，求所有可能的状态

每个操作做两次等于没做，所有共有2^4=16种方案
又因为操作123等于没做，所以只有0=123,1=23,2=13,3=12,4=1234,14=234,24=134,34=124八种状态
当c=0时，只有不操作这一种
当c=1时，只有1,2,3,4四种
当c=2时，只有4这个状态不行（可以看上面）
当c=3时，其实是c=1+2，所以任何一种都行，其实c>=3后任何一种都行
另外所有操作的最小公倍数是6，所以灯泡一定是六个一循环的
然后工作就简单了~

关键词：巧算法，枚举 
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
