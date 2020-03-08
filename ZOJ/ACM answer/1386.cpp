//109318 2003-04-06 17:37:28 Accepted 1386 C++ 00:00.24 4660K Century Ghost 
#include<iostream.h>
#include<stdio.h>
#include<vector>
using namespace std;
char tzolkin[20][10]={"Imix", "Ik", "Akbal", "Kan", "Chikchan", "Kimi", 
	"Manik", "Lamat", "Muluk", "Ok", "Chuen", "Eb", "Ben", "Ix", "Men", 
	"Kib", "Kaban", "Etznab", "Kawak", "Ajaw"};
char haab[19][10]={"Pohp", "Wo", "Sip", "Zotz", "Sek", "Xul", "Yaxkin", 
	"Mol", "Chen", "Yax", "Sak", "Keh", "Mak", "Kankin", "Muan", "Pax", 
	"Kayab", "Kumku", "Wayeb"};


struct solution_type
{
	int b,k,t,w,i;
	void print()
	{
		cout<<b<<"."<<k<<"."<<t<<"."<<w<<"."<<i<<endl;
	}

};
vector<solution_type>result[14][20][21][20];

void increase(int& d1,int& n1,int& d2,int& n2)
{

	d1++;
	if(d1>13)	d1=1;
	n1++;
	if(n1>19)	n1=0;
	d2++;
	
	if(n2==18&&d2==6)
	{
//			cout<<"==="<<endl;
			d2=1;
			n2=0;
	}
	if(d2==21)
	{
		n2++;
		d2=1;
	}
//	cout<<d1<<"   "<<n1<<" ----  "<<d2<<"  "<<n2<<endl;
}


int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);


	int d1=9,n1=19,d2=3,n2=2;
	
	
	int bb,kk,tt,ww,ii;
	for(bb=8;bb<=9;bb++)
		for(kk=0;kk<20;kk++)
			for(tt=0;tt<20;tt++)
				for(ww=0;ww<18;ww++)
					for(ii=0;ii<20;ii++)
					{
						solution_type temp;
						temp.b=bb;temp.i=ii;temp.k=kk;temp.t=tt;temp.w=ww;
						result[d1][n1][d2][n2].push_back(temp);
//						temp.print();
//							cout<<d1<<"   "<<n1<<"   "<<d2<<"  "<<n2<<endl;
						increase(d1,n1,d2,n2);
						
					}
	int nn;
	cin>>nn;
	while(nn--)
	{
		int fir,sec;
		char fir_str[10],sec_str[10];
		cin>>fir>>fir_str>>sec>>sec_str;
		int j,pt;
		for(j=0;j<20;j++)
			if(strcmp(fir_str,tzolkin[j])==0)	break;
		for(pt=0;pt<20;pt++)
			if(strcmp(sec_str,haab[pt])==0)	break;
//		cout<<fir<<"    "<<j<<" ----  "<<sec<<"    "<<pt<<endl;
		int len=result[fir][j][sec][pt].size();
		cout<<len<<endl;
		int loop;
		for(loop=0;loop<len;loop++)
			result[fir][j][sec][pt][loop].print ();
	}
	return 0;
}
		



