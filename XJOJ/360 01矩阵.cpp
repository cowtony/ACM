/*
判断一个bool矩阵能否通过若干次行取反及列取反变为全零或全一矩阵，输出最少次数

由于每个元素行列不能交换位置，所以先把第一列通过行取反变为全部一样的
然后看剩下几列，如果可以只通过列取反达成目的即代表可行（每列元素一样） 
所以对第一列进行行取反的时候，最少的次数是第一列中个数最少的那个数字的个数
对矩阵进行列取反的时候，最少次数也是最少的那个元素列的个数
两个一加就是总最少次数

关键词：有思想 
*/
#include<iostream>
using namespace std;

int m,n;

int trans(bool t[][1000])
{
    bool matrix[1000][1000];
    memcpy(matrix,t,sizeof(matrix));
    
    int count=0;
    for(int i=0;i<m;i++)
        if(matrix[i][0]!=0)
        {
            for(int j=0;j<n;j++)
                matrix[i][j]=!matrix[i][j];
            count++;
        }
    count=min(count,m-count);
    
    int count2=0;
    for(int j=0;j<n;j++)
    {
        for(int i=1;i<m;i++)
            if(matrix[i][j]!=matrix[i-1][j])return -1;
        if(matrix[0][j]!=0)
            count2++;
    }
    count2=min(count2,n-count2);
    
    return count+count2;
}

int main()
{
    cin>>m>>n;
    
    bool matrix[1000][1000];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            matrix[i][j]=c-'0';
        }
        
    int steps=trans(matrix);
    
    cout<<steps<<endl;
    //while(1);
}
