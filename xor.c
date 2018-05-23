#include<stdio.h>
#include<string.h>
int j[2]={0,0};

int char_num(char a) {
	
	if(a=='1')
		return 1;
	else if(a=='2')
		return 2;
	else if(a=='3')
		return 3;
	else if(a=='4')
		return 4;
	else if(a=='5')
		return 5;
	else if(a=='6')
		return 6;
	else if(a=='7')
		return 7;
	else if(a=='8')
		return 8;
	else if(a=='9')
		return 9;
	else if(a=='a')
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

char back_hexr(int a) {

	if(a==10)
		return('a');
	else if(a==11)
		return('b');
	else if(a==12)
		return('c');
	else if(a==13)
		return('d');
	else if(a==14)
		return('e');
	else if(a==15)
		return('f');
	else
		return 0;
}

int main() {

	char htr[]="1c0111001f010100061a024b53535009181c";
	char str[]="686974207468652062756c6c277320657965";
	char ans[]="746865206b696420646f6e277420706c6179";
	int t,j,tj;
	for(int i=0;i<strlen(htr);i++) {

		t=char_num(htr[i]);
		j=char_num(str[i]);
		
		tj=t^j;

		if(back_hexr(tj))
			printf("%c",back_hexr(tj));
		else
			printf("%d",tj);
	}
	return 0;
}
