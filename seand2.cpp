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
#define ll int
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
int t,i,j,k,l,m,n,a[1000005];
long long int pre_val, b[10000];;
char s[10000],ans[100000],temps[10000];
 int count2[1000];
 long long int temp,val;
void permute(int i,int n,int p,int sec,int last)
{
	if(pre_val==0)
			return;
	if(i==n)
	{
		 temp=0,val=0;
		for(int u=0;u<k;u++)
		{
			val=b[u];
			for(int j=sec;j<=last;j++)
				val=((val*10)+(s[j]-'0'));
			val=val%a[u];
			temp=temp+val;
		}
		if(temp<pre_val)
		{
			pre_val=temp;
			strcpy(ans,s);
		}
	}
	else
	{
		for(int k=i;k<=n;k++)
		{
			char temp;
  			temp =s[i];
		    s[i] =s[k];
    		s[k] = temp;	
    		permute(i+1,n,p,sec,last);
  			temp = s[i];
		    s[i] = s[k];
    		s[k] = temp;	
		}
	}
}
bool cmp(char a,char b)
{
	if(a=='0')
		return a>b;
	else if(b=='0')
		return b>a;
	else
	return a>b;
}
int main()
{
	finp(&t);
	while(t--)
	{
		pre_val=LONG_MAX;
		scanf("%s",s);
		int l=strlen(s);
		finp(&k);
		for(i=0;i<k;i++) 
		{
			finp(&a[i]);
			b[i]=0;
		}	
		if(l<=7)
			permute(0,l-1,k,0,l-1);
		else
		{
 
			ll sec=l-7;
			for(i=0;i<k;i++)
			{
				int val=0;
				for(j=0;j<sec;j++)
					val=(val*10+(s[j]-'0'))%a[i];
				b[i]=val;
			}
			permute(sec,l-1,k,sec,l-1);
			sort(s,s+l,cmp);
			for(i=0;i<k;i++)
			{
				int val=0;
				for(j=0;j<sec;j++)
					val=(val*10+(s[j]-'0'))%a[i];
				b[i]=val;
			}
			permute(sec,l-1,k,sec,l-1);
			int c=0;
			count2[0]=0;
			for(i=0;i<l;i++)
			{
				if(s[i]=='0')
					temps[c++]='0';
				else
				count2[s[i]-'0']++;
			}
			for(i=9;i>=1;i--)
			{
				if(count2[i]>1)
				{
					for(j=0;j<count2[i]-1;j++)
						temps[c++]=i+48;
					count2[i]=1;
				}
				
			}
			for(i=9;i>=1;i--)
			{
				if(count2[i]==1)
						temps[c++]=i+48;
				count2[i]=0;
			}
			temps[c++]='\0';
			strcpy(s,temps);
			for(i=0;i<k;i++)
			{
				int val=0;
				for(j=0;j<sec;j++)
					val=(val*10+(s[j]-'0'))%a[i];
				b[i]=val;
			}
			permute(sec,l-1,k,sec-1,l-1);
		}
		printf("%s\n",ans);
		
	}
	return 0;
}
 
 
