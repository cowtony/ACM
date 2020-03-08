/*
给一个bool方阵，输出里面边长大于2的全1正方形，并且按照边长大小输出每种边长的有多少个 

这道题思想同ZOJ 2067
只不过不用int count来存个数，用个map方便

关键词：有思想 
*/
#include<iostream>
#include<map>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int n;
    cin>>n;
    
    int square[250][250];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            square[i][j]=c-'0';
        }
    
    for(int i=0;i<n;i++)
        for(int j=1;j<n;j++)
            if(square[i][j]==1)
                square[i][j]+=square[i][j-1];
    
    map<int,int> m;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(square[i][j]>=2)
            {
                int min=square[i][j];
                for(int k=i+1;k<n;k++)
                {
                    if(square[k][j]<min)min=square[k][j];
                    if(min<k-i+1)break;
                    else m[k-i+1]++;
                }
            }
        }
    }
    
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        cout<<(*it).first<<' '<<(*it).second<<endl;
        
    //while(1);
}
