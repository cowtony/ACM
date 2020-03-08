 #include<iostream.h>
 #include<math.h>

 int equal(float fir,float sec)
 {
	return	(fabs(fir-sec)<0.0000001);
 }
 int main()
 {
	int student,stu_reg[151],stu_mark[151],stu_k[151],stu_fdu[151][51];
	int school,sch_reg[51],sch_cap[51];
	int org[51][151];int stu_belong[151];
	int i,j,k,t;int n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		if(i!=0)	cout<<endl;
		cin>>student>>school;
		for(j=1;j<=student;j++)
		{
			cin>>stu_reg[j]>>stu_mark[j]>>stu_k[j];
			for(t=1;t<=stu_k[j];t++)
				cin>>stu_fdu[j][t];
		}
		for(j=1;j<=school;j++)	cin>>sch_reg[j]>>sch_cap[j];
		for(j=1;j<=student;j++)	stu_belong[j]=-1;
		for(j=1;j<=school;j++)
			for(t=1;t<=student;t++)	org[j][t]=t;
		for(j=1;j<=school;j++)
		{
			float mark[151];
			for(t=1;t<=student;t++)
			{

				if(stu_reg[t]==sch_reg[j])	mark[t]=(float)stu_mark[t];
				else	mark[t]=(float)stu_mark[t]/1.7;

			}

			for(t=1;t<=student;t++)
			{	int pt=t;
				for(k=t+1;k<=student;k++)
				{
					if(mark[org[j][pt]]<mark[org[j][k]])	pt=k;
					else if(equal(mark[org[j][pt]],mark[org[j][k]])&&stu_reg[org[j][k]]==sch_reg[j]) 	pt=k;
				}
				if(pt!=t){
					int temp=org[j][t];org[j][t]=org[j][pt];org[j][pt]=temp;
				}

			}
		}

		int flag[51][151];
		for(j=1;j<=school;j++)
			for(t=1;t<=student;t++)
				flag[j][t]=0;
		int used[151];
		for(j=1;j<=student;j++)	used[j]=0;
		for(j=1;j<=school;j++)
		{
			for(t=1;t<=school;t++)
			{
				for(k=1;k<=sch_cap[t];k++)
				{
					if(k>student)	break;
					if(flag[t][k])	continue;
					int temstu=org[t][k];

					int q;
					if(stu_belong[temstu]==-1)
						for(q=1;q<=j;q++)
						{       if(q>stu_k[temstu]){flag[t][k]=1;sch_cap[t]++;break;}
							if(stu_fdu[temstu][q]==t)
							{	stu_belong[temstu]=t;
								used[temstu]=q;
								flag[t][k]=1;
								break;
							}
						}
					else{   int tempt=used[temstu];
						for(q=1;q<used[temstu];q++)
						{
						       if(stu_fdu[temstu][q]==t)
							{       sch_cap[stu_belong[temstu]]++;
								stu_belong[temstu]=t;
								used[temstu]=q;
								flag[t][k]=1;
								break;
							}
						}
						if(q==tempt){flag[t][k]=1;sch_cap[t]++;continue;}
					}
				}
			}
		}


		for(j=1;j<=student;j++)
		{
			if(stu_belong[j]==-1)	cout<<"not accepted"<<endl;
			else	cout<<stu_belong[j]<<endl;
		}
	}
	return 0;
 }










