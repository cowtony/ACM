#include <iostream>
#include <algorithm>
using namespace std;
#define MAXNUM 50002

struct EdgeType
{
	int a, b, c;
};

EdgeType Edge[MAXNUM];
int S[MAXNUM];
int iN;

bool operator < (const EdgeType & a, const EdgeType & b)
{
	return a.b < b.b;
}

bool Input()
{
	cin >> iN;
	if(!cin ) 
		return false;
	int i;
	for (i = 0; i < iN; ++i)
	{
		cin >> Edge[i].a >> Edge[i].b >> Edge[i].c;
		Edge[i].b++;
	}
	return true;
}

/*
int Compare(const void * pa, const void * pb)
{
	EdgeType *aa = (EdgeType *)pa;
	EdgeType *bb = (EdgeType *)pb;
	return aa->b - bb->b;
} */

int Calculate()
{
	int i;
	S[0] = 0;
	sort(Edge, Edge + iN);
	int CountEdge = 0;
	for (i = 1; i < MAXNUM; ++i)
	{
		S[i] = S[i-1];
		int curr = Edge[CountEdge].b;
		while(i == curr)
		{
			int temp = S[Edge[CountEdge].a] + Edge[CountEdge].c;
			if(S[i] < temp)
				S[i] = temp;
			CountEdge ++;
			curr = Edge[CountEdge].b;
		}
		int k;
		for (k = i-1; k > 0; --k)
		{
			if(S[k]-S[i] >= k-i)
				break;
			S[k] = k-i + S[i];
		}
		if(CountEdge == iN)
			return S[i];
	}
	return S[MAXNUM-1];
}

int main()
{
	while(Input())
	{
		cout << Calculate() << endl;
	}
	return 0;
}

//经比较，此题中使用sort()排序效率比qsort()要高一些