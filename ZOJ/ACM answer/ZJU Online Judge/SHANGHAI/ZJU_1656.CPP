#include <stdio.h>
#include <string.h>
#include <math.h>

struct person_dat
{
	char name[60];
	double shoot_power , shoot_accuracy;
	double target , ac;
} list[12];

bool init()
{
	scanf("%s" , list[0].name);
	if(strcmp(list[0].name , "END") == 0) return 0;
	scanf("%lf%lf" , &list[0].shoot_power , &list[0].shoot_accuracy);

	for(int i=1; i<11; i++)
	{
		scanf("%s%lf%lf" , list[i].name , &list[i].shoot_power , &list[i].shoot_accuracy);
	}
	return 1;
}

bool cmp(const person_dat& a, const person_dat& b)
{
	if(a.ac != b.ac) return a.ac > b.ac;
	return strcmp(a.name , b.name) < 0;
}

void solve()
{
	int i , j;
	double r , s;
	double pi = acos(0) * 2;

	for(i=0; i<11; i++)
	{
		if(list[i].shoot_power <= 5){ list[i].ac = 0; continue;}
		list[i].target = list[i].shoot_accuracy * 5;
		r = 121 / (list[i].shoot_power * list[i].shoot_power / 25.0 - 1);
		r = sqrt(r);
	
		if(r >= sqrt(2.5 * 2.5 + 3.75 * 3.75)) // case 1
			s = 2.5 * 7.5;
		else if(r <= 2.5) // case 2
			s = pi * r * r / 2;
		else if(r <= 3.75) // case 3
		{
			double theta = acos(2.5 / r);
			s = 2.5 * r * sin(theta) + (pi / 2 - theta) * r * r;
		}
		else // case 4
		{
			double theta = acos(2.5 / r);
			s = 2.5 * r * sin(theta);
			double alpha = acos(3.75 / r);
			s += 3.75 * r * sin(alpha);
			s += (pi / 2 - alpha - theta) * r * r;
		}

		list[i].ac = list[i].target * (( 2.5 * 7.5 ) - s) / 2.5 / 7.5;
	}

	person_dat tmp;

	for(i=0; i<5; i++)
	{
		for(j=i+1; j<11; j++)
			if(cmp(list[j] , list[i]))
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		printf("%s %.2lf%%\n" , list[i].name , list[i].ac);
	}
	putchar('\n');
}

int main()
{
//	freopen("test/in0.in" , "r" ,stdin);

	int CaseNo = 0;

	while(init())
	{
		printf("Case %d:\n" , ++CaseNo);
		solve();
	}
	
	return 0;
}
