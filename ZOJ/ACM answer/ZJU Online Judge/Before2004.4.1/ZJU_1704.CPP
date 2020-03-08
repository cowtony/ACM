#include <stdio.h>
#include <math.h>
int n;
struct point{
    char label;
    double x, y;
} List[20];

double Multiply(const point& p1,const point& p2,const point& p0){
	return((p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x));
}

double min(double a,double b){
    return a < b ? a : b;
}

double max(double a,double b){
    return a > b ? a : b;
}

bool OnSegment(const point& p,const point& p1, const point& p2){
    return((min(p1.x , p2.x) <= p.x) && (p.x <= max(p1.x , p2.x)) &&
			(min(p1.y , p2.y) <= p.y) && (p.y <= max(p1.y , p2.y)) &&
			(Multiply(p , p1 , p2) == 0));
}

bool PointIn(const point& p, const point& a,const point& b,const point& c){
    if(OnSegment(p , a , b)) return 1;
    if(OnSegment(p , b , c)) return 1;
    if(OnSegment(p , c , a)) return 1;
    point p1;
    p1.x = (a.x + b.x + c.x) / 3;
    p1.y = (a.y + b.y + c.y) / 3;
    if((Multiply(p1,a,b) * Multiply(p,a,b) > 0) && 
       (Multiply(p1,b,c) * Multiply(p,b,c) > 0) &&
       (Multiply(p1,c,a) * Multiply(p,c,a) > 0)) return 1;
    return 0;
}

bool check(int a,int b,int c){
    for(int i=0; i<n; i++)
		if(i != a && i != b && i != c){
			if(PointIn(List[i],List[a],List[b],List[c]))
				return 0;
		}    
    return 1;
}

void Work(){
    int a , b , c;
    int A , B , C;   
    double maxArea = 0;
    double Area;
    for(a = 0; a<n; a++)
		for(b = a+1; b<n; b++)
			for(c = b+1; c<n; c++){
				// 0.5 ¡Á [(y3 - y1)(x2 - x1) - (y2 - y1)(x3 - x1)].
				Area = 0.5 * fabs((List[c].y - List[a].y) * (List[b].x - List[a].x) - (List[b].y - List[a].y) * (List[c].x - List[a].x));
				if (Area > maxArea){
					if(check(a , b , c)){
						A = a; B = b; C = c;
						maxArea = Area;
					}
				}
			}
	printf("%c%c%c\n" , List[A].label, List[B].label , List[C].label);
}

int main(){
	//freopen("in.txt","r",stdin);
    int i;
    while(scanf("%d" , &n) , n){		
		for(i = 0; i < n; i++){
			scanf("%1s %lf %lf" , &List[i].label , &List[i].x , &List[i].y);
		}
		Work();
	}

    return 0;
}

