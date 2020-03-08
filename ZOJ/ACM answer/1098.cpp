 #include<iostream.h>


 int main()
 {
 char str;
 while(cin>>str)
 {
	int val[33];
	int j;

	int flag=0; int accu=0;
	int pc=0;

	for(j=0;j<=31;j++)
	{
		int i;
		val[j]=0;
		for(i=0;i<8;i++) {	val[j]=val[j]*2+str-48;
					if(i==7)	break;
					cin>>str;

		}


		if(j==31)	break;
		cin>>str;
	}
	while(1)
	{
		if(flag)	break;
		 int temval=val[pc];
		 int head=temval/32;
		 int tail=temval%32;
		pc=(pc+1)%32;
		if(head==0)	val[tail]=accu;
		if(head==1)	accu=val[tail];
		if(head==2)
		{
			if(accu==0)
			{
				pc=tail;
				continue;
			}
		}
		if(head==3)	;
		if(head==4)
		{
			if(accu==0)	accu=255;
			else	accu--;
		}
		if(head==5)
		{
			if(accu==255)	accu=0;
			else	accu++;
		}
		if(head==6){	pc=tail;continue;}
		if(head==7){	flag=1;}

	}
	int div=128;
	for(int i=0;i<8;i++)
	{
		cout<<(accu/div);
		accu=accu%div;
		div/=2;
	}
	cout<<endl;
 }
	return 0;
 }




