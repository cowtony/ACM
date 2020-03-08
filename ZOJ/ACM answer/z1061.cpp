#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
int n;
cin>>n;
for(int i=0; i<n; i++)
{
  
  
    int j=0;
    int k=0;
    stack<string> backStack;
    stack<string> forwardStack;
    string tmp[1000];
    string url[1000];
    url[0] = "http://www.acm.org/";
    backStack.push(url[k]);
    while(cin>>tmp[j]&&tmp[j].compare("QUIT"))
    {
     if(!tmp[j].compare("VISIT"))
     {
      cin>>url[k];
      backStack.push(url[k]);
      k++;
      cout<<backStack.top()<<endl;
      while(!forwardStack.empty())
       forwardStack.pop();
     }
     if(!tmp[j].compare("BACK"))
     {
      forwardStack.push(backStack.top());
      backStack.pop();
      if(!backStack.empty()) 
       cout<<backStack.top()<<endl;
     
      else if(backStack.empty()){
       cout<<"Ignored"<<endl;
       backStack.push(forwardStack.top());
       forwardStack.pop();
      }
     
     }
     if(!tmp[j].compare("FORWARD"))
     {
     
      if(!forwardStack.empty())
      {
       backStack.push(forwardStack.top());
       //u = forwardStack.top();
       forwardStack.pop();
       cout<<backStack.top()<<endl;
      }
      else if(forwardStack.empty())
       cout<<"Ignored"<<endl;
     }
     j++;
    }
    if(i<n-1)
     cout<<endl;
  

}
}
