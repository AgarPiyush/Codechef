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
#define max 30
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
#define total(v) upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l)
inline void finp(int *a )
{
	int n=0; ll ch = getcx(); ll sign = 1;
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
map<int,int> mps;
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
 
struct trie_node
{
	trie_node *next[3];
	vector<int> v;
};
 
int t,i,j,k,l,r,m,n;
int a[500010];
trie_node *root;
 
inline trie_node *insert(struct trie_node *temp,int x,int mask,int ind)
{
	//getchar();
	if(mask==0)
		return temp;
	if(temp==NULL)
	{
		temp=new trie_node();
		temp->next[0]=temp->next[1]=NULL;
	}
	temp->v.pb(ind);
	if(x&(mask>>1))
		temp->next[1]=insert(temp->next[1],x,mask>>1,ind);
	else
		temp->next[0]=insert(temp->next[0],x,mask>>1,ind);
	return temp;	
}
inline void show(struct trie_node *root,int len,int x)
{
//	printf("yes len %lld\n",len);
	if(root==NULL) return;
	if(len>=20)
	{
		printf("for x %d %d\n",x,len );
		//printf("cnt %d end %d len %d\n",root->cnt,root->end,len);
		for(ll i=0;i<root->v.size();i++)
			cout << root->v[i];
		printf("\n");
	}
	show(root->next[0],len+1,0);
	show(root->next[1],len+1,1);
}
int flag=0;
inline int findk(struct trie_node *root,int l,int r,int k,int len)
{
 
	if(!root->next[0]&&!root->next[1])
		return root->v[0];
	if(root->next[0])
	{
		int leftk=total(root->next[0]->v);
		if(leftk>=k) 
			return findk(root->next[0],l,r,k,len+1);
		else
			if(root->next[1])
				return findk(root->next[1],l,r,k-leftk,len+1);
	}
	else if(root->next[1])
		return findk(root->next[1],l,r,k,len+1);		
}
inline int cnt(struct trie_node *root,int l,int r,int x,int mask)
{
	if(root==NULL)
		return 0;
 
	if(!root->next[0]&&!root->next[1])
		return total(root->v);
	
 
	if(x&(mask>>1))
	{
		if(root->next[0])
			return total(root->next[0]->v)+cnt(root->next[1],l,r,x,mask>>1);
		else
		if(root->next[1])
			return cnt(root->next[1],l,r,x,mask>>1);
	}
	else return cnt(root->next[0],l,r,x,mask>>1);
}
vector<int>::iterator it;
inline bool present(vector<int> &v)
{
	if(v.empty()) return false;
	it =lower_bound(v.begin(),v.end(),l);
	if(it!=v.end()&&*it>=l&&*it<=r)
		return true;
	return false;
}
inline int xors(struct trie_node *root,int l,int r,int x,int mask,int len)
{
	if(root==NULL)
		return 0;
 
	if(mask==1||root->v.size()==1)
		return root->v[0];
	if(x&(mask>>1))
	{
		if(root->next[0]&&present(root->next[0]->v))
				return xors(root->next[0],l,r,x,mask>>1,len+1);
		else
			return xors(root->next[1],l,r,x,mask>>1,len+1);
	}
	else
	{
		if(root->next[1]&&present(root->next[1]->v))
			return xors(root->next[1],l,r,x,mask>>1,len+1);
		else
			return xors(root->next[0],l,r,x,mask>>1,len+1);
	}
}
inline void deletes(struct trie_node *root,int x,int mask)
{
	if(root==NULL) return;
	root->v.pop_back();
	if(mask==1)
		return;
	if(x&(mask>>1))
		deletes(root->next[1],x,mask>>1);
	else
		deletes(root->next[0],x,mask>>1);
}
int main()
{
	int q,j;
	root=new trie_node();
	root->next[0]=root->next[1]=NULL;
	finp(&m);
	n=0;
	int ch,x;
	while(m--)
	{
		finp(&ch);
		if(ch==0)
		{
			finp(&x);
			a[n++]=x;
			root=insert(root,a[n-1],(1<<19),n-1);
		}
		else if(ch==1)
		{
			finp(&l);finp(&r);finp(&x);
			l--;r--;
			printf("%d\n",a[xors(root,l,r,x,(1<<19),0)]);
		}
		else if(ch==2)
		{
			finp(&x);
			x--;
			for(int i=n-1-x;i<=n-1;i++)
				deletes(root,a[i],1<<19);
			n=n-x-1;
		//	printf("n is %d\n",n);
		}
		else if(ch==3)
		{
			finp(&l);finp(&r);finp(&x);
			l--;r--;
			printf("%d\n",cnt(root,l,r,x,1<<19));		
		}
		else
		{
			finp(&l);finp(&r);finp(&x);
			l--;r--;
			printf("%d\n",a[findk(root,l,r,x,0)]);			
		}
	}
	free(root);
	return 0;
} 