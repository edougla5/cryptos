#include<stdio.h>
#include<string.h>

int score(int yee) {
	if(yee>64 && yee<91)
		return 1;
	else if(yee>97 && yee<123)
		return 1;
	else
		return 0;
}

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

int bitCkr(char a, char b) {

	int j=0;

	if(lowChk(a)) 
		a=(int)lowChk(a);
	if(lowChk(b))
		b=(int)lowChk(b);

	if(a&0x08)
		j+=128;
	if(a&0x04)
		j+=64;
	if(a&0x02)
		j+=32;
	if(a&0x01)
		j+=16;
	if(b&0x08)
		j+=8;
	if(b&0x04)
		j+=4;
	if(b&0x02)
		j+=2;
	if(b&0x01)
		j+=1;	

	return j;
}

int main() {
	char word[]="1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	int teet,jebs=0,sis=0,scorch;
	
	for(int a=0;a<128;a++) {
		for(int b=0;b<strlen(word);b+=2) {
			teet=bitCkr(word[b],word[b+1]);
			teet=teet^a;
			if(score(teet))
				sis++;
		}
		if(sis>jebs) {
			jebs=sis;
			scorch=a;
		}
		sis=0;
	}

	for(int c=0;c<strlen(word);c+=2) {
		teet=bitCkr(word[c],word[c+1]);
		teet=teet^scorch;
		printf("%c",teet);
	}
	puts(" ");
}
