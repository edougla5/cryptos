#include<stdio.h>
#include<string.h>
int j[2]={0,0};

int lowChk(char a) {

	if(a=='a')
		return 10;
	else if(a=='b')
		return 11;
	else if(a=='c')
		return 12;
	else if(a=='d')
		return 13;
	else if(a=='e')
		return 14;
	else if(a=='f')
		return 15;
	else
		return 0;
}

int* bitCkr(char a, char b, char c) {

	if(lowChk(a)) 
		a=(int)lowChk(a);
	if(lowChk(b))
		b=(int)lowChk(b);
	if(lowChk(c))
		c=(int)lowChk(c);

	if(a&0x08)
		j[0]+=32;
	if(a&0x04)
		j[0]+=16;
	if(a&0x02)
		j[0]+=8;
	if(a&0x01)
		j[0]+=4;
	if(b&0x08)
		j[0]+=2;
	if(b&0x04)
		j[0]+=1;
	if(b&0x02)
		j[1]+=32;
	if(b&0x01)
		j[1]+=16;
	if(c&0x08)
		j[1]+=8;
	if(c&0x04)
		j[1]+=4;
	if(c&0x02)
		j[1]+=2;
	if(c&0x01)
		j[1]+=1;	


	return j;
}

char base64(int x) {

	if(x<26)
		return x+65;
	else if(x<52)
		return (x+71);
	else
		return (x-4);
}
int main() {

	char htr[]="49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d",def,fed;
	int *t;
	
	for(int yes=0;yes<sizeof(htr)-3;yes+=3) {

		t=bitCkr(htr[yes],htr[yes+1],htr[yes+2]);

		def=base64(t[0]),fed=base64(t[1]);
		printf("%c%c",def,fed);

		j[0]=0,j[1]=0;
	}

	return 0;
}
