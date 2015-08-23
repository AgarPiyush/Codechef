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
ll t,i,j,k,l,m,n,a[1000005];
ll w,d,s,r;
int main()
{
	inp1(t);
	while(t--)
	{
		ll w1,d1,s1,r1;
		inp2(w1,d1);
		inp2(s1,r1);
		double w=w1*1.0,d=d1*1.0,s=s1*1.0,r=r1*1.0;
		if(w==0)
		{
			double t1=d/r;
			printf("%lf %lf\n",d,t1);
			continue;
		}
		else if(d==0)
		{
			double t1=w/s;
			printf("0.000000 %lf\n",t1);
			continue;
		}
		if(s>=r)
		{
			double dis=sqrt(w*w+d*d);
			double ti=dis/s;
			printf("0.000000 %lf\n",ti);
		}
		else
		{
			double dis=sqrt(r*r-s*s);
			double x=d-((s*w)/(dis));
			double x2=d+((s*w)/(dis));
			double dia2=sqrt(((d-x2)*(d-x2))+(w*w));
			double t2=(x2)/r+dia2/s;
		 	if(x<=0)
			{
				double dis=sqrt(w*w+d*d);
				double ti=dis/s;
				if(ti<=t2)
					printf("0.000000 %lf\n",ti);
				else 
					printf("%lf %lf\n",x2,t2);
			}
			else
			{
				double dia=sqrt(((d-x)*(d-x))+(w*w));
				double ti=(x)/r+dia/s;
				if(ti<t2)
		 			printf("%lf %lf\n",x,ti );
		 		else
					printf("%lf %lf\n",x2,t2);
			}
		}
	}
	return 0;
}
