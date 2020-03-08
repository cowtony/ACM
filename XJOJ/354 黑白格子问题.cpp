/*
8*8的国际象棋盘，读入棋盘信息，表示哪些格子上有棋子，求白格子上有几个棋子

简单，在遍历棋盘的时候判断白格子的条件是（行数+列数为偶数） 

关键词：巧算法 
*/ 
#include<iostream>
using namespace std;

int main()
{
    char a[8][9];
    int count=0;
    
    for(int i=0;i<8;i++)
        cin>>a[i];
    
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(a[i][j]=='F' && (i+j)%2==0)count++;
    
    cout<<count;
    
    //while(1);
    return 0;
}
