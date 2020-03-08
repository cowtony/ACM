/*
求一棵单词查找树的节点数，单词查找树的定义看原题

可以直接建一棵树，再搜索节点数
也可以优化一下，把单词排好序，然后每个单词所新增的节点数就是和前一个单词的差集
比如ASCY和ASCKQW，他们前面的共有串是ASC，所以第二个新增了KQW三个节点

关键词：树，巧算法 
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int n=0;
    string word[100000];
    while(cin>>word[n++]);
    
    sort(word,word+n);
    
    int node=1+word[0].length();
    for(int i=1;i<n;i++)
    {
        int j=0;
        while(j<word[i-1].length() && j<word[i].length())
        {
            if(word[i-1][j]!=word[i][j])break;
            j++;
        }
        
        node+=word[i].length()-j;
    }
    
    cout<<node<<endl;
    //while(1);
}
