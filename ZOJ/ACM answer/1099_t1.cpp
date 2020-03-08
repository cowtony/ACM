 #include<stdio.h>
 #include<string.h>

 int main()
 {
	char line[81]="--------------------------------------------------------------------------------";

	char str[100];int pos=0;
	while(scanf("%s",str)!=EOF)
	{

		int len=strlen(str);
		if(len==4&&str[0]=='<')
		{
			if(str[1]=='b')
			{
				printf("\n");
				pos=0;
			}
			else
			{
				if(pos>0)	printf("\n");
				printf("%s\n",line);

				pos=0;
			}
		}
		else
		{
			if(pos==0)
			{
				printf("%s",str);
				pos+=len;
			}
			else
			{
				if(pos+len<80)
				{

					printf(" %s",str);
					pos+=len+1;
				}
				else
				{
					printf("\n%s",str);
					pos=len;
				}
			}
		}
	}
	printf("\n");

	return 0;

 }





