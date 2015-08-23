/* Author : Piyush Agarwal

 _._ _..._ .-',     _.._(`))
'-. `     '  /-._.-'    ',/
   )         \            '.
  / _    _    |             \
 |  a    a    /              |
 \   .-.                     ;  
  '-('' ).-'       ,'       ;
     '-;           |      .'
        \           \    /
        | 7  .__  _.-\   \
        | |  |  ``/  /`  /
       /,_|  |   /,_/   /
          /,_/      '`-'
*/
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
ll t,i,j,k,l,m,n;
double a[1005][1005],sum[1005][1005];
string s;
int main()
{
	a[1][1]=1;
	sum[1][1]=1;
	for(i=2;i<=1000;i++)
	{
		a[i][1]=a[i-1][1]/2.0;
		sum[i][1]=sum[i-1][1]+a[i][1];
		a[1][i]=a[1][i-1]/2.0;
		sum[1][i]=sum[1][i-1]+a[1][i];
	}
	for(i=2;i<=1000;i++)
	{
		for(j=2;j<=1000;j++)
		{
			a[i][j]=(a[i-1][j]/2.0)+(a[i][j-1]/2.0);
			sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
/*	for(i=1;i<=3;i++)
	{
		for(j=1;j<=4;j++)
			printf("%lf ",a[i][j] );
		printf("\n");
	}
	printf("\n");
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=4;j++)
			printf("%lf ",sum[i][j] );
		printf("\n");
	}*/
	inp1(t);
	while(t--)
	{
		inp2(j,k);
		if(k==1||j==1) 
			{
				printf("%lld.000000\n",max(k,j));
				continue;
			}
			double ans=sum[j-1][k-1]+1;
			//printf("prev %lf\n",ans );
			double p=a[1][k];
			double y=a[j][1];
			ans=ans+p+y;

			for(i=2;i<=j-1;i++)
			{
				p=p+a[i][k-1]/2;
				ans=ans+p;
			}
			for(i=2;i<=k-1;i++)
			{
				y=y+a[j-1][i]/2;
				ans=ans+y;
			}
			printf("%lf\n",ans);
		
		
	}
	return 0;
}
