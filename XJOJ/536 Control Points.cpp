/*
输入升序的一堆点，现在要用覆盖范围1m的sth覆盖这些点，求最少需要多少个sth

贪心

关键词：简单题，贪心 
*/
#include<iostream>
using namespace std;

int main()
{
    int N;
    while(cin>>N)
    {
        double point;
        cin>>point;
        int total=1;
        
        for(int i=1;i<N;i++)
        {
            double temp;
            cin>>temp;
            
            if(temp-point>=1)
            {
                point=temp;
                total++;
            }
        }
        cout<<total<<endl;
    }
}
