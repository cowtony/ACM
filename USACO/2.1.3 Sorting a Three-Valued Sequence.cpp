/*
ID:cowtony1
PROG:sort3
LANG:C++
给一串只有1,2,3的数列，用交换元素法把它排成升序，求最少交换次数

首先将原数列与排序好的数列进行对比，把同位置下数字（一对数）一样的去掉，他们不会参与交换
找出这样两对数：他们正好相反，如1,3和3,1，这种只需要交换一次，所以count++，然后删掉这两对数
最后剩下的一定是三的倍数（元素只有1,2,3），他们每三个需要两次交换
如
3,1,2
1,2,3所以count+=ori.size()/3*2即可

关键词：排序 
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int n;
    cin>>n;
    
    vector<int> ori(n),sorted(n);
    for(int i=0;i<n;i++)
    {
        cin>>ori[i];
        sorted[i]=ori[i];
    }
    
    sort(sorted.begin(),sorted.begin()+n);
    
    for(int i=0;i<ori.size();i++)
        if(ori[i]==sorted[i])
        {
            ori.erase(ori.begin()+i);
            sorted.erase(sorted.begin()+i);
            i--;
        }
    
    int count=0;

    start:
    for(int i=0;i<ori.size();i++)
        if(ori[i]!=sorted[i])
            for(int j=i+1;j<ori.size();j++)
                if(ori[i]==sorted[j] && sorted[i]==ori[j])
                {
                    count++;
                    ori.erase(ori.begin()+j);
                    ori.erase(ori.begin()+i);
                    sorted.erase(sorted.begin()+j);
                    sorted.erase(sorted.begin()+i);//先删后面的元素再删前面的，不然号就乱了 
                    goto start;
                }
    
    count+=ori.size()/3*2;
    cout<<count<<endl;
}
