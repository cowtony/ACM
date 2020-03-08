/*
有长度为l的杆，上面有n个蚂蚁，已知每个蚂蚁的位置，不知道方向，速度一样，他们碰面后会掉头走
求他们全从杆上掉下来需要的最短及最长时间

两个蚂蚁碰面后掉头，因为速度一样，所以等效于互相穿透
所以最短的时间就是假设每个蚂蚁都向离端点近的方向走，距离最远的那只蚂蚁就是最短时间
反之最长时间是假设每个蚂蚁都向离端点远的方向走，也是取决于距离最远的蚂蚁

关键词：巧算法，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        
        int maxtime=0,mintime=0;
        for(int i=0;i<n;i++)
        {
            int ant;
            cin>>ant;
            int max=ant>l-ant?ant:l-ant;
            int min=ant<l-ant?ant:l-ant;
            if(max>maxtime)maxtime=max;
            if(min>mintime)mintime=min;
        }
        
        cout<<mintime<<' '<<maxtime<<endl;
    }
}
