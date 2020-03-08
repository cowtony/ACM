#include<iostream.h>
#include<math.h>

struct POS{double x, y;};
POS list[26][3];
int sp[26];

double dist(POS& p1, POS& p2)
{
	return ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
const double eps=1e-6;

int check(int i)
{
	double d1, d2, d3;
	d1=dist(list[i][0], list[i][1]);
	d2=dist(list[i][0], list[i][2]);
	if (fabs(d1-d2)>eps) return 0;
	d3=dist(list[i][1], list[i][2]);
	if (fabs(d1-d3)>eps) return 0;
	if (fabs(d2-d3)>eps) return 0;
	return 1;
}

int main()
{
	double x, y, sqrt3=1.7320508075688772935274463415059;
	int i, j, n;
        char c;

	freopen("d:/in", "r", stdin);
	
	while(cin>>n){
		if (n==0) break;

		memset(sp, 0, sizeof(sp));

		for (i=0; i<n; i++){
			x=-i;
			y=sqrt3*i;
			for (j=0; j<=i; j++){
				cin>>c;
				POS& p=list[c-'a'][sp[c-'a']++];
				p.x=x+2*j;
				p.y=y;
			}
		}
		int lose=1;
		for (i=0; i<26; i++){
			if (sp[i]==3){
				if (check(i)){
					cout<<char(i+'a');
					lose=0;
				}
			}
		}
		if (lose){
			cout<<"LOOOOOOOOSER!";
		}
		cout<<endl;
	}
	return 0;
}




