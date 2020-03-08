/*
A+B problem

cin.eof()!!!!!!!!!!!!!!! 

¹Ø¼ü´Ê£º¼òµ¥Ìâ  
*/
#include<iostream>
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<a+b<<endl;
        if(cin.eof()==false)cout<<endl;
	}
}
