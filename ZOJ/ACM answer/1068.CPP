 #include<iostream.h>
 #include<string.h>

 char code[31][5];int len[31];
 void initial()
 {
	strcpy(code[1],".-");len[1]=2;
	strcpy(code[2],"-...");len[2]=4;
	strcpy(code[3],"-.-.");len[3]=4;
	strcpy(code[4],"-..");len[4]=3;
	strcpy(code[5],".");len[5]=1;
	strcpy(code[6],"..-.");len[6]=4;
	strcpy(code[7],"--.");len[7]=3;
	strcpy(code[8],"....");len[8]=4;
	strcpy(code[9],"..");len[9]=2;
	strcpy(code[10],".---");len[10]=4;
	strcpy(code[11],"-.-");len[11]=3;
	strcpy(code[12],".-..");len[12]=4;
	strcpy(code[13],"--");len[13]=2;
	strcpy(code[14],"-.");len[14]=2;
	strcpy(code[15],"---");len[15]=3;
	strcpy(code[16],".--.");len[16]=4;
	strcpy(code[17],"--.-");len[17]=4;
	strcpy(code[18],".-.");len[18]=3;
	strcpy(code[19],"...");len[19]=3;
	strcpy(code[20],"-");len[20]=1;
	strcpy(code[21],"..-");len[21]=3;
	strcpy(code[22],"...-");len[22]=4;
	strcpy(code[23],".--");len[23]=3;
	strcpy(code[24],"-..-");len[24]=4;
	strcpy(code[25],"-.--");len[25]=4;
	strcpy(code[26],"--..");len[26]=4;
	strcpy(code[27],"..--");len[27]=4;
	strcpy(code[28],".-.-");len[28]=4;
	strcpy(code[29],"---.");len[29]=4;
	strcpy(code[30],"----");len[30]=4;

 }

 int main()
 {
	initial();

	int nn;int i,j;
	cin>>nn;
	for(i=1;i<=nn;i++)
	{
		char str[101];
		cin>>str;
		int length=strlen(str);
		char pass[500];int pt=0;int a[101];
		int ant=0;
		for(j=0;j<length;j++)
		{
			int ttt;
			if(str[j]>64&&str[j]<91) ttt=str[j]-64;
			else if(str[j]=='_') ttt=27;
			else if(str[j]==',') ttt=28;
			else if(str[j]=='.') ttt=29;
			else if(str[j]=='?') ttt=30;


			a[ant++]=len[ttt];
			for(int t=0;t<len[ttt];t++)
			{

				pass[pt++]=code[ttt][t];
			}
		}
		int t,k;int beg=0;
		cout<<i<<": ";
		for(j=ant-1;j>=0;j--)
		{

			for(t=1;t<=30;t++)
			{
				if(len[t]!=a[j]) continue;
				for(k=0;k<a[j];k++)

					if(code[t][k]!=pass[beg+k]) break;
				if(k==a[j])
				{
					if(t<=26) cout<<(char)(t+64);
					if(t==27) cout<<"_";
					if(t==28) cout<<",";
					if(t==29) cout<<".";
					if(t==30) cout<<"?";
					break;
				}
			}
			beg+=a[j];
		}

		cout<<endl;
	}
	return 0;
 }



