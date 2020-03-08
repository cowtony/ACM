/*
输入一个房子的地图，输出有几个房间，最大房间面积以及打破哪个墙可以得到最大的新房间
USACO 2.1.1

先读入数据，建立地图
然后用搜索的方法搜索出有几间房间，同时可以算出每个房间的面积并且给每个房间的地板编上房号
按顺序枚举要拆掉的墙，记录下最优的值
很考技巧的题 

关键词：搜索，恶心！ 
*/
#include<iostream>
#include<fstream>
using namespace std;

int M,N;
int map[101][101];
int room=0;
int area[10000]={0};

void input()
{
    cin>>M>>N;
    for(int i=0;i<=2*N;i++)
        for(int j=0;j<=2*M;j++)
            map[i][j]=-1;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            int row=2*i+1,column=2*j+1,a;
            cin>>a;
            map[row][column]=0;
            map[row-1][column]=-bool(a&2);
            map[row+1][column]=-bool(a&8);
            map[row][column-1]=-bool(a&1);
            map[row][column+1]=-bool(a&4);
        }
}//0是可以走的，-1是墙 

void search(int row,int column)
{
    map[row][column]=room;
    area[room]++;
    if(map[row+1][column]==0 && map[row+2][column]==0)search(row+2,column);
    if(map[row-1][column]==0 && map[row-2][column]==0)search(row-2,column);
    if(map[row][column+1]==0 && map[row][column+2]==0)search(row,column+2);
    if(map[row][column-1]==0 && map[row][column-2]==0)search(row,column-2);
}

int main()
{
    input();
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(map[2*i+1][2*j+1]==0)
            {
                room++;
                search(2*i+1,2*j+1);
            }    
    cout<<room<<endl;
    int MAX_area=0;
    for(int i=1;i<=room;i++)
        MAX_area=max(MAX_area,area[i]);
    cout<<MAX_area<<endl;
    
    int push_row,push_column;
    char push_toward;
    for(int j=0;j<M;j++)
        for(int i=N-1;i>=0;i--)
        {
            int row=2*i+1,column=2*j+1;
            if(map[row-1][column]==-1 && row-2>0)
                if(map[row][column]!=map[row-2][column])
                {
                    int temp=area[map[row][column]]+area[map[row-2][column]];
                    if(MAX_area<temp)
                    {MAX_area=temp;push_row=i+1;push_column=j+1;push_toward='N';}
                }
            if(map[row][column+1]==-1 && column+2<2*M)
                if(map[row][column]!=map[row][column+2])
                {
                    int temp=area[map[row][column]]+area[map[row][column+2]];
                    if(MAX_area<temp)
                    {MAX_area=temp;push_row=i+1;push_column=j+1;push_toward='E';}
                }
        }
        
    cout<<MAX_area<<endl;
    cout<<push_row<<' '<<push_column<<' '<<push_toward<<endl;
}
