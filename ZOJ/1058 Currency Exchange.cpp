/*
一个人要出国旅游，当然要使用汇率换钱，现在他要去好几个国家，每去一个国家前都要换一次钱，让你求出走一圈，等他回国时他的钱是多少。
输入的第一行是有多少个数据块
然后是空行，每一个数据块之间也会有一个空行
然后的五行是五个国家相互的汇率，第i行的第j列就是第i个国家到第j个国家的汇率
然后剩下的行数每行是一个数据
第一个数是去几个国家，后面的数就是具体去的哪个国家，最后一个数是起始钱数
当国家数为0时这个数据块结束
输出分数据块，每个数据块之间有一个空行，每行输出换到最后是多少钱。

用数组currency存下汇率，再根据所去的国家一步步转化。要注意每次转化都要四舍五入到小数点后两位

关键词：模拟题
*/
#include <iostream>
using namespace std;

int main()
{
    int cases,n;
    int city[13];
    double currency[5][5];
    double money;
    
    cin>>cases;
    while(cases--)
    {        
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                cin>>currency[i][j];   //读入汇率
                
        while(cin>>n,n!=0)
        {            
            for(int i=1;i<=n;i++)
                cin>>city[i];         //读入去的国家代码
            city[0]=city[n+1]=1;      //代码前端数据为1代表从本国出发，末端数据为1代表回到本国
                
            cin>>money;     //读入所带金额
            
            
            for(int i=1;i<=n+1;i++)
            {
                money*=currency[city[i-1]-1][city[i]-1];      //转换汇率
                money=double(int(money*100+0.5))/100;         //四舍五入
            }
            
            printf("%.2f\n",money);
        }
        if(cases!=0)cout<<endl; //讨厌的格式要求
    }
    
    return 0;
}
