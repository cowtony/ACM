#include <stdio.h>
int main()
{
	int  sou[100],tar[100],st[100],dur[100];
	int temp[100];
	int cat,ext;
	int i,j,k;
	int m,he,ph,t,l,n;
	int cas;
	scanf("%d",&cas);
	t=0;
	n=cas;
	while(n--)
	{
		l=0;
		while(1)
		{
			scanf("%d",&sou[l]);
			if(sou[l]==0) break;
			scanf("%d%d%d",&st[l],&dur[l],&tar[l]);
			l++;
		}
		if(t==0) {printf("CALL FORWARDING OUTPUT\n");t=1;}
		printf("SYSTEM %d\n",cas-n);
		while(scanf("%d",&cat))
		{
			if(cat==9000) break;
			scanf("%d",&ext);
			m=0;
			i=0;
			j=0;
			ph=ext;
			he=0;
			while(i<l)
			{
				if(ph==sou[i])
				{
					he=1;
					if(cat>=st[i]&&cat<=st[i]+dur[i])
					{
						ph=tar[i];
						for(k=0;k<j;k++)
						{
							if(temp[k]==ph) {m=1;break;}
						}
						if(m==1) break;
						else temp[j++]=ph;
						i=0;
					}
					else i++;
				}
				else i++;
			}
			if(he==0||i==l) printf("AT %04d CALL TO %04d RINGS %04d\n",cat,ext,ph);
			if(m==1) printf("AT %04d CALL TO %04d RINGS 9999\n",cat,ext);
		}
		if(n==0) printf("END OF OUTPUT\n");
	}
	return 0;
}




