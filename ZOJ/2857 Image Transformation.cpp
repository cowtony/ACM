/*
读入3个矩阵，分别表示点的红绿蓝，求灰度（r+g+b/3） 

读入及输出略有些麻烦而已

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int N,M;
    int cases=0;
    while(cin>>N>>M)
    {
        if(M==0 && N==0)break;
        
        int RGB[100][100][3];
        
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                cin>>RGB[i][j][0];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                cin>>RGB[i][j][1];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                cin>>RGB[i][j][2];
                
        cases++;
        cout<<"Case "<<cases<<":"<<endl;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M-1;j++)
                cout<<(RGB[i][j][0]+RGB[i][j][1]+RGB[i][j][2])/3<<",";
            cout<<(RGB[i][M-1][0]+RGB[i][M-1][1]+RGB[i][M-1][2])/3<<endl;
        }
    } 
}
