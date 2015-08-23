//Author : Piyush Agarwal
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define inp1(a) scanf("%lld",&a);
#define outl(a) printf("%lld\n",a);
#define out(a) printf("%lld ",a);
#define line printf("\n");
#define FOR(i,b,e) for(i=b;i<=e;i++)
#define mp make_pair
#define pb push_back
#define inp2(a,b) scanf("%lld %lld",&a,&b)
#define getcx getchar_unlocked
#define chkbit(s,b) (s & (1<<b))
#define setbit(s,b) (s | (1<<b))
#define clrbit(s,b) (s &= ~(1<<b))
 
/*inline void finp(ll *a )
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
ll power(ll b,ll e)
{
	ll x=1;
	while(e>0)
	{
		if(e&1)
			x=x*b;
		b=b*b;
		e=e/2;
	}
	return x;
}  
ll gcd(ll a,ll b)
{
    if(b==0)
          return a;
    return gcd(b,a%b);
}
ll t,i,j,k,l,m,n,a[1000005],sum[100000],b[100000],mat[25][25];
int main()
{
	for(i=1;i<=24;i++)
	{
		mat[i][1]=i;mat[i][i]=1;
	}
	for(i=3;i<=21;i++)
	{
		for(j=2;j<=i-1;j++)
			mat[i][j]=mat[i-1][j]+mat[i-1][j-1];
	}
	while(1)
	{
		inp2(k,l);
		printf("%lld\n",mat[k][l]);
	}
	/*inp1(t);
	while(t--)
	{
		inp2(n,k);
		for(i=0;i<n;i++)
		{
			inp1(a[i]]);sum[i]=0;
		}
		sort(a,a+n);
		for(i=0;i<k;i++)
	}*/
   return 0;
}