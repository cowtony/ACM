#include<iostream.h>
#include<fstream.h>
ofstream fout("out.txt");

int large(long fir,long sec,long thi,long fou)
{
	return (fir*fou>sec*thi);
}


int main()
{
	long gain,lose;int flag=0;
	

	while(cin>>gain>>lose)
	{
		long prefir=gain*10,presec=lose;
		if(flag)	cout<<endl;
		flag=1;
		long i,j;
		for(i=1;;i++)
		{	
			long fir,sec;	
			for(j=1;;j++)
			{
				fir=(j-1);
				sec=j;
				if((large(gain,lose,fir,i)&&large(sec,i,gain,lose))||j*lose==gain*i)	break;
			}
	//		fout<<j<<"=="<<i<<endl;
			if(j*lose==gain*i)	
			{	cout<<j<<"/"<<i<<endl;break;}
			
			
			if(2*gain*i<(fir+sec)*lose&&(lose*i*prefir>(gain*i-fir*lose)*presec))
			{
				cout<<(j-1)<<"/"<<i<<endl;
				prefir=gain*i-fir*lose;
				presec=lose*i;
			}
			else if(2*gain*i>(fir+sec)*lose&&(lose*i*prefir>(gain*i-sec*lose)*presec))
			{
				cout<<j<<"/"<<i<<endl;
				prefir=gain*i-sec*lose;
				presec=lose*i;
			}
			
		}
	}
	return 0;
}


