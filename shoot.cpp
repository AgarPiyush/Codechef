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
ll t,i,j,k,m,n,a[1000005];
int main()
{
	inp1(t);
	while(t--)
	{
		ll c1,r;
		string s[100];
		vector <ll> l[10000];
		cin >> r >> c1;
		for(i=0;i<r;i++)
		{
			cin >> s[i];
			for(j=0;j<c1;j++)
			{
				if(s[i][j]=='L')
					l[i].push_back(j);
			}
		}
		int flag=0,flag2=0;
		for(i=0;i<r;i++)
		{
			ll c=0;
			flag=0,flag2=0;
			for(j=0;j<c1;j++)
			{
				flag=0;
				if(s[i][j]=='E')
				{
					for(k=i+1;k<r;k++)
					{
						if(s[k][j]=='L')
						{
							flag=1;break;
						}
					}
					if(flag==0)
					{
						if(c>=l[i].size())
						{
							printf("Impossible\n");
							flag2=1;break;
						}
						if(l[i][c]<j)
						{
							s[i][l[i][c]]='.';
							for(k=l[i][c++];k<c1;k++)
								if(s[i][k]=='E')
									s[i][k]='.';
						}
						else
						{
							s[i][l[i][c]]='.';
							for(k=0;k<l[i][c++];k++)
								if(s[i][k]=='E')	
									s[i][k]='.';
						}
					}
				}
			}
				if(flag2)	break;
				if(flag)
			for(j=0;j<c1;j++)
			{
				int temp=-1;
				if(s[i][j]=='E')
				{
					for(k=i+1;k<r;k++)
						if(s[k][j]=='L')
							temp=k;
				}
				if(temp==-1)
				{

				}
				else
				{
					s[i][temp]='.';
					for(k=i;k<temp;k++)
						if(s[k][j]=='E')
							s[k][j]='.';
				}
			}
							if(flag2)	break;

		}
		 flag=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c1;j++)
				if(s[i][j]=='E')
				{
					flag=1;break;
				}
				if(flag) break;
		}
		if(!flag2)
		{
		if(flag) printf("Impossible\n");
		else printf("Possible\n");	
		}
	}
   return 0;
}