//Reverse a file

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp = fopen("one.txt","r+");
	fseek(fp,0,SEEK_END);
	long len = ftell(fp);
	int i;
	char temp1, temp2;
	for(i=0; i<len/2; i++){
		fseek(fp,i,SEEK_SET);
		temp1 = getc(fp);
		fseek(fp,(-i-1),SEEK_END);
		temp2 = getc(fp);
		fseek(fp,-1,SEEK_CUR);
		putc(temp1, fp);
		fseek(fp,i,SEEK_SET);
		putc(temp2, fp);
	}
	fclose(fp);
	return; 
}

