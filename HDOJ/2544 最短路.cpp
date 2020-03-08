/*
Floyd求最短路径就可以了 
*/
#include<iostream>
using namespace std;

const int INF=100000000;

int main()
{
    int N,M;
    while(cin>>N>>M && (N!=0 || M!=0))
    {
        int map[100][100];
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                map[i][j]=INF;
                
        for(int i=0;i<M;i++)
        {
            int A,B,C;
            cin>>A>>B>>C;
            map[A-1][B-1]=C;
            map[B-1][A-1]=C;
        }

        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    if(map[i][k]+map[j][k]<map[i][j])
                       map[i][j]=map[i][k]+map[j][k];
             
        cout<<map[0][N-1]<<endl;
    }
}
