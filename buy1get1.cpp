#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int t,x,i,j,k,len,l,c=0,p=0;  
	scanf("%d",&t);
	char *s[1000000],*z;
	z=(char*)malloc(201);
	for(i=0;i<t;i++)
	s[i]=(char*)malloc(201);
	for(i=0;i<t;i++) 
	scanf("%s",s[i]);
	for(i=0,l=strlen(s[i]);i<t;i++)
	{
	for(j=97;j<=122;j++)
	{
	strcpy(z,s[i]);
	for(k=0,len=strlen(z);k<len;k++)
	{
		if(z[k]==(char)j)
		c++;
	}
	if(c%2==0)
	p=p+c/2;
	else
	p=p+(c/2)+1;
	
	c=0;
	}
	c=0;
	for(x=65;x<=90;x++)
	{
	for(k=0,len=strlen(z);k<len;k++)
	{
		if(z[k]==(char)x)
		c++;
	}
	if(c%2==0)
	p=p+c/2;
	else
	p=p+(c/2)+1;
	
	c=0;
	}
	z=NULL;
	z=(char*)malloc(201);
	printf("%d\n",p);
	p=0;
	}
	return 0;
}
