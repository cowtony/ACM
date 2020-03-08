/*
判断字符串a在字符串b中出现了多少次，a是可以随意排序的

用一个数组存下哪个字母出现了多少次，以及一共有几种字母
在字符串b里每新加一个字母，就去掉一个尾部的字母，并且新加的字母如果个数等于key，b++
减去的字母如果原来个数等于key，b--
最后如果一样就算找到一种 

关键词：字符串 
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int length1,length2;
    cin>>length1>>length2;
    string key,str;
    cin>>key>>str;

    int a[256]={0},b[256]={0};
    int a_t=0,b_t=0;
    int count=0;
    
    for(int i=0;i<length1;i++)
        a[key[i]]++;
    for(int i=0;i<256;i++)
        if(a[i]>0)a_t++;
        
    for(int i=0;i<length2;i++)
    {
        b[str[i]]++;
        if(b[str[i]]==a[str[i]])b_t++;
        
        if(i>=length1)
        {
            if(b[str[i-length1]]==a[str[i-length1]])b_t--;
            b[str[i-length1]]--;
        }
        
        if(a_t==b_t)count++;
    }
    
    cout<<count;
    //while(1);
}
