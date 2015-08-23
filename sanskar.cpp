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
 
inline void finp(ll *a )
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
ll t,i,j,k,l,m,n,a[100],ans=0,mark[100];
unsigned ll su=0,sum[100];
ll cnt=0;

void recur(int idx,int pos)
{
	if(ans) return;
	if(idx==n)
	{
		ans=1;
		return;
	}
	for(int i=pos;i<k;i++)
	{
//		if(!mark[i])
		{
			sum[i]=sum[i]+a[idx];
			if(su>sum[i])
					recur(idx+1,pos);
			if(su==sum[i])
			{
				mark[i]=1;
				recur(idx+1,pos);
			}
			sum[i]=sum[i]-a[idx];
			if(ans) return;
		}
	}
}
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	finp(&t);
	while(t--)
	{
		su=0;
		ans=0;
		finp(&n);
		finp(&k);
		for(i=0;i<n;i++) {
			mark[i]=0;
			finp(&a[i]);
			su=su+a[i];
		}
		if(su%k!=0) printf("no\n");
		else
		if(k>n) printf("no\n");
		else if(k==n)
		{
			int flag=0;
			for(i=0;i<n;i++)
			{
				if(a[i]==a[0])
					continue;
				flag=1;break;
			}
			if(flag)printf("no\n");
			else printf("yes\n");
		}
		else
		{
			su=su/k;
			cnt=0;	
			int u=0;
			for(i=0;i<n;i++) 
			{
				if(a[i]>su) 
				{
					printf("no\n");u=1;break;
				}
				 sum[i]=0;
			}
			if(u==1) continue;
			sort(a,a+n,cmp);
			for(i=0;i<n;i++)
				if(a[i]==su)
					cnt++;
			ans=0;
			recur(cnt,cnt);
			if(ans==1) printf("yes\n");
				else printf("no\n");

		}
	}
   return 0;
}