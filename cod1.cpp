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
ll t,i,j,k,l1,l2,m,n;
char a[100005],s1[100005],s2[100005];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	inp1(t);
	while(t--)
	{

		scanf("%s",s1);
		scanf("%s",a);
		l1=strlen(s1);
		l2=strlen(a);
		
		sort(a,a+l2,cmp);
		i=0;j=0;
		while(j<l2&&i<l1)
		{
			if(s1[i]<a[j])
			{
				s1[i]=a[j];i++;j++;
			}
			else
			{
				i++;
			}
		}
		printf("%s\n",s1);
	}
   return 0;
}