#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void sort(double a[], int n)
{
	int i,j;
	double k;
	
	for(i=n-2;i>-1;i--)
		{
			k=a[i];
			j=i+1;
			
			while(k>a[j] && j<n)
			{
				a[j-1]=a[j];
				j++;
			}
			
			a[j-1]=k;
			
			
		}
}


int main()
{
	const double pi=3.141592654;
	
	char s[20];
	
	double a[200],diff,sum=0,ans=0;
	int i,n;
	
	i=0;
	
	while(1)
	{
		
		scanf("%s",s);
		if(s[0]=='$')
			break;
		
		else
		{
		a[i]=atof(s);
		i++;
		}
	}
	
	n=i;
	sort(a,n);
	for(i=1;i<n;i++)
	{
		diff=a[i]-a[i-1];
		if(diff<0)
			diff*=-1;
		diff*=pi;
		diff/=2;
		
		ans=(sin(diff)*(cos(diff)));
		
		sum+=ans;
	}
	
	diff=(a[n-1]-a[0]);
		if(diff<0)
			diff*=-1;
		diff*=pi;
		diff/=2;
		
		ans=(sin(diff)*(cos(diff)));
		sum+=ans;
	printf("%.2f",sum);
	return (0);
}
