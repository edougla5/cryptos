#include<stdio.h>
#include<string.h>
void main() {
	unsigned char h[]="Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
	int i=0;
	int g=strlen(h);

	while(i<g) {
			printf("%02x",h[i]^'I');
		i++;
		if(i==g)
			break;
			printf("%02x",h[i]^'C');
		i++;
		if(i==g)
			break;
                        printf("%02x",h[i]^'E');
		i++;
		if(i==g)
			break;
	}
}
