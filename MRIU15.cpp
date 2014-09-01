#include<stdio.h>
#include<string.h>
char s[100000],c[100000],k=0;
void chk(long long int a)
{
	switch(a)
	{
		case 2:
		c[k++]='a';
		break;
		case 22:
		c[k++]='b';
		break;
		case 222:
		c[k++]='c';
		break;
		case 3:
		c[k++]='d';
		break;
		case 33:
		c[k++]='e';
		break;
		case 333:
		c[k++]='f';
		break;
		case 4:
		c[k++]='g';
		break;
		case 44:
		c[k++]='h';
		break;
		case 444:
		c[k++]='i';
		break;
		case 5:
		c[k++]='j';
		break;
		case 55:
		c[k++]='k';
		break;
		case 555:
		c[k++]='l';
		break;
		case 6:
		c[k++]='m';
		break;
		case 66:
		c[k++]='n';
		break;
		case 666:
		c[k++]='o';
		break;
		case 7:
		c[k++]='p';
		break;
		case 77:
		c[k++]='q';
		break;
		case 777:
		c[k++]='r';
		break;
		case 7777:
		c[k++]='s';
		break;
		case 8:
		c[k++]='t';
		break;
		case 88:
		c[k++]='u';
		break;
		case 888:
		c[k++]='v';
		break;
		case 9:
		c[k++]='w';
		break;
		case 99:
		c[k++]='x';
		break;
		case 999:
		c[k++]='y';
		break;
		case 9999:
		c[k++]='z';
		break;
		case 0:
		c[k++]=' ';
		break;
	}
}
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		k=0;
		long long int w[10000];
		scanf("%s",s);
		long long int l=strlen(s);
		s[l]='a';
		s[l+1]='b';
		s[l+2]='c';
		s[l+3]='c';
		l=l+3;
		long long int e=0;
		long long int f,i;
		for(i=0;i<l;i++)
		{
			if(s[i]>='0'&&s[i]<='9')
			{
			if(s[i]!=s[i+1])
			{
				f=s[i]-48;
				chk(f);
			}
			else if(s[i]==s[i+1]&&s[i+1]==s[i+2]&&s[i+2]==s[i+3])
			{
				f=(s[i]-48)*1000+(s[i]-48)*100+(s[i]-48)*10+s[i]-48;
				chk(f);
				i=i+3;
			}
			else if(s[i]==s[i+1]&&s[i+1]==s[i+2])
			{
				f=(s[i]-48)*100+(s[i]-48)*10+s[i]-48;
				chk(f);
				i=i+2;
			}
			else if(s[i]==s[i+1])
			{
				f=(s[i]-48)*10+s[i]-48;
				chk(f);
				i++;
			}
			}
		}
		for(i=0;i<k;i++)
		if(c[i]!=' ')
		printf("%c",c[i]-32);
		else
		printf(" ");
		printf("\n");
	}
	
	return 0;	
}
