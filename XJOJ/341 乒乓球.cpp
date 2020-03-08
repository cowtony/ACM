/*
输入一堆W和L以E结束，根据win和lose的情况分别输出在11分制下和21分制下的比分

用数组存下两种情况的比分，一个字符一个字符的读入，计算，最后输出
要求如果结果正好是一局比赛的结束，则按新一局比赛的开始处理，即最后一行为0:0

关键词：模拟题 
*/
#include<iostream>
using namespace std;

int main()
{
    char c;
    int result_11[20000][2]={0};//11分制下的比赛情况，最多20000局 
    int result_21[20000][2]={0};
    int count_11=0;//记录当前局数 
    int count_21=0;
    
    while(cin>>c)
    {
        if(c=='E')break;
        
        if(c=='W')
        {
            result_11[count_11][0]++;
            result_21[count_21][0]++;
        }
        else
        {
            result_11[count_11][1]++;
            result_21[count_21][1]++;
        }
        
        if(result_11[count_11][0]>=11 && result_11[count_11][0]-result_11[count_11][1]>=2)count_11++;
        if(result_11[count_11][1]>=11 && result_11[count_11][1]-result_11[count_11][0]>=2)count_11++;
        if(result_21[count_21][0]>=21 && result_21[count_21][0]-result_21[count_21][1]>=2)count_21++;
        if(result_21[count_21][1]>=21 && result_21[count_21][1]-result_21[count_21][0]>=2)count_21++;//这四行判断是否结束一局 
    }
    
    for(int i=0;i<=count_11;i++)
        cout<<result_11[i][0]<<":"<<result_11[i][1]<<endl;
    cout<<endl;
    for(int i=0;i<=count_21;i++)
        cout<<result_21[i][0]<<":"<<result_21[i][1]<<endl;
        
    //while(1);
}
