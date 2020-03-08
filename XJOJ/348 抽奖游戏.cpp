/*
看原题吧，意思很难懂，慢慢看 

动态规划，score[i]表示第i个台阶上的分数
best[i][j]表示当前所在台阶i，当前走了的步数j。
所以状态转移方程best[i][j]=max(best[i-1][j-1],best[i-2][j-1],...,best[i-K][j-1])+score[i];
意思就是说上一步的最好情况再走一步，走到了best[i][j]
最终走到best[N+1][M]

关键词：二维动态规划 
*/
#include<iostream>
using namespace std;

int main()
{ 
    int N,M,K;
    int score[102]={0};
    
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) 
        cin>>score[i];
        
    long best[102][100];
    for(int i=0;i<=N+1;i++)
        for(int j=0;j<M;j++)
            best[i][j]=-1;
    best[0][0]=0;
    
    for(int i=1;i<=N+1;i++)
        for(int j=1;j<=min(i,M);j++)
        {
            int max=0;
            for(int step=1;step<=K;step++)
                if(i>=step && max<best[i-step][j-1])max=best[i-step][j-1];
            best[i][j]=max+score[i];
        }

    cout<<best[N+1][M];
    //while(1);
}
