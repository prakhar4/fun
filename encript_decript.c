/*
 	to encrip and decrip data as per input file using input XOR
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	
	char *cipher=argv[2];
	int cip=atoi(cipher);
	int ip;
	
	FILE *fp;
	FILE *wfp;
	char *newss="new";
	fp=fopen(argv[1],"r");
	wfp=fopen(newss,"w");
	
	while((ip=getc(fp))!=EOF)
		putc(ip^=cip,wfp);
	
	fclose(fp);
	fclose(wfp);
	printf("\n");
}
