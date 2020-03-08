/*
Hilbert curve问题，输入Hilbert curve的阶数以及以该曲线自然坐标表示的两点，求这两点的直线距离

先要把自然坐标转化为直角坐标
就是说每次根据自然坐标的值判断该点在图中的位置（左上0，右上1，右下2，左下3）
一步一步逐渐精确。
但是要判断方向，图中只会有四种方向type（右下左0，下右上1，上左下2，左上右3）
建立transfer转换矩阵来根据当前type和所处的位置判断下一个的type
而block矩阵是根据当前type和在该自然坐标下的长度确定直角坐标下的位置
最后可以根据一次一次位置的确定得到直角坐标

关键词：难题，递归 
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> get_position(int order,int num)
{
    int transfer[4][4]={{1,0,0,2},{0,1,1,3},{3,2,2,0},{2,3,3,1}};
    int block[4][4]={{0,1,2,3},{0,3,2,1},{2,1,0,3},{2,3,0,1}};
    int total=1;
    for(int i=0;i<order;i++)
        total*=4;

    int type=0,x=1,y=1;
    for(int i=0;i<order;i++)
    {
        total/=4;
        int part=(num-1)/total;
        num-=total*part;
        
        int pos=block[type][part];
        
        if(pos==2||pos==3)x+=sqrt(total);
        if(pos==1||pos==2)y+=sqrt(total);
        
        type=transfer[type][part];
    }
    
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    return v;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,h,o;
        cin>>n>>h>>o;
        
        vector<int> pos1,pos2;
        pos1=get_position(n,h);
        pos2=get_position(n,o);
         
        int x=pos1[0]-pos2[0];
        int y=pos1[1]-pos2[1];

        cout<<int(sqrt(x*x+y*y)*10+0.5)<<endl;
    }
}
