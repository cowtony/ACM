 #include<iostream.h>


 struct blocktype
 {
	int x,y,z;
 };
 void bubble(blocktype temp[],int add)
 {
	int i,j;
	for(i=0;i<add;i++)
	{
		int k=i;
		for(j=i+1;j<add;j++)
			if((temp[k].x>=temp[j].x&&temp[k].y>=temp[j].y)||
			(temp[k].y>=temp[j].x&&temp[k].x>=temp[j].y)) k=j;
		blocktype tt=temp[i];temp[i]=temp[k];temp[k]=tt;
	}
 }

 int main()
 {
	int n;int amount=0;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		amount++;
		int i,j;blocktype block[91]; int pt=0;int a,b,c;
		for(i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			block[pt].x=a;block[pt].y=b;block[pt].z=c;pt++;
			block[pt].x=b;block[pt].y=c;block[pt].z=a;pt++;
			block[pt].x=c;block[pt].y=a;block[pt].z=b;pt++;

		}

		bubble(block,n*3);


		int val[91];
		for(i=0;i<n*3;i++)
		{
			val[i]=block[i].z;int tempmax=-1;
			for(j=i-1;j>=0;j--)
				if((block[j].x<block[i].x&&block[j].y<block[i].y)||
				   (block[j].y<block[i].x&&block[j].x<block[i].y))
				 {  if(tempmax==-1) tempmax=val[j];
				     else if(tempmax<val[j]) tempmax=val[j];
				 }
			if(tempmax!=-1) val[i]+=tempmax;
		}

		int max=val[0];
		for(i=1;i<n*3;i++)
			if(val[i]>max) max=val[i];
		cout<<"Case "<<amount<<": maximum height = "<<max<<endl;
	}
	return 0;
 }


