/*
读入一行行的字符串，逆序输出

用cin.getline读，学会用reverse函数
还有注意ignore在这里的用法和原因

关键词：字符串，简单题 
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    cin.ignore();//忽略掉读完数的回车符，还是要把输入流搞清楚 
    while(testcase--)
    {
        char s[80];
        cin.getline(s,80);
        reverse(s,s+strlen(s));
        cout<<s<<endl;
    }
}
