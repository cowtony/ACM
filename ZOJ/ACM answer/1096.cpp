 #include<iostream.h>
 #include<math.h>


 int main()
 {
	float	d,m,a,jerk;
	while(cin>>d>>m>>a>>jerk)
	{
		 float	max_val,max_dis;
		 float	t0,v0,s0;
		 float	t1,v1,s1;
		 float	t2,s2;
		 float 	t3,totalt;

		t0=a*1.0/jerk;
		v0=jerk*t0*t0*1.0/2;
		if(v0*2<m)
		{
			v1=m-v0;
			t1=(v1-v0)*1.0/a;

			t2=t0;
		}
		else{
			v0=m*1.0/2;
			t0=sqrt(v0*2.0/jerk);
			t1=0;v1=v0;
			t2=t0;
		}
		s0=jerk*t0*t0*t0*1.0/6;
		s1=v0*t1+a*t1*t1*1.0/2;
		s2=v1*t2+jerk*t2*t2*t2*1.0/3;
		float	tems=s0+s1+s2;
		if(tems*2>d)
		{
			if(t1==0||6*s0>=d/2)
			{
				t0=exp(log(d*1.0/(2*jerk))/3.0);
				totalt=4*t0;
			}
			else
			{
				t1=(-(jerk*t0*t0*1.0/2+a*t0)+sqrt((jerk*t0*t0/2+a*t0)*
				    (jerk*t0*t0/2+a*t0)-2*a*(jerk*t0*t0*t0-d/2)))/a;
				totalt=4*t0+2*t1;
			}

		}
		else
		{
			t3=(d-2*tems)/m;
			totalt=2*(t0+t1+t2)+t3;
		}
		cout.precision(1);
		cout.setf(ios::fixed|ios::showpoint);
		cout<<totalt<<endl;
	}

	return 0;
 }








