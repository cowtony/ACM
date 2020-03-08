/*
输入直线上的区间及填充颜色，所有数据输入完毕后按颜色大小顺序输出可以看到的该颜色的块数

先读入数据，那一个线性数组去模拟，记录下全部填充后的结果
然后把不同的颜色加入multiset中，因为是块的个数，所以要有一个条件是“此处的颜色不同于前一格的颜色”才能添加
然后按照multiset输出顶端元素，再输出“删除顶端元素”删除了几个。直到结束

关键词：模拟，STL
*/
#include<iostream>
#include<set>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int color[8000];
        for(int i=0;i<8000;i++)
            color[i]=-1;

        int x1,x2,c;
        for(int i=0;i<n;i++)
        {
            cin>>x1>>x2>>c;
            for(int j=x1;j<x2;j++)
                color[j]=c;
        }
        
        multiset<int> ms;
        if(color[0]>=0)ms.insert(color[0]);
        for(int i=1;i<8000;i++)
            if(color[i]!=color[i-1] && color[i]>=0)
                ms.insert(color[i]);
        
        while(ms.size()>0)
        {
            cout<<*ms.begin()<<' ';
            cout<<ms.erase(*ms.begin())<<endl;
            //这两行要分开写，因为cout执行计算是从右往左，会出错 
        }
        cout<<endl;
    }
}
