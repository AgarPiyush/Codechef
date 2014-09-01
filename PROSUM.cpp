#include<iostream>
#include<cstdio>
#include<climits>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<queue>
using namespace std;
#define inp(a) scanf("%lld",&a)
#define line(a) printf("%lld ",a);
#define next() printf("\n");
#define out(a) printf("%lld\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll long long int
#define mod 1000000007
#define getcx getchar_unlocked
inline void fscan(int *a )
{
	int n=0; int ch = getcx(); int sign = 1;
	while(ch < '0' || ch > '9')
	{
	if(ch == '-') sign=-1; ch = getcx();
	}
	while(ch >= '0' && ch <= '9')
	{
	n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	}
	*a = n * sign;
}
int i,k,j,n,m,t,a[100010];
int main()
{
	fscan(&t);
	while(t--)
	{
		fscan(&n);
		int count=0,two=0;
		ll sum=0;
		for(i=0;i<n;i++)
		{
			fscan(&a[i]);
			if(a[i]>2)
			count++;
			else if(a[i]==2)
			two++;
		}
		sum=(count*(count-1))/2+two*count;
		out(sum);
	}
	return 0;
}

