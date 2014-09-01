//Author: Piyush Agarwal, MNNIT Allahabad
#include<stdio.h>
#define ll long int
using namespace std;
#define getcx getchar_unlocked

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

ll k,b,m,n,x,t;
int main()
{
	finp(&t);
	while(t--)
	{
		finp(&x);
		finp(&b);
		b=-b;
		if(b<0)
		{
			k=-b;
			if(k%2==0)
			{
				if(x==0)
					printf("YES\n");
				else
				if(x>0&&(x<k)||(x>0&&x>k&&(x%2==1)))
					printf("YES\n");
				else
				if((x<0&&x>=b)||(x<0&&x<b&&((-x)%2==0)))
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
			{
				k=-b;
				if(x%2==1&&x>=k)
					printf("YES\n");
				else if(x<b&&((-x)%2==0))
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
		else if(b>0)
		{
			if(b%2==0)
			{
				if(x<=b&&x>=(-b))	
					printf("YES\n");
				else if(x<b&&((-x)%2==0))
					printf("YES\n");
				else if(x>b&&(x%2==1))
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
			{
				if(x>b&&(x%2==1))
					printf("YES\n");
				else if(x<(-b)&&((-x)%2==0))
					printf("YES\n");
				else printf("NO\n");
			}
		}	
		else
		{
			if(x==0)
				printf("YES\n");
			else
				if(x>0&&(x%2==1))
					printf("YES\n");
			else
				if(x<0&&(((-x)%2)==0))
					printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}

