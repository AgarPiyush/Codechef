#include<iostream>
#include<cstdio>
#include<climits>
#include<string>
#include<cstring>
#include<stdlib.h>
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
struct node
{
	struct node *alp[27];
	int key;
};
struct node *s;
char s1[30000],s2[30000];
void insert(int f)
{
	int k;
	s->alp[f]=(struct node*)malloc(sizeof(struct node));
	s=s->alp[f];
	for(k=0;k<=26;k++)
	s->alp[k]=NULL;
}
void recur(struct node *s)
{
	int k;
	for(k=0;k<=26;k++)
	if(s->alp[k]!=NULL)
	{
		printf("%c",k+96);
		recur(s->alp[k]);
		printf("\n");
	}
}
int main()
{
	int i,j;
	struct node *ptr;
	s=(struct node*)malloc(sizeof(struct node));
	for(i=0;i<=26;i++)
	s->alp[i]=NULL;
	ptr=s;
	scanf("%s",s1);
	int l1=strlen(s1);
	for(i=l1-1;i>=0;i--)
	{
		for(j=i;j<l1;j++)
		insert(s1[j]-96);
		s=ptr;
	}
	s=ptr;
	printf("\n");
	if(s->alp['a'-96]!=NULL)
	{
		printf("a");
		s=s->alp['a'-96];
	}
		if(s->alp['p'-96]!=NULL)
		{
		printf("p");
		s=s->alp['p'-96];
		}
	s=ptr;
	recur(s);
	
	return 0;
}

