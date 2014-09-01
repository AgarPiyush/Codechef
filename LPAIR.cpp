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
inline void fscani(int *a )
{
	int n=0; int ch = getcx(); int sign = 1;
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
int n;
int a[1000000],b[1000000];
int temp2[1000000],temp[1000000];

void merge(int a[], int l, int mid, int u)
{
long long int ac=l,bc=mid+1,cc=l,i;
while(ac<=mid&&bc<=u)
{
if(a[ac]<a[bc])
{
temp2[cc]=b[ac];
temp[cc++]=a[ac++];
}
else
{
 temp2[cc]=b[bc];	
 temp[cc++]=a[bc++];
}
}
while(ac<=mid)
{
temp2[cc]=b[ac];
temp[cc++]=a[ac++];
}
while(bc<=u)
{
temp2[cc]=b[bc];
temp[cc++]=a[bc++];
}
for(i=l;i<cc;i++)
{
a[i]=temp[i];b[i]=temp2[i];
}
}



void mergesort(int a[],int l, int u)
{
int mid=(l+u)/2;
if(l!=u)
{
mergesort(a,l,mid);
mergesort(a,mid+1,u);
merge(a,l,mid,u);
}
}

ll merge2(int arr[],int l,int mid,int u)
{
    int i=l;
    int j=mid;
    int k=l;
    ll ans=0;
    while((i<=mid-1) && (j<=u))
    {
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            ans+=(mid-i);
        }
    }
    while(i<=mid-1)	
    temp[k++]=arr[i++];
    while(j<=u)
    temp[k++]=arr[j++];
    for(int i=l;i<=u;i++)
    arr[i]=temp[i];
    return ans;
}
long long int mergesort2(int arr[],int l,int u)	
{
    ll ans=0;
    if(u>l){
        int mid=(l+u)/2;
        ans=mergesort2(arr,l,mid);
        ans+=mergesort2(arr,mid+1,u);
        ans+=merge2(arr,l,mid+1,u);
    }
    return ans;
}

int main()
{
	 ll i;
	fscani(&n);
	for(i=0;i<n;i++)
	{
		fscani(&a[i]);fscani(&b[i]);
	}
	mergesort(a,0,n-1);
	out(mergesort2(b,0,n-1));
	return 0;
}

