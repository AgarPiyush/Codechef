#include<stdio.h>
#define getcx getchar_unlocked

typedef int lll;
lll ini[100050],fin[100050],pri[100050];
int temp[100050],temp2[100050],temp3[100050];
void merge( int pri[],int l,int mid,int u)
{
	int ac=l,bc=mid+1,cc=l,i;
	while(ac<=mid&&bc<=u)
	{
	if(pri[ac]<pri[bc])
	{
	temp[cc]=fin[ac];
	temp2[cc]=ini[ac];
	temp3[cc]=pri[ac];
	cc++;
	ac++;
	}
	else
	{
	temp[cc]=fin[bc];
	temp2[cc]=ini[bc];
	temp3[cc]=pri[bc];
	bc++;
	cc++;
	}
	}
	while(ac<=mid)
	{
	temp[cc]=fin[ac];
	temp2[cc]=ini[ac];
	temp3[cc]=pri[ac];
	cc++;
	ac++;
	}
while(bc<=u)
{
temp[cc]=fin[bc];
temp2[cc]=ini[bc];
temp3[cc]=pri[bc];
cc++;bc++;
}
for(i=l;i<cc;i++)
{
fin[i]=temp[i];
ini[i]=temp2[i];
pri[i]=temp3[i];
}
}
void merge2(int fin[],int l,int mid,int u)
{
	int ac=l,bc=mid+1,cc=l,i;
	while(ac<=mid&&bc<=u)
	{
	if(fin[ac]<fin[bc])
	{
	temp[cc]=fin[ac];
	temp2[cc]=ini[ac];
	cc++;
	ac++;
	}
	else
	{
	temp[cc]=fin[bc];
	temp2[cc]=ini[bc];
	bc++;
	cc++;
	}
	}
	while(ac<=mid)
	{
	temp[cc]=fin[ac];
	temp2[cc]=ini[ac];
	cc++;
	ac++;
	}
while(bc<=u)
{
temp[cc]=fin[bc];
temp2[cc]=ini[bc];
cc++;bc++;
}
	for(i=l;i<cc;i++)
	{
	fin[i]=temp[i];
	ini[i]=temp2[i];
	}
}


void mergesort(int pri[],int l,int u)
{
 int mid=(l+u)/2;
if(l!=u)
{
mergesort(pri,l,mid);
mergesort(pri,mid+1,u);
merge(pri,l,mid,u);
}
}



void mergesort2(int fin[],int l, int u)
{
 int mid=(l+u)/2;
if(l!=u)
{
mergesort2(fin,l,mid);
mergesort2(fin,mid+1,u);
merge2(fin,l,mid,u);
}
}

inline void fscan(int *a ) 
{
long long int n=0; int ch = getcx(); int sign = 1;
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



lll cus,comp;
int main()
{
	int t,i,j,k,l;
	//scanf("%lld",&t);
	fscan(&t);
		
	while(t--)
	{
		int sum=0;
		//scanf("%lld %lld",&cus,&comp);
		fscan(&cus);
		fscan(&comp);
		
		if(cus==0) printf("0\n");
		else
		{
		
		//printf("%lld %lld",cus,comp);
		for(i=0;i<cus;i++)
		{
			fscan(&ini[i]);
			fscan(&fin[i]);
			fscan(&pri[i]);
		//	scanf("%lld %lld %lld",&ini[i],&fin[i],&pri[i]);
		//	printf("%lld\n",i);
		}
		mergesort(pri,0,cus-1);
		int l=0,u=0;
		for(i=0;i<cus-1;i++)
		{
			if(pri[i]!=pri[i+1])
			{
				mergesort2(fin,l,u);
				l=i+1;
			}
			u=i+1;
		}
		mergesort2(fin,l,u);
		sum=1,j=0;
		for(i=1;i<cus;i++)
		{
			if(pri[i]!=pri[i-1])
			{
				sum++;
				j=i;
			}
			else
			{
				if(ini[i]>=fin[j])
				{
					sum++;
					j=i;
				}
			}
		}
		printf("%d\n",sum);
	}
}	
	return 0;
}
