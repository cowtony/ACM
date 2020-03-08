#include<iostream.h>
#include<math.h>
 const double preci=10e-12;
 int maxorsame(double fir,double sec)
 {
        if(fir>sec)     return 1;
	if(fabs(fir-sec)<preci)	return 1;
	return 0;
 }
 struct node
 {
        double x;
        double y;
 };
 struct line
 {
        node start;
        node end;
 };
 double calsize(node point[],int n)
 {
        int i;
        double s;
        s=point[0].y*(point[1].x-point[n-1].x);
        for(i=1;i<n;i++)
                s+=point[i].y*(point[(i+1)%n].x-point[i-1].x);
        return (s/2);
 }

 double max(double fir,double sec)
 {
        if(fir>sec)     return fir;
        else    return sec;
 }
 double min(double fir,double sec)
 {
        if(fir<sec)     return fir;
        else    return sec;
 }
 double multiply(node fir,node sec,node mid)
 {
        return ((fir.x-mid.x)*(sec.y-mid.y)-(sec.x-mid.x)*(fir.y-mid.y));
 }
 int intersect(line fir,line sec)
 {
	if((maxorsame(max(fir.start.x,fir.end.x),min(sec.start.x,sec.end.x)))&&
	   (maxorsame(max(sec.start.x,sec.end.x),min(fir.start.x,fir.end.x)))&&
	   (maxorsame(max(fir.start.y,fir.end.y),min(sec.start.y,sec.end.y)))&&
	   (maxorsame(max(sec.start.y,sec.end.y),min(fir.start.y,fir.end.y)))&&
           (maxorsame(multiply(fir.start,sec.start,sec.end)*multiply(sec.start,fir.end,sec.end),0))&&
           (maxorsame(multiply(sec.end,fir.start,fir.end)*multiply(fir.start,sec.start,fir.end),0)))
           return 1;
        return 0;
 }

 int ispoly(node point[],int n)
 {
        int i,j;
        for(i=0;i<n-2;i++)
        {
                line fir;
                fir.start=point[i];
                fir.end=point[i+1];
                for(j=i+2;j<n;j++)
                {
			if(i==0&&j==n-1)        continue;
                        line sec;
                        sec.start=point[j];
                        sec.end=point[(j+1)%n];
                        if(intersect(fir,sec))   return 0;
                }
        }
        return 1;
 }

int main( )
{
        int n;int count=0;node point[1001];
        
        while(cin>>n)
        {
                if(n==0)        break;
                count++;
                if(count!=1)    cout<<endl;
                int i;
                for(i=0;i<n;i++)
                        cin>>point[i].x>>point[i].y;
                cout<<"Figure "<<count<<": ";
                if(n<3||!ispoly(point,n))    cout<<"Impossible"<<endl;
                else
                {       double size=fabs(calsize(point,n));
                        if(size<preci) cout<<"Impossible"<<endl;
                        else{
                                cout.precision(2);
                                cout.setf(ios::showpoint|ios::fixed);
                                cout<<size<<endl;
                        }
                }
        }
        return 0;
}

