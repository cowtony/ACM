#include<iostream>
using namespace std;

int main()
{
    int ca,cb,n,A,B,t;
    bool ok;
    
    while(cin>>ca>>cb>>n)
    {
        ok=false;
        A=B=0;
        
        if(ca==n)
        {
            cout<<"fill A"<<endl;
            cout<<"success"<<endl;
        }
        else if(cb==n)
        {
            cout<<"fill B"<<endl;
            cout<<"success"<<endl;
        }
        else
        {
            while(ok==false)
            {
                cout<<"fill A"<<endl;
                A=ca;
                cout<<"pour A B"<<endl;
                A=A-(cb-B);
                
                if(A>0)
                {
                    cout<<"empty B"<<endl;
                    cout<<"pour A B"<<endl;B=A;A=0;
                    if(B==n)ok=true;
                }
                else 
                {
                    A=0;B=B+ca;
                    if(B==n)ok=true;
                }
            }
            cout<<"success"<<endl;
        }
    }
    
    return 0;
} 
