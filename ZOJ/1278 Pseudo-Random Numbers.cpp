/*
依据递推式L[n+1]=(Z*L[n]+I)%M，给出Z,L,I,M的值，求L值的循环周期  L<M<10000

利用数组（筛）存下L出现过的数值，依次求出L，看什么时候求出的L以前出现过
需要注意在L的值循环时并不一定循环回初始的L值，例如3,5,7,6,5,7,6,5,7,6...的周期是3

关键词：数学题
*/
#include<iostream>
using namespace std;

int main()
{
    
    int z,i,m,l,count,cases=0;
    bool con[10000];
    
    while(cin>>z>>i>>m>>l)
    {
        if(m==0)break;
        memset(con,false,sizeof(con));
        
        while(con[l]==false)
        {
            con[l]=true;
            l=(z*l+i)%m;
        }                                 //先求出循环的起点
        
        memset(con,false,sizeof(con));
        count=0;
        while(con[l]==false)
        {
            con[l]=true;
            l=(z*l+i)%m;
            count++;
        }                                 //再求出循环的周期
        
        cout<<"Case "<<++cases<<": "<<count<<endl;
    }
    
    return 0;
    
}

