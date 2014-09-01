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
/*inline void fscan(ll *a )
{
	ll n=0; int ch = getcx(); int sign = 1;
	while(ch < '0' || ch > '9')
	{
	if(ch == '-') sign=-1; ch = getcx();
	}
	while(ch >= '0' && ch <= '9')
	{
	n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	}
	*a = n * sign;
}*/
int a[20000],n,b[20000],temp[200000],i,j,k,l;
int binarysearch(int s,int l,int u)
{
	int mid=(l+u)/2;
	if(a[mid]==s)
	return mid;
	if(a[mid]>s)
	return binarysearch(s,l,mid-1);
	if(a[mid]<s)
	return binarysearch(s,mid+1,u);
}
int pairs[100000][2],cd[20000],pairs1[100000][2];
int main()
{
	inp(n);
	for(i=1;i<=n;i++)
	{
		inp(a[i]);
		b[i]=a[i];
		cd[i]=b[i];
	}
	sort(a+1,a+n+1);
	int c=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
		int f=0;
		int s=a[i];
		
		
		for(j=i;j<=n;j++)
		if(s==b[j])
		break;
		pairs[c][0]=i;
		pairs[c][1]=j;
		c++;
		for(k=j;k>=i;k--)
		temp[f++]=b[k];
		f=0;
		for(k=i;k<=j;k++)
		b[k]=temp[f++];
		
		}
	}
		int c1=0;
		for(i=n;i>=1;i--)
		{
		if(a[i]!=cd[i])
		{
		int f=0;
		int s=a[i];
		for(j=i;j>=0;j--)
		if(s==cd[j])
		break;
		pairs1[c1][0]=i;
		pairs1[c1][1]=j;
		c1++;
		for(k=i;k>=j;k--)
		temp[f++]=cd[k];
		f=0;
		for(k=j;k<=i;k++)
		cd[k]=temp[f++];
		}
		}
		if(c>c1)
		{
		printf("%d\n",c1);
		for(i=0;i<c1;i++)
		printf("%d %d\n",pairs1[i][1],pairs1[i][0]);
		}
		else
		{
		printf("%d\n",c);
		for(i=0;i<c;i++)
		printf("%d %d\n",pairs[i][0],pairs[i][1]);
		}
	return 0;
}

