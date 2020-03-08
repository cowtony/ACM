/*
求数列1,2,2,3,3,3,4,4,4,4,5,5,5,5,5...的前n项和

先一项，两项，三项这样加，最后剩一点单独处理就可以了

关键词：数学题，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int day;
        while(cin>>day)
        {
            if(day==0)break;
            
            int c=1,coin=0,save=day;
            while(day>c)
            {
                coin+=c*c;
                day-=c;
                c++;
            }
            coin+=c*day;
            
            cout<<save<<' '<<coin<<endl;
        }
        if(t>0)cout<<endl;
    }
}
