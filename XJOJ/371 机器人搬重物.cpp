/*
看原题

迷宫问题，类似的XJOJ 302
只不过这个迷宫题稍微麻烦一些，告诉你机器人是直径1.6米的圆意味着路的宽度变成2了
所以对于输入的矩阵数据要进行一些转化，就可以变成普通的迷宫图了
转化后的坐标意义不再是小方格，而是十字交叉点

times[i][j][k]表示从起点走到[i][j]这个点在k方向时的最少时间
初值所有的都为无限大，只有起点以及方向为0
然后对于每个计算过的点，算出他直走x<=3步，左转，右转状态的时间
和原状态取最小值
最后看结束点的值即可 

关键词：动态规划，迷宫 
*/
#include<iostream>  
using namespace std;  

int main()  
{  
    //freopen("aaa.txt","r",stdin);
    
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int m,n;
    cin>>m>>n;
    
    bool map[56][56];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>map[i][j];
    //读入原地图 
    
    bool nmap[56][56];
    for(int i=1;i<=m-1;i++)  
        for(int j=1;j<=n-1;j++)
            nmap[i][j]=!(map[i][j] || map[i][j+1] || map[i+1][j] || map[i+1][j+1]);
    //计算后的新地图。1表示可走，0表示不可走 
    
    int start[2],end[2],direction;        
    cin>>start[0]>>start[1]>>end[0]>>end[1];
    char c;
    cin>>c;
    switch(c)
    {
        case'E':direction=0;break;
        case'S':direction=1;break;
        case'W':direction=2;break;
        case'N':direction=3;break;
    }
    
    int times[56][56][56];
    for(int i=0;i<m;i++)  
        for(int j=0;j<n;j++)  
            for(int k=0;k<4;k++)  
                times[i][j][k]=10000;  
    times[start[0]][start[1]][direction]=0;
    //初始化 

    bool flag=true;
    while(flag)  
    {  
        flag=false;
        for(int i=1;i<m;i++)  
            for(int j=1;j<n;j++)  
                for(int k=0;k<4;k++)  
                    if(nmap[i][j] && times[i][j][k]<10000)  
                    {  
                        for(int t=1;t<=3 && nmap[i+t*dx[k]][j+t*dy[k]];t++)
                            if(times[i+t*dx[k]][j+t*dy[k]][k]>times[i][j][k]+1)  
                            {  
                                times[i+t*dx[k]][j+t*dy[k]][k]=times[i][j][k]+1;  
                                flag=true;  
                            }//走1步，走2步，走3步 
                        
                        if(times[i][j][(k+1)%4]>times[i][j][k]+1)  
                        {  
                            times[i][j][(k+1)%4]=times[i][j][k]+1;  
                            flag=true;  
                        }//右转 
                        if(times[i][j][(k+3)%4]>times[i][j][k]+1)  
                        {  
                            times[i][j][(k+3)%4]=times[i][j][k]+1;  
                            flag=true;  
                        }//左转 
                    }  
    }
    
    int mins=10000;
    for(int k=0;k<4;k++)
        if(mins>times[end[0]][end[1]][k])mins=times[end[0]][end[1]][k];
        
    if(mins==10000 || nmap[start[0]][start[1]]==0)cout<<"-1"<<endl;  
    else cout<<mins<<endl;  
        
    //while(1);
}
