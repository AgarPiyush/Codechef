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
#define inp1(a) scanf("%d",&a);
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
ll mult(ll A,ll B)
{
	if ( B == 0 ) return 0;
	ll u = mult(A, B/2);
	ll res;
	if ( B%2 == 0 ) 
		res = u + u;
	else
		res = u + u + A;
	while ( res >= mod ) res -= mod;
	return res;
}
ll t,i,j,k,l,m,n,a[1000005][2];
char s1[1000005],s2[1000005];
ll cal(ll start, ll l1)
{
	int flag = 0,k = 0,pos =0;
	for(i=0;i<=l1;i++)
		a[i][0] = a[i][1] = 0;
	
	while(pos < l1 - 1)
	{
		if(start == 0)
		{
			a[pos][0] = 1;
			if(s1[pos + 1] == '.')
				pos++;
			else if(s2[pos + 1] == '.'&& !a[pos+1][1]) {
					k++;
					start = 1; pos++;	}
			else if(s2[pos] == '.'&&a[pos][1] == 0)
			{
					k++;
					start = 1;
			}
			else{ flag = 1; break;}
		}
		else
		{
			a[pos][1] = 1;
			if(s2[pos + 1] == '.')
				pos++;
			else if(s1[pos + 1] == '.'&& !a[pos+1][0])
				{
					start = 0; pos++;
					k++;
				}
			else if(s1[pos] == '.'&&a[pos][0] == 0)
			{
					k++;
					start = 0;
			}
			else{ flag = 1; break;}
		}
	}
	//printf("ans is %d pos is %d\n",k,pos );
	if(flag) return -1;
	return k;
}
int main()
{
	inp1(t);
	while(t--)
	{
		ll start ;
		scanf("%s %s",s1,s2);
		ll l1, l2;
		l1 = strlen(s1);
		if(s1[0] == '#' && s2[0] =='#'){printf("No\n");continue;}
		ll f1, f2 ;
		if(s1[0] == '#' && s2[0] == '.') { f1 = cal(1,l1); if(f1 == -1) {printf("No\n"); continue;} else {printf("Yes\n%d\n",f1);}}
		if(s1[0] == '.' && s2[0] == '#') { f1 = cal(0,l1); if(f1 == -1) {printf("No\n"); continue;} else {printf("Yes\n%d\n",f1);}}
		if(s1[0] == '.' && s2[0] == '.') { f1 = cal(0,l1); f2 = cal(1,l1);
		if(f1 == -1 && f2 == -1) printf("No\n"); 
		else 
		{
	//		printf("%d %d\n",f1,f2 );
			printf("Yes\n%d\n",min(f1,f2));
		}
		}
	}
	return 0;
}
