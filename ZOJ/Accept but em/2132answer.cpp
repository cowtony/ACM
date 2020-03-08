/*
L<=250000个数,其中有一个数出现的次数大于L/2,求这个数


*/
#include<iostream>
using namespace std;

int main()
{
    int n,m,b,k;
    
    while(cin>>n)
    {
        k=0;
        while(n--)
        {
            cin>>m;
            
            if(k==0){b=m;k++;}
            else 
            if(m==b)k++;
            else k--;
        } 
        cout<<b<<endl;
    }
    
    return 0;
}
