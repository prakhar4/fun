#include <stdio.h>
#include <stdlib.h>

int coff[3][100], sum[100], diff[100], mul[100];


double atoF(char a[])
{
	double num;
	int sign=1, i, enable, pos;
	
	for(i=0; isspace(a[i]) && a[i]!='\0'; i++);
	
	if(a[i]=='-')
	{
		sign=-1;
		i++;
	}
	
	for(num=0; isdigit(a[i]) && a[i]!='\0'; i++)
	{
		num*=10;
		num+=a[i]-'0';
	}	
	
	if(a[i]=='.')
	{
		enable=1;
		i++;
	}
	pos=1;
	if(enable)
	{
		for(;isdigit(a[i]) && a[i]!='\0'; i++)
		{
			num*=10;
			num+=a[i]-'0';	
			pos*=10;
		}
	}
	num/=pos;
	num*=sign;
	
	return (num);
}




int atoI(char a[])
{
	double atoF(char []);	
	return ((int)atoF(a));
}



int getLen(int n)
{
	int i=0;
	while(n)
	{
		n/=10;
		i++;
	}
	if(n<0)
	return i+1;
	else
	return i;

}


int parser(char *poly, int ref)
{
	int cc, l,pp, i, j;
	char *temp=poly;
	
	while(*temp)
	{
		cc=atoI(temp);
		l=getLen(cc);

		temp+=l;
		temp++;
	
		pp=atoI(temp);
		l=getLen(pp);
		temp+=l;
		temp++;
		coff[ref][pp]=cc;
	
	}

}


showAdd()
{
	int i;
	printf("\nSUM\n");
	for(i=0;i<50;i++)
	{
		if(sum[i]==0)
			continue;
		else
			printf(" %dx%d+ ",sum[i],i);
	
	}
}

showProd()
{
	int i;
	printf("\nMULTIPLICATION\n");
	for(i=0;i<50;i++)
	{
		if(mul[i]==0)
			continue;
		else
			printf(" %dx%d+ ",mul[i],i);
	
	}
}


showSub()
{
	int i;
	printf("\nDIFFERENCE\n");
	for(i=0;i<50;i++)
	{
		if(diff[i]==0)
			continue;
		else
			printf(" %dx%d+ ",diff[i],i);
	
	}
}
add()
{
	int i;
	for(i=0;i<25;i++)
		sum[i]=coff[1][i]+coff[2][i];

	showAdd();
	printf("\b");
	return;
}

sub()
{
	int i;
	for(i=0;i<25;i++)
		diff[i]=coff[1][i]-coff[2][i];
	
	showSub();
	return;
}


prod()
{
	int i,j,k;
	
	for(i=0;i<25;i++)
		for(j=0;j<25;j++)
			mul[i+j]+=(coff[1][i]*coff[2][j]);
	showProd();
}



int main()
{
	char one[100],two[100];


	printf("\nEnter first poly :");
	scanf("%s",one);
	getchar();
	printf("\nEnter second poly :");
	scanf("%s",two);
	getchar();
	
	parser(one,1);
	parser(two,2);
	int i;
/*	for(i=0;i<5;i++)*/
/*		printf("\n%d",coff[1][i]);*/
/*	*/
/*	for(i=0;i<5;i++)*/
/*		printf("\n%d",coff[2][i]);*/
/*	*/

	add();

	sub();
	prod();
}












