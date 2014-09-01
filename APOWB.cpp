#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define max 100000000000004
typedef long long int lll;
set<lll> a;
int main()
{
	lll i,j,k,l,m,t,n;
	double ans;
	for(i=2;i<=10000;i++)
	{
		ans=i*i*i;
		for(j=i;;)
		{
			ans=ans*i;
			if(ans>max) break;
			a.insert(ans);
		}
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		j=sqrt(n);
		k=cbrt(n);
		if((j*j==n)||((j-1)*(j-1)==n)||((j+1)*(j+1)==n)||(k*k*k==n)||(((k-1)*(k-1)*(k-1))==n)||((k+1)*(k+1)*(k+1))==n)
		printf("YES\n");
		else if(a.find(n)!=a.end()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
