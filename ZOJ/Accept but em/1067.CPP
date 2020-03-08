 #include<iostream.h>

 int main()
 {
	long a[16],b[16],c[16];
	int i;
	for(i=0;i<16;i++)	cin>>a[i]>>b[i]>>c[i];
	long fir,sec,thi;
	while(cin>>fir>>sec>>thi)
	{
		if(fir==-1&&sec==-1&&thi==-1) break;
		long dis=(a[0]-fir)*(a[0]-fir)+(b[0]-sec)*(b[0]-sec)+(c[0]-thi)*(c[0]-thi);

		int pos=0;
		for(i=1;i<16;i++)
		{
			long temp=(a[i]-fir)*(a[i]-fir)+(b[i]-sec)*(b[i]-sec)+(c[i]-thi)*(c[i]-thi);
			if(temp<dis){dis=temp;pos=i;}
		}

		cout<<"("<<fir<<","<<sec<<","<<thi<<") maps to ("<<a[pos]<<","<<b[pos]<<","<<c[pos]<<")"<<endl;
	}
	return 0;
 }



