#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
	long long int t,i,j,k,l;
	char a,b;
	scanf("%lld",&t);
	int f=0;
	char r;
	while(t--)
	{
		if(f==0)
		scanf("%c",&r);
		f++;
		int flag1=0,flag2=0;
		gets(s);
		long long int l=strlen(s);
		if(l!=3)
		printf("INVALID\n");
		else
		{
		a=s[0];
		b=s[2];
	//	printf("%c %c\n",a,b);
		if(a=='A'||a=='Q'||a=='J'||a=='K'||(a>='2'&&a<='9'))
		{
		flag1=0;
		}	
		else
		{
		flag1=1;
		}
		if(b=='A'||b=='Q'||b=='J'||b=='K'||(b>='2'&&b<='9'))
		flag2=0;
		else
		flag2=1;
		if(flag1==1||flag2==1)
		printf("INVALID\n");
		else
		{
			int sum=0;
			if(a=='A'||b=='A')
			{
			printf("HIT\n");	
			}
			else
			{
				if(a=='Q'||a=='J'||a=='K')
				sum=sum+10;
				if(a>='2'&&a<='9')
				sum=sum+a-48;
				if(b=='Q'||b=='J'||b=='K')
				sum=sum+10;
				if(b>='2'&&b<='9')
				sum=sum+b-48;
				if(sum<=11)
				printf("HIT\n");
				else
				printf("STAND\n");
			}
		}
		}
	}
	return 0;
	
}
