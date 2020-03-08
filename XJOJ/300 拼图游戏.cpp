/*
求解一个三阶拼图的最少步数

这个是用广度优先搜索做的，直接搜的话中间会出现许多重复状态，用一个set记录可以避免重复状态进入队列
我写了一个记录棋盘状态的类
这个题更好的解法是双向广度搜索和A*启发式搜索

关键词：广度优先搜索，A*启发式搜索 
*/
#include<iostream>
#include<queue>
#include<set>
using namespace std;

enum Forward{f_up,f_down,f_left,f_right,f_null};

struct Board
{
    int data[3][3];
    int row,column;//the position of zero
    int step;
    Forward last;//上一次走的方向
    
    void input()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                cin>>data[i][j];
                if(data[i][j]==0){row=i;column=j;}
            }
        step=0;
        last=f_null;
    }
    bool operator <(const Board b)const
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(data[i][j]!=b.data[i][j])
                    return data[i][j]<b.data[i][j];
        return false;
    }//为了用set定义了一个比较函数 
    bool move(Forward f)
    {
        switch(f)
        {
            case f_up:
                if(row<=0 || last==f_down)return false;
                data[row][column]=data[row-1][column];
                row--;break;
            case f_down:
                if(row>=2 || last==f_up)return false;
                data[row][column]=data[row+1][column];
                row++;break;
            case f_left:
                if(column<=0 || last==f_right)return false;
                data[row][column]=data[row][column-1];
                column--;break;
            case f_right:
                if(column>=2 || last==f_left)return false;
                data[row][column]=data[row][column+1];
                column++;break;
        }
        data[row][column]=0;
        step++;last=f;
        return true;
    }//向某一方向移动一步 
    bool judge()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(data[i][j]!=(i*3+j+1)%9)return false;
        return true;
    }//判断是否到最终状态 
};

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Board start;start.input();
        queue<Board> q;q.push(start);
        set<Board> s;s.insert(start);
        
        while(q.size()>0)
        {
            Board f[4];
            f[0]=f[1]=f[2]=f[3]=q.front();
            q.pop();
            
            for(int i=0;i<4;i++)
                if(f[i].move(Forward(i))==true)
                    if(s.find(f[i])==s.end())
                        if(f[i].judge()==true)
                        {cout<<f[i].step<<endl;goto end;}
                        else{q.push(f[i]);s.insert(f[i]);}
        }
        end:;
    }
}
