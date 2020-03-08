/*
看原题，近似相当于已知二叉树的中序遍历，求二叉树的前序遍历

利用递归，已知字符串的长度，就可以求得中间字符的位置，从而把字符串分割为左右两部分，对于每一部分执行相同操作
执行什么操作？
把原字符串可以分为“左字符串，中间字符，右字符串”
读入的顺序是“中间字符，左字符串，右字符串”
调换一下顺序递归就可以了

关键词：二叉树，递归，字符串 
*/
#include<iostream>
#include<string>
using namespace std;

void f(char input[],char result[],int length)
{
    if(length==0)return;
    
    int middle=(1+length)/2;
    result[middle-1]=input[0];
    
    int left_length=middle-1;
    int right_length=length-middle;
    
    f(input+1,result,left_length);
    f(input+middle,result+middle,right_length);
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    char input[2001],result[2001]={0};
    
    char c;
    int i=0;
    while(scanf("%c",&c)!=EOF)
        input[i++]=c;
    
    f(input,result,i);
    cout<<result;
    
    //while(1);
}
