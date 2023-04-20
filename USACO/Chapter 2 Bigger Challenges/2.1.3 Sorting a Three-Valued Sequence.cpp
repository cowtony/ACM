/*
ID:cowtony1
PROG:sort3
LANG:C++
��һ��ֻ��1,2,3�����У��ý���Ԫ�ط������ų����������ٽ�������

���Ƚ�ԭ����������õ����н��жԱȣ���ͬλ�������֣�һ������һ����ȥ�������ǲ�����뽻��
�ҳ����������������������෴����1,3��3,1������ֻ��Ҫ����һ�Σ�����count++��Ȼ��ɾ����������
���ʣ�µ�һ�������ı�����Ԫ��ֻ��1,2,3��������ÿ������Ҫ���ν���
��
3,1,2
1,2,3����count+=ori.size()/3*2����

�ؼ��ʣ����� 
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
                    sorted.erase(sorted.begin()+i);//��ɾ�����Ԫ����ɾǰ��ģ���Ȼ�ž����� 
                    goto start;
                }
    
    count+=ori.size()/3*2;
    cout<<count<<endl;
}
