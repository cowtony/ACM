/*
输入n阶方阵，有'.'和'#'组成，求纯由'.'构成的矩形有多少个

1.先读入数据（改写为1,0格式），存入original[n][n]数组 
2.然后将数组改写为“每个元素包括自身向左有多少个连续的1”
  比如原数组的第一行为1110011，改写完就是1230012
3.再新建一个数组rectangular[n][n]，意义是以i,j为右上角顶点的矩形有多少个
  从i,j点往下找，每次加上当前的最小值就可以了。这个画一画就能明白
  比如矩阵（如下）
  111111
  001111
  000111
  111111
  它的最右上角点值为6，代表(1,1)-(1,6) (1,2)-(1,6) (1,3)-(1,6) (1,4)-(1,6) (1,5)-(1,6) (1,6)-(1,6)这6个矩形（单独一个点也算） 
  下一行2,6这个点的值为4，所以当前最小值为4，代表(2,3)-(1,6) (2,4)-(1,6) (2,5)-(1,6) (2,6)-(1,6)这四个矩形
  同样第三行值为3，代表新增(3,4)-(1,6) (3,5)-(1,6) (3,6)-(1,6)这三个矩形
  第四行的值虽然为6，但是他不能新增6个矩形，因为(4,1)-(1,6)中间包含不是1的点，所以得取当前最小值3
  以上列出矩形都是以(1,6)为右上角的，所以全部加到rectangular[1][6]中
4.最后再把rectangular矩阵所有元素值加一起就是总数了

关键词：好题，好算法，搜索 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        char original[100][100];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cin>>original[i][j];
                if(original[i][j]=='.')original[i][j]=1;
                else original[i][j]=0;
            }//(1) 
        
        for(int i=0;i<n;i++)
            for(int j=1;j<n;j++)
                if(original[i][j]==1)
                    original[i][j]+=original[i][j-1];//(2)
                    
        int rectangular[100][100]={0},min;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(original[i][j]==0)continue;
                min=original[i][j];
                
                for(int k=i;k<n;k++)
                {
                    if(original[k][j]==0)break;
                    if(min>original[k][j])min=original[k][j];
                    rectangular[i][j]+=min;
                }
            }
        
        int count=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                count+=rectangular[i][j];
                
        cout<<count<<endl;
    }
}
