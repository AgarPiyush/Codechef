#include<stdio.h>
#include<algorithm>
typedef long long int ll;
ll a[1000010],csort[1000010];
/*	#define getcx getchar_unlocked
	inline void fscan(ll *a ) 
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
	}
*/
using namespace std;
int main()
{
	ll i,n,q,j,mid,max=0,b,e;
	scanf("%lld",&n);
	scanf("%lld",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%lld",&b);
		scanf("%lld",&e);
		for(j=b;j<=e;j++)
		a[j]++;
	}
	sort(a,a+n+1);
	printf("%d\n",a[n/2]);

return 0;
}
