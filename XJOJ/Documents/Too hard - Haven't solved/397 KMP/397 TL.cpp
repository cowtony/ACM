#include<iostream>
#include<string>
using namespace std;

char T[1000001],S[1000001];
int pat[1000000]={0};

bool similar(char a,char b)
{
    if(a==b && a>='A' && a<='Z')return true;
    if(a>='a' && a<='z' && b>='a' && b<='z')return true;
    return false; 
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    cin>>T>>S;
    
    int point=0;
    for(int i=1;i<strlen(S);i++)
    {
        if(S[i]==S[point] && S[i]>='A' && S[i]<='Z' || (S[i]>='a' && S[i]<='z' &&S[point]>='a' && S[point]<='z'))pat[i]=++point;
        else point=0;
    }//预处理模式pat
    
    point=0;
    int count=0;
    for(int i=0;i<strlen(T);i++)
    {
        if(T[i]==S[point] && T[i]>='A' && T[i]<='Z' || (T[i]>='a' && T[i]<='z' &&S[point]>='a' && S[point]<='z'))point++;
        else if(point>0){point=pat[point-1];i--;}
        
        if(point==strlen(S))
        {
            char map[256][2]={0};
            for(int j=i-strlen(S)+1,k=0;j<=i;j++,k++)
            {
                if(T[j]>='a' && T[j]<='z')
                {
                    if(map[S[k]][0]==0)map[S[k]][0]=T[j];
                    else if(map[S[k]][0]!=T[j])goto end;
                
                    if(map[T[j]][1]==0)map[T[j]][1]=S[k];
                    else if(map[T[j]][1]!=S[k])goto end;
                }
            }
            count++;
            end:point=pat[point-1];
        }
    }
    cout<<count;
    //while(1);
}
