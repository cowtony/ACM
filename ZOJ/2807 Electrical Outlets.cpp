/*
墙上只有一个插头，给你许多插线板，告诉你插线板上的插头数，求最终有几个可用插头

每个插线板可以增加它上面的插头数
但它插在别的地方，所以还要减一
结果就是所有插线板的插头数的和减去插线板数
因为刚开始的时候还有一个，所以再加1

关键词：简单题，巧算法 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>k;
        int sum=0;
        for(int i=0;i<k;i++)
        {
            int t;
            cin>>t;
            sum+=t;
        }
        cout<<sum-k+1<<endl;
    }
} 
