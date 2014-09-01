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
#define inp(a) scanf("%d",&a)
#define line(a) printf("%d ",a);
#define next() printf("\n");
#define out(a) printf("%d\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll int
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
struct node
{
	int high;
	int low;
}a[1000001];
ll b[1000001];
int main()
{
	ll i,j,k,l,m,n;
	fscan(&n);fscan(&k);
	for(i=1;i<=n;i++)
	{
		fscan(&j); b[i]=j;
		if(a[j].low==0) {
		a[j].low=i; a[j].high=i;}
		else
		{
			if(i>a[j].high) a[j].high=i;
		}
	}
	ll flag=0,ans,ans1;
	ll min=INT_MAX;
	for(i=1;i<=n;i++)
	{
		ans=ans1=0;
		l=k-b[i];
		if(l>0&&a[l].low!=0&&l!=b[i])
		{
			flag=1;
			ll min1=std::min(a[l].low,n-a[l].high+1);
			ll min2=std::min(a[b[i]].low,n-a[b[i]].high+1);	
			ans=std::max(min1,min2);
			if(min>ans) min=ans;
		}
	}
	if(flag)
	out(min);
	else printf("-1\n");	
	return 0;
}

