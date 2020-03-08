/*
给了一个递归函数，但是直接调用很慢，找一个快的算法使用这个函数 

由于函数定义里0<a,b,c<=20，所以定义一个数组array[21][21][21]存下w(a,b,c)的值
以后遇见的时候就不用递归直接可以得出结果了
避免了大量的无限递归 
用cin和cout会超时 

关键词：巧算法，递归 
*/
#include<iostream>
using namespace std;

int array[21][21][21]={0};

int w(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return w(20,20,20);
    if(array[a][b][c]!=0)return array[a][b][c];  
    if(a<b&&b<c)return array[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return array[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main()
{
    int a,b,c;
    
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if(a==-1&&b==-1&&c==-1)return 0;

        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
}
