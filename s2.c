#include<stdio.h>
#include<string.h>

int score(int yee) {
	if(yee>64 && yee<91)
		return 1;
	else if(yee>97 && yee<123)
		return 1;
	else if(yee==32)
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
	FILE *f;
	f=fopen("file.c","r");
	
	char word[60],h,words[30],wordz[30];
	int x=0,charTrack,bigChar,ltr,spider=0,bigLtr,super=0;
	
	while(fgets(word,61,f)) {
		int j=0;
	for(int t=0;t<60;t+=2) {
		x=bitCkr(word[t],word[t+1]);
		words[j]=x;
		j++;
	}
	bigChar=0;
	for(int q=0;q<127;q++) {
		charTrack=0;
		
		for(int t=0;t<30;t++) {
			h=words[t]^q;
			if(score(h))
				charTrack++;

		}
		if(charTrack>bigChar) {
			bigChar=charTrack;
			ltr=q;
		}
	}
	
	//when this loop finishes, bigChar will == largest # of alphabetic chars found in a single string
	//and ltr will == the char that matches the largest alpha count
	if(bigChar>spider) {
		spider=bigChar;
		bigLtr=ltr;
		strcpy(wordz,words);
	}
	//if bigChar>spider, it is set to the largest char count found
	//also bigLtr is set to the character that matches with the largest alpha count
	}
	for(int y=0;y<30;y++) {
		h=wordz[y]^bigLtr;
		printf("%c",h);
	}
	
	
	fclose(f);

	return 0;
}
