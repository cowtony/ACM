/*
输入矩阵，每个数表示草长得高度，要求至少有为零的块，且为零的块不能相邻

读入数据，然后一个一个的判断，两个flag，一个用来判断第一个条件
另一个用来判断第二个条件
为了更方便的判断某一块的上下左右，给本身的矩阵外加一个数据不为零的边框
这样编程就比较好实现

关键词：不算太简单的简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int N,M;
    while(cin>>N>>M)
    {
        if(N==0 && M==0)break;
        
        int meadow[12][12];
        for(int i=0;i<12;i++)
            for(int j=0;j<12;j++)
                meadow[i][j]=1;
                
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                cin>>meadow[i][j];
             
        bool zero=false;
        bool beautiful=true;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                if(meadow[i][j]==0)
                {
                    zero=true;
                    if(meadow[i-1][j]==0)beautiful=false;
                    if(meadow[i+1][j]==0)beautiful=false;
                    if(meadow[i][j-1]==0)beautiful=false;
                    if(meadow[i][j+1]==0)beautiful=false;
                }
        if(zero==true && beautiful==true)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
} 
