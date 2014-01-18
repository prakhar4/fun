#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
#define MAX(A,B) (((A)>(B))? (A) : (B))

int stk[2][25];
int top[2];


int push(int info, int index)
{
	stk[index][top[index]]=info;
	top[index]+=1;
	return info;
}

int pop(int index)
{
	int temp=0;
	if(top[index]==0)
		return -1;
	else{
		temp=stk[index][top[index]-1];
		top[index]-=1;
		return temp;
	}
}

int present(char *str, int c)
{
  int i,j,len=strlen(str);
  
  for(i=0;i<len;i++)
  	if(str[i]==c)
		return 1;
  
  if(i=len)
  	return -1;
}

char *removez(char *this, char *from)
{
	int len=strlen(from);
	int i,j=0,k;
	char new[20];
	
	for(i=0;i<len;i++){
		if(present(this,from[i])==1)
			continue;
		else
			new[j++]=from[i];
	}
	new[j]='\0';
	
	strcpy(from,new);
	return from;
}  
 
char * lcs(const char *a,const char * b) {
    int lena = strlen(a)+1;
    int lenb = strlen(b)+1;
 
    int bufrlen = 40;
    char bufr[40], *result;
 
    int i,j;
    const char *x, *y;
    int *la = calloc(lena*lenb, sizeof( int));
    int  **lengths = malloc( lena*sizeof( int*));
    for (i=0; i<lena; i++) lengths[i] = la + i*lenb;
 
    for (i=0,x=a; *x; i++, x++) {
        for (j=0,y=b; *y; j++,y++ ) {
            if (*x == *y) {
               lengths[i+1][j+1] = lengths[i][j] +1;
            }
            else {
               int ml = MAX(lengths[i+1][j], lengths[i][j+1]);
               lengths[i+1][j+1] = ml;
            }
        }
    }
 
    result = bufr+bufrlen;
    *--result = '\0';
    i = lena-1; j = lenb-1;
    while ( (i>0) && (j>0) ) {
        if (lengths[i][j] == lengths[i-1][j])  i -= 1;
        else if (lengths[i][j] == lengths[i][j-1]) j-= 1;
        else {
//			assert( a[i-1] == b[j-1]);
            *--result = a[i-1];
            i-=1; j-=1;
        }
    }
    free(la); free(lengths);
    return strdup(result);
}


int main()
{
	char *asd;
	char temp[20];
/*	asd=lcs("otoman", "oty123123m3245a4356n");*/
/*    printf("%s\n",asd);*/
	
	char init[10], fin[10];
	char init1[10], fin1[10];
	int i,j,k,l;
	int len=0;
	
	printf("\nEnter the initial state of stack:(bottom-top) ");
	scanf("%s",init);
	getchar();
	printf("\nEnter the final state of stack:(bottom-top) ");
	scanf("%s",fin);
	
	printf("\t%s\n%s",init,fin);
	asd=lcs(init,fin);
    printf("\nTHE LCS IS :%s\n",asd);
	strcpy(temp,asd);
	
	strcpy(init1,init);
	strcpy(fin1,fin);
	
	removez(temp,init1);
	removez(temp,fin1);
	
	printf("\nTEmp is %s ",temp);


	printf("\t%s\n%s",init1,fin1);
	asd=lcs(init1,fin1);
    printf("\nTHE  new LCS IS :%s\n",asd);
    return 0;
}
