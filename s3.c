#include<stdio.h>
#include<string.h>

int main() {

	int g,q;
	char jazz[]="Burning 'em, if you ain't quick and nimble";
	char hop[]="I go crazy when I hear a cymbal";
	int h,t,k;

	g=strlen(jazz);
	q=strlen(hop);



	int i=0;

	while(i<g) {
		printf("%02x",jazz[i]^'I');
		i++;
		printf("%02x",jazz[i]^'C');
		i++;
		printf("%02x",jazz[i]^'E');
		i++;
        }

	i=0;
	

	while(i<q) {
		printf("%02x",hop[i]^'I');
		i++;
		printf("%02x",hop[i]^'C');
		i++;
		printf("%02x",hop[i]^'E');
		i++;
	}

	return 0;
}
