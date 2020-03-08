//146452 2003-05-10 18:27:55 Accepted 1102 C++ 00:00.22 1500K just for play 
#include<iostream.h>
#include<string.h>
//#include<stdio.h>
int main()
{
//	freopen("in.txt","r",stdin);

	int n,len;
	while(cin>>n>>len)
	{
		if(n==0&&len==0)	break;
		char input[1025][1001];
		int i,j;
		for(i=0;i<n;i++)	cin>>input[i];
		char ch[2048][26];
		int num[2048];
		
		int total=0;
		char result[1001];
		for(i=0;i<len;i++)
		{
			memset(num,0,sizeof(num));
			for(j=2*n-2;j>=n-1;j--)
			{
				ch[j][0]=input[j-n+1][i];
				num[j]=1;
		
			}
			for(j=n-2;j>=0;j--)
			{
				
				int left=2*j+1,right=2*j+2;
				int kt,tt;bool has_found=false;
				for(kt=0;kt<num[left];kt++)
				{
					for(tt=0;tt<num[right];tt++)
						if(ch[left][kt]==ch[right][tt])
						{
							has_found=true;
							ch[j][num[j]++]=ch[left][kt];
						}
					
				}
				if(!has_found)													
				{
					int pt=0;
					for(kt=0;kt<num[left];kt++)
						ch[j][pt++]=ch[left][kt];
					for(kt=0;kt<num[right];kt++)
						ch[j][pt++]=ch[right][kt];
					num[j]=pt;
					total+=1;
				}
			}
			result[i]=ch[0][0];
		
		}
		result[len]='\0';
		cout<<result<<" "<<total<<endl;
	}
	return 0;
}




