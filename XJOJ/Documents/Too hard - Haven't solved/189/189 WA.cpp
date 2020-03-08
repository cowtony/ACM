#include<iostream>
#include<cmath>
using namespace std;

int extend_GCD(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    else
    {
        int r=extend_GCD(b,a%b,x,y);
        int temp=x;x=y;
        y=temp-a/b*y;
        return r;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c,p,q,r,s;
        cin>>a>>b>>c>>p>>q>>r>>s;
        
        if(q<p || s<r)cout<<0<<endl;
        else if(a==0 && b==0)
        {
            if(c==0)cout<<(q-p+1)*(s-r+1)<<endl;
            else cout<<0<<endl;
        }
        else if(a==0)
        {
            if(c%b==0 && -c/b>=r && -c/b<=s)cout<<q-p+1<<endl;
            else cout<<0<<endl;
        }
        else if(b==0)
        {
            if(c%a==0 && -c/a>=p && -c/a<=q)cout<<s-r+1<<endl;
            else cout<<0<<endl;
        }
        else
        {
            int x,y;
            int gcd=extend_GCD(a,b,x,y);
        
            if(c%gcd==0)
            {
                x*=-c/gcd;
                y*=-c/gcd;
                
                double t1=double(p-x)/double(b/gcd);
                double t2=double(q-x)/double(b/gcd);
                if(t1>t2)swap(t1,t2);
            
                double t3=double(y-r)/double(a/gcd);
                double t4=double(y-s)/double(a/gcd);
                if(t3>t4)swap(t3,t4);

                int left=ceil(max(t1,t3));
                int right=min(t2,t4);
            
                if(left>right)cout<<0<<endl;
                else cout<<right-left+1<<endl;
            }
            else cout<<0<<endl;
        }
    }
}
