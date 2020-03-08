/*
牛与牛共同拍过一部电影他们的关系就为1，隔一只牛就为2。求平均分离度最小的那头牛的平均分离度*100

读入数据，建图，牛是节点，两头牛要是同拍过一部电影就连一条路
分别宽度优先遍历每只牛，得到每只牛的总分离度，除以N-1*100

关键词：图论，简单题，宽度遍历 
*/
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    int N,M,Mi;
    cin>>N>>M;
    
    bool map[301][301]={false};
    while(cin>>Mi)
    {
        int cow[100];
        for(int i=0;i<Mi;i++)
            cin>>cow[i];
        for(int i=0;i<Mi;i++)
            for(int j=i+1;j<Mi;j++)
                map[cow[i]][cow[j]]=map[cow[j]][cow[i]]=true;
    }
    /*
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
            cout<<map[i][j]<<' ';
        cout<<endl;
    }
    */
    int min=2000000000;
    for(int i=1;i<=N;i++)
    {
        bool used[301]={false};
        used[i]=true;
        queue<int> ID,DEGREE;
        ID.push(i);
        DEGREE.push(0);
        
        int total=0;
        while(ID.size()>0)
        {
            int id=ID.front();
            int degree=DEGREE.front()+1;
            ID.pop();
            DEGREE.pop();
            
            for(int j=1;j<=N;j++)
                if(map[id][j]==true && used[j]==false)
                {
                    ID.push(j);
                    DEGREE.push(degree);
                    total+=degree;
                    used[j]=true;
                }
        }
        if(total<min)min=total;
    }
    cout<<int((min)*100.0/(N-1));
    //while(1);
}
