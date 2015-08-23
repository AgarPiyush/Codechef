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
ll t,i,j,k,l,m,n;
string s;
struct node
{
	ll _2c;
	ll _1c;
	ll _0c;
	ll val;
}a[1000005];

char d[100005];
void segment(ll node,ll b,ll e)
{
	if(b==e)
	{
		if(b==0)
		{
			a[node]._0c++;
			a[node].val=0;
			return;
		}
		int k=(d[b-1]-'0')%3;
		a[node].val=k;
		if(k==0)
			a[node]._0c++;
		else if(k==1)
			a[node]._1c++;
		else
			a[node]._2c++;
		return;
	}
	segment(node<<1,b,(e+b)>>1);
	segment((node<<1)+1,((e+b)>>1)+1,e);
	a[node].val=(a[node<<1].val+a[(node<<1)+1].val)%3;
	if(a[node<<1].val==0)
	{
		a[node]._0c=a[node<<1]._0c+a[(node<<1)+1]._0c;
		a[node]._1c=a[(node<<1)]._1c+a[(node<<1)+1]._1c;
		a[node]._2c=a[(node<<1)]._2c+a[(node<<1)+1]._2c;
	}
	else if(a[node<<1].val==1)
	{
		a[node]._0c=a[node<<1]._0c+a[(node<<1)+1]._2c;
		a[node]._1c=a[(node<<1)]._1c+a[(node<<1)+1]._0c;
		a[node]._2c=a[(node<<1)]._2c+a[(node<<1)+1]._1c;
	}
	else if(a[(node<<1)].val==2)
	{
		a[node]._0c=a[(node<<1)]._0c+a[(node<<1)+1]._1c;
		a[node]._1c=a[(node<<1)]._1c+a[(node<<1)+1]._2c;
		a[node]._2c=a[(node<<1)]._2c+a[(node<<1)+1]._0c;
	}
}
struct node query(ll node,ll b,ll e,ll i,ll j)
{
	if(b>=i&&j>=e)
		return a[node];
	
	if(i>e||b>j)
	{
		struct node p;
		p.val=-1;
		return p;
	}
	struct node p1=query((node<<1),b,(e+b)>>1,i,j);
	struct node p2=query((node<<1)+1,((e+b)>>1)+1,e,i,j);
	if(p1.val==-1)
		return p2;
	else if(p2.val==-1)
		return p1;
	struct node p3;
	p3.val=(p1.val+p2.val)%3;
	if(p1.val==0)
	{
		p3._0c=p1._0c+p2._0c;
		p3._1c=p1._1c+p2._1c;
		p3._2c=p1._2c+p2._2c;
	}
	else if(p1.val==1)
	{
		p3._0c=p1._0c+p2._2c;
		p3._1c=p1._1c+p2._0c;
		p3._2c=p1._2c+p2._1c;
	}
	else if(p1.val==2)
	{
		p3._0c=p1._0c+p2._1c;
		p3._1c=p1._1c+p2._2c;
		p3._2c=p1._2c+p2._0c;
	}	
	return p3;
}
void update(ll node,ll b,ll e,ll pos,ll vals)
{
	if(e<pos||b>pos)
		return;
	if(b==e&&b==pos)
	{
		a[node]._0c=a[node]._1c=a[node]._2c=0;
		int k=vals%3;
		a[node].val=k;
		if(k==0)
			a[node]._0c++;
		else if(k==1)
			a[node]._1c++;
		else
			a[node]._2c++;
		return;
	}
	if(b==e) return;
	update((node<<1),b,(e+b)>>1,pos,vals);
	update((node<<1)+1,((e+b)>>1)+1,e,pos,vals);
	a[node].val=(a[(node<<1)].val+a[(node<<1)+1].val)%3;
	if(a[(node<<1)].val==0)
	{
		a[node]._0c=a[(node<<1)]._0c+a[(node<<1)+1]._0c;
		a[node]._1c=a[(node<<1)]._1c+a[(node<<1)+1]._1c;
		a[node]._2c=a[(node<<1)]._2c+a[(node<<1)+1]._2c;
	}
	else if(a[(node<<1)].val==1)
	{
		a[node]._0c=a[(node<<1)]._0c+a[(node<<1)+1]._2c;
		a[node]._1c=a[(node<<1)]._1c+a[(node<<1)+1]._0c;
		a[node]._2c=a[(node<<1)]._2c+a[(node<<1)+1]._1c;
	}
	else if(a[2*node].val==2)
	{
		a[node]._0c=a[(node<<1)]._0c+a[(node<<1)+1]._1c;
		a[node]._1c=a[(node<<1)]._1c+a[(node<<1)+1]._2c;
		a[node]._2c=a[(node<<1)]._2c+a[(node<<1)+1]._0c;
	}
}

int main()
{
	ll l,q;
	finp(&l);finp(&q);
	scanf("%s",d);
	segment(1,0,l);
	ll ch,lef,righ;
		
	while(q--)
	{
		finp(&ch);
		finp(&lef);
		finp(&righ);
		if(ch==2)
		{
			struct node f=query(1,0,l,lef-1,righ);
			printf("%lld\n",(f._0c*(f._0c-1))/2+(f._1c*(f._1c-1))/2+(f._2c*(f._2c-1))/2);
		}
		else
			update(1,0,l,lef,righ);
	}
	return 0;
}
