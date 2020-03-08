/*
输入n，求使2^x=1(mod n)成立的最小x值

2^x%n等价于2%n然后乘2再%n，如此循环x次直到值为1
当且仅当n为偶数或n=1时不可能

关键词：数学题
*/
#include <iostream> 
using namespace std; 

int main()
{ 
    int n,x,js;
 
    //freopen("aaa.txt","r",stdin);

    while (cin>>n)
    { 
        if(n%2==0||n==1)
        {
            cout<<"2^? mod "<<n<<" = 1"<<endl;
            continue;
        }
   
        x=1,js=0;
        
        while(1)
        { 
            x*=2;
            x%=n;
            js++; 
            if (x==1)break; 
            
        }
        
        cout<<"2^"<<js<<" mod "<<n<<" = 1"<<endl; 
         
    }
    
    //while(1);
    return 0; 
} 