/*
地图上找金子，碰见相邻有陷阱的就得原路返回，求最多找几个金子 

类似于ZOJ 1709的题，同样的方法去做
这道题多了一个条件就是“陷阱”

关键词：地图，递归搜索 
*/
#include<iostream>
using namespace std;

int w,h;
char map[50][50];
int gold=0;

void search(int row,int column)
{
    map[row][column]='#';
    
    if(map[row-1][column]=='T' || map[row+1][column]=='T' || map[row][column-1]=='T' || map[row][column+1]=='T')
        return;
        
    if(map[row-1][column]!='#')
    {
        if(map[row-1][column]=='G')gold++;
        search(row-1,column);
    }
    if(map[row+1][column]!='#')
    {
        if(map[row+1][column]=='G')gold++;
        search(row+1,column);
    }
    if(map[row][column-1]!='#')
    {
        if(map[row][column-1]=='G')gold++;
        search(row,column-1);
    }
    if(map[row][column+1]!='#')
    {
        if(map[row][column+1]=='G')gold++;
        search(row,column+1);
    }
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    cin>>w>>h;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>map[i][j];
            
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            if(map[i][j]=='P')
                search(i,j);

    cout<<gold<<endl;
    
    //while(1);
} 
