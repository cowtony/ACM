/*
布上有些图案，输入一套图案中每个图案的面积和出现次数，求一平方英码的布上最多可以有多少套图案，还有2，3平方英码

1yard=36feet
其实直接用面积除就可以了~~简单

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int image;
        cin>>image;
        
        int total=0;
        while(image--)
        {
            int s,r;
            cin>>s>>r;
            total+=s*r;
        }
        cout<<1296/total<<" "<<1296*2/total<<" "<<1296*3/total<<endl;
    }
}

