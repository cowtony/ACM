 //56144 2002-11-22 12:38:45 Accepted 1294 C++ 00:00.00 432K Century Ghost
 #include<iostream.h>
 #include<string.h>

 int main()
 {
	char str[7][20];
	strcpy(str[0],"Hole-in-one.");
	strcpy(str[1],"Double eagle.");
	strcpy(str[2],"Eagle.");
	strcpy(str[3],"Birdie.");
	strcpy(str[4],"Par.");
	strcpy(str[5],"Bogey.");
	strcpy(str[6],"Double Bogey.");
	int need,stroke;int count=0;
	while(1)
	{
		cin>>need>>stroke;
		if(need==0&&stroke==0)	break;
		count++;
		cout<<"Hole #"<<count<<endl;
		if(stroke==1) {	cout<<str[0]<<endl<<endl;continue;}
		int temp=stroke-need+4;
		if(temp>6)	temp=6;
		cout<<str[temp]<<endl<<endl;
	}
	return 0;
 }

