/*
赢一场比赛得3分，平一场得1分，输一场不得分。
已知还要比赛N场，并且知道以前比赛赢了几场，平了几场，输了几场（拿这个可以算出概率）
求在以后N场中至少得P分的概率

先根据以前的数据算出赢一场的概率，还有平和输的
然后枚举N场比赛所有可能的组合（赢的场数，平的场数） 
对于每一种组合，如果得分大于等于P，则把这种组合的概率加上
概率的算法：C(N,win)*pow(p_win,win)*C(N-win,draw)*pow(p_draw,draw)*pow(p_lose,lose);
输出有要求

关键词：模拟，概率题 
*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int C(int a,int b)
{
    if(b==0 || b==a)return 1;
    
    return C(a-1,b-1)+C(a-1,b);
}

int main()
{
    int N,P;
    while(cin>>N>>P)
    {
        if(N==0 && P==0)break;
        
        int W,D,L;
        cin>>W>>D>>L;
        
        double p_win=double(W)/(W+D+L);
        double p_draw=double(D)/(W+D+L);
        double p_lose=double(L)/(W+D+L);

        double p=0;
        for(int win=0;win<=N;win++)
            for(int draw=0;draw<=N-win;draw++)
            {
                int lose=N-win-draw;
                int point=3*win+draw;
                if(point>=P)
                    p+=C(N,win)*pow(p_win,win)*C(N-win,draw)*pow(p_draw,draw)*pow(p_lose,lose);
            }
        
        cout.precision(1);
        cout<<fixed<<p*100<<endl;
    }
} 
