//112595 2003-04-09 12:02:22 Accepted 1343 C++ 00:00.01 436K Century Ghost 
#include<iostream.h>
#include<string.h>
//#include<stdio.h>

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	char str[4][14];
	while(cin>>str[0])
	{
		if(strcmp(str[0],"Q")==0)	break;
		cin>>str[1]>>str[2]>>str[3];
		int max=0;
		int i,t;
		int k0,k1,k2;
		int pt1,pt2,pt3,pt4;
		k0=1;k1=2;k2=3;
		for(i=0;i<6;i++)
		{
			for(pt1=1;pt1<11;pt1++)			
				for(pt2=1;pt2<11;pt2++)
				{
					if(str[k0][pt1]!=str[0][pt2])	continue;
					for(pt3=1;pt3<11;pt3++)
						for(pt4=10;pt4>0;pt4--)
						{
//							cout<<pt1<<"--"<<pt2<<"--"<<pt3<<"--"<<pt4<<endl;
							if(pt4==pt2||pt4==pt2+1||pt4==pt2-1)	continue;
							if(str[k1][pt3]!=str[0][pt4])	continue;
							int lap;
							if(pt3>pt1)		lap=10-pt3;
							else	lap=10-pt1;
							for(;lap>1;lap--)
							{
								int end_t;
								if(pt4>pt2) end_t=11+pt2-pt4;
								else	end_t=11+pt4-pt2;
								bool found=false;
								for(t=1;t<end_t;t++)
									if((pt4>pt2&&str[k0][pt1+lap]==str[k2][t]&&
										str[k1][pt3+lap]==str[k2][t+11-end_t])||
										(pt4<pt2&&str[k1][pt3+lap]==str[k2][t]&&
										str[k0][pt1+lap]==str[k2][t+11-end_t]))	{	found=true;break;}
								if(found)
								{
									int temp;
									if(pt4>pt2)
										temp=(pt4-pt2-1)*(lap-1);
									else	temp=(pt2-pt4-1)*(lap-1);
									if(temp>max)	max=temp;
									break;
								}
							}
							if(pt3>pt1)		lap=pt1-1;
							else	lap=pt3-1;
							for(;lap>1;lap--)
							{
								int end_t;
								if(pt4>pt2)	end_t=11+pt2-pt4;
								else	end_t=11+pt4-pt2;
								bool found=false;
								for(t=1;t<end_t;t++)
									if((pt4>pt2&&str[k0][pt1-lap]==str[k2][t]&&
										str[k1][pt3-lap]==str[k2][t+11-end_t])||
										(pt4<pt2&&str[k0][pt1-lap]==str[k2][t+11-end_t]&&
										str[k1][pt3-lap]==str[k2][t]))	{found=true;break;}
								if(found)
								{
									int temp;
									if(pt4>pt2)
										temp=(pt4-pt2-1)*(lap-1);
									else	temp=(pt2-pt4-1)*(lap-1);
									if(temp>max)	max=temp;
									break;
								}
							}
						}
				}
				int temp;temp=k0;k0=k1;k1=k2;k2=temp;
		}
		cout<<max<<endl;
	}

	return 0;
}
							
								
								


