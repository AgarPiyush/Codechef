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
ll i,j,k,l,m,t;
char s[100000],y[100000],n[100000];
int main()
{
	inp(t);
	for(i=0;i<=10000;i++)
	{
		y[i]='Y';
		n[i]='N';
	}
	while(t--)
	{
		char copy[100000];
		inp(l);
		scanf("%s",s);
		strcpy(copy,s);
		ll ans1=0;
		ll ans2=0;
		char no='N',yes='Y';
		for(i=0;i<l-1;i++)
		{
			if(s[i]=='Y'&&i%2==0)
			{
				ans1++;
				s[i]='N';
				if(s[i+1]=='N')
				{
					ans1++;
					s[i+1]='Y';
					i++;
				}
				else
				{
					i++;
				}
			}
			if(s[i]=='N'&&i%2==1)
			{
				ans1++;
				s[i]='Y';
				if(s[i+1]=='Y')
				{
					ans1++;
					s[i+1]='N';
					i++;
				}
				else
				{
					i++;
				}
			}
		}
	
			if(s[l-1]==s[l-2])
		{
			ans1++;
			if(s[l-1]=='N') 
			s[l-1]='Y';
		}
		
		for(i=0;i<l-1;i++)
		{
			if(copy[i]=='N'&&i%2==0)
			{
					ans2++;
				
				copy[i]='Y';
				if(copy[i+1]=='Y')
				{
					ans2++;
					copy[i+1]='N';
					i++;
				}
				else
				{
					i++;
				}
			}
			if(copy[i]=='Y'&&i%2==1)
			{
				ans2++;
				copy[i]='N';
				if(copy[i+1]=='N')
				{
					ans2++;
					copy[i+1]='Y';
					i++;
				}
				else
				i++;
			}
		}
			if(copy[l-1]==copy[l-2])
			{
			
			ans2++;
			if(copy[i-1]=='N')
			copy[l-1]='Y';
			else
			copy[l-1]='N';
		}
		/*for(i=0;i<l;i++)
		printf("%c",s[i]);
		printf("\n");
		out(ans1);
		for(i=0;i<l;i++)
		printf("%c",copy[i]);
		printf("\n");*/
		if(ans2<ans1)
		out(ans2);
		else
		out(ans1);
	}
	return 0;
}

