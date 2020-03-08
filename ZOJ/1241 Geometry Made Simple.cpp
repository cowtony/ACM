/*
输入直角三角形两边长，求另一边。如4,-1,5，第三项为斜边，-1项为所求项

用很多if

关键词：简单题，数学题 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double a,b,c;
    int n=0;
    
    //freopen("aaa.txt","r",stdin);
    
    while(cin>>a>>b>>c)
    {
        if(a==0&&b==0&&c==0)break;
        
        n++;
        if(a==-1)  //求a的边长 
        {
            if(b>c)//不可能的情况 
            {
                cout<<"Triangle #"<<n<<endl;
                cout<<"Impossible."<<endl<<endl;
            }
            else
            { 
                cout<<"Triangle #"<<n<<endl;
                printf("a = %.3f\n\n",sqrt(c*c-b*b));
            }
        }
        else if(b==-1)  //求b的边长 
        {
            if(a>c)//不可能的情况 
            {
                cout<<"Triangle #"<<n<<endl;
                cout<<"Impossible."<<endl<<endl;
            }
            else
            { 
                cout<<"Triangle #"<<n<<endl;
                printf("b = %.3f\n\n",sqrt(c*c-a*a));
            }
        }
        else   //求c的边长 
        {
            cout<<"Triangle #"<<n<<endl;
            printf("c = %.3f\n\n",sqrt(a*a+b*b));
        }
    }
    
    
    
    
    //while(1);
    return 0;
}

