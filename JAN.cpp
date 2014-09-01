#include<stdio.h>
#include<limits.h>
#include<string.h>
typedef unsigned long long int ll;
ll a[1000000];
char s[1000000];
ll mul(ll a1,ll b1,ll c1)
{
	ll pro=0;
	b1=b1%c1;
	while(a1)
	{
		if(a1&1)
		{
			pro=pro+=b1;
			if(pro>c1) pro=pro-c1;
		}
		a1>>=1;
		b1<<=1;
		if(b1>c1)
		b1=b1-c1;
	}
	return pro;
	
}

	#define getcx getchar_unlocked
	inline void fscan(ll *a ) 
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
	
int main()
{
	ll i,j,k,l,m,n,t,x,y,z,temp1,temp2,end,count,min,revcount;
	fscan(&t);
//	scanf("%llu",&t);
	while(t--)
	{
//		scanf("%llu",&n);
	
		fscan(&n);
		for(i=0;i<n;i++)
		fscan(&a[i]);
//		scanf("%llu",&a[i]);
	
	//	fscan(&a[i]);
		fscan(&x);fscan(&y);fscan(&z);	
	/*scanf("%llu",&x);
	scanf("%llu",&y);
	scanf("%llu",&z);
		*/
		scanf("%s",s);
		l=strlen(s);
		end=n-1,count=n,revcount=0;
		i=0;
		ll sum=0,mulc=1;
		
		for(count=0;count<n;count++)
		{
			if(s[count]=='A')
			{
				sum=(sum+x)%z;
				a[i]=mul(a[i],mulc,z);
				printf("%llu ",((a[i]+sum)%z));
				if(((revcount&1))==1) i--;
				else  i++;
			}
			else if(s[count]=='M')
			{
					sum=mul(sum,y,z);
					mulc=mul(mulc,y,z);
					a[i]=mul(a[i],mulc,z);
					printf("%llu ",((a[i])+sum)%z);
					if(((revcount&1))==1) i--;
					else  i++;
			}
			else
			{
			a[end]=mul(a[end],mulc,z);
			printf("%llu ",((a[end]+sum)%z));
			if(end>=i)
			temp1=end-1;
			else
			temp1=e1nd+1;

			temp2=temp1;
			temp1=i;
			i=temp2;
			
			end=temp1;
			revcount++;
		
			}
		}

	printf("\n");		
	}
	return 0;
}
