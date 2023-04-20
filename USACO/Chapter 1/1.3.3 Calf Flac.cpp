/*
ID:cowtony1
PROG:calfflac
LANG:C++
输入一段文章，输出是最长回文的一段，判断回文的时候不管非字母的东西，但输出还要正常输出

先读入数据，然后枚举回文中点，找最大的长度
记下最大长度时的左边和右边，最后输出
题目不难，但比较考技巧

关键词：字符串，回文 
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string s;

int solve(int left,int right,int& a,int& b)
{
    int length=right-left-1;

    while(left>=0 && right<s.length())
    {
        while(!isalpha(s[left]) && left>=0)left--;
        while(!isalpha(s[right]) && right<s.length())right++;
        if(tolower(s[left])==tolower(s[right]))
        {
            length+=2;
            a=left;
            b=right;
            left--;
            right++;
        }
        else break;
    }
    return length;
} 

int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);

    while(cin.eof()==false)
        s+=cin.get();
    
    int max_length=0;
    int max_left,max_right;
    
    for(int i=0;i<s.length();i++)
    {
        int len,left,right;
        if(isalpha(s[i]))
        {
            len=solve(i,i,left,right);//奇数 
            if(max_length<len)
            {
                max_length=len;
                max_left=left;
                max_right=right;
            }
            len=solve(i,i+1,left,right);//偶数
            if(max_length<len)
            {
                max_length=len;
                max_left=left;
                max_right=right;
            }
        }
    }
    
    cout<<max_length<<endl; 
    for(int i=max_left;i<=max_right;i++)
        cout<<s[i];
    cout<<endl;
}
