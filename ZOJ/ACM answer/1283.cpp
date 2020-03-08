#include<iostream.h>
#include<string.h>

int slump(char* input)
{
	int len=strlen(input);
	if(len<3)	return 0;
	if(input[0]!='D'&&input[0]!='E')	return 0;
	int i;
	for(i=1;i<len;i++)
		if(input[i]!='F')	break;
	if(input[i]=='G'&&i==len-1)	return 1;
	char temp[61];int j;
	for(j=i;j<len;j++)
		temp[j-i]=input[j];
	temp[len-i]='\0';
	if(slump(temp))	return 1;
	return 0;
}


int slimp(char* input)
{
	int len=strlen(input);
	if(len==1)	return 0;
	if(input[0]!='A')	return 0;
	if(len==2)
	{
		if(input[1]=='H')	return 1;
		return 0;
	}
	if(input[len-1]!='C')	return 0;
	char temp[61];
	int i;
	if(input[2]=='B')
	{
		for(i=3;i<len-1;i++)
			temp[i-3]=input[i];
		temp[len-4]='\0';
		if(slimp(temp))	return 1;
		return 0;
	}
	for(i=2;i<len-1;i++)
		temp[i-2]=input[i];
	temp[i-3]='\0';
	if(slump(temp))	return 1;
	return 0;
}


int slurpy(char* input)
{
	int i;
	int len=strlen(input);
	for(i=len-1;i>=0;i--)
		if(input[i]=='D'||input[i]=='E')	break;

	if(i==len)	return 0;
	char fir[61],sec[61];
	int j;
	for(j=0;j<=i;j++)
		fir[j]=input[j];
	fir[i+1]='\0';
	for(j=i+1;j<len;j++)
		sec[j-i-1]=input[j];
	sec[len-i-1]='\0';
	cout<<fir<<"    "<<sec<<endl;
	if(slimp(fir)&&slump(sec))	return 1;
	return 0;
}

int main()
{
	char input[61];
	int n;
	cin>>n;
	cout<<"SLURPYS OUTPUT"<<endl;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>input;
		if(slurpy(input))	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
	
	