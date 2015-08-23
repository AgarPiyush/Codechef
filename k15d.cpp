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
ll t,i,j,k,l,m,n,a[10000005];
string s;
ll pri;
bool prime(ll n)
{
	int c=0;
	ll val=sqrt(n);
	for(ll i=2;i<=val;i++)
	{
		if(n%i==0)
		{
			if(a[i]==0)
				pri=i;
			c++;
		}
	}
	if(c==0)
		return true;
	return false;
}
int main()
{
	a[1]=1;
	for(i=3;i<=3165;i=i+2)
	{
		if(a[i]==0)
		{
			for(j=3;j*i<=10000000;j=j+2)
				a[i*j]=i;
		}
	}
	inp2(l)
	inp1(t);
	while(t--)
	{
		pri=0;
		inp1(n);
		ll cpy=n;
		ll sq=sqrt(n);
		ll ma=0;
		if(n%2==0)
		{
			ma=2;
			while(n%2==0)
				n=n/2;
		}
		bool chk=false;
		while(n>10000000)
		{
			chk=prime(n);
			if(chk==false)
			{
				ma=max(ma,pri);
				while(n%pri==0)
					n/=pri;
				//printf("%lld ",pri );
			}
			else
			{
				ma=max(ma,n);
				break;
			}
		}
		//printf("n is %lld\n",n);
		if(chk==false)
		{
		while(n>1)
		{	
			if(a[n]==0) 
			{
				ma=max(ma,n);
				break;
			}
			ma=max(ma,a[n]);
		//	printf("n is %lld pri is %lld\n",n,a[n]);
			n=n/a[n];
		}
		}
		//if(ma==1) printf("yes\n");
		
		//printf("prime is %lld\n",ma);
		printf("%lld\n",cpy/ma);
		
	}
	return 0;
}
