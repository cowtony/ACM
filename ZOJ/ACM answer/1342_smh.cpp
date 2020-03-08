//word index
// 28495 2002-08-14 09:51:47 Accepted 1342 C++ 00:00.00 380K jet_engine
// :(

#include<stdio.h>
#include<string.h>


int C(int n, int m)
{
	if (m==0) return 1;
	long result=1, i;
	for (i=n; i>n-m; i--)result*=i;
	for (i=2; i<=m; i++) result/=i;
	return result;
}

int str_OK(char str[])
{
	int pos=0;
	int len=strlen(str);
	while(pos+1<len){
		if (str[pos]>=str[pos+1]) return 0;
		pos++;
	}
	return 1;
}

long calc(char str[], int length)
{
	long result=0, i;
	i=length-1;
	while(i>=1) {result+=C(26, i); i--;}
	for (i=1; i<=length; i++){
		if (i==length){
			result+=str[i]-str[i-1];
		} else {
			for (int j=str[i]-str[i-1]-1; j>0; j--){
				result+=C('z'-str[i-1]-j, length-i);
			}
		}
	}
	return result;
}


int main()
{
	char str[7];
	while(scanf("%s", str)!=EOF){
		if (!str_OK(str)) printf("0\n");
		else {
			memmove(&str[1], str, sizeof(char)*(strlen(str)+1));
			str[0]='a'-1;
			printf("%ld\n", calc(str, strlen(str)-1));
		}
	}
	return 0;
}


