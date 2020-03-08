/*
输入两个数，若第二个小于第一个输出"MMM BRAINS"否则输出"NO BRAINS"

诡异的题。。。僵尸。。。

关键词：最最最最瓜的题，我喜欢 
*/
#include<iostream>
using namespace std;

int main()
{
    int case_num;
    cin>>case_num;
    
    while(case_num--)
    {
        int x,y;
        cin>>x>>y;
        if(x>=y)cout<<"MMM BRAINS"<<endl;
        else cout<<"NO BRAINS"<<endl;
    }
}
