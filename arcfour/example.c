/* example.c */
// temporary file
#include "arcfour.h"

#define F fflush(stdout)

int main(void);

// ef20 ac12

void printbin(const int8 *input, const int16 size) {
	int16 i;
	const int8 *p;

	assert(size > 0);

	for(i = size, p=input; i; i--, p++) {
		if (! (i % 2)) 
			printf(" ");
		printf("%.02x", *p);
	}
	printf("\n");
	return;
}

int main() {
	Arcfour *rc4;
	int16 skey, stext; //size key and text
	char *key, *from;
	int8 *encrypted, *decrypted;

	
	key = "tomatoes"; 
	skey = strlen(key);
	from = "Shall i compare thee to a summer's day?";
	stext = strlen(from);

	printf("Initializing encryption...");
	rc4 = rc4init((int8 *)key, skey);
	printf("done\n");

	printf("'%s'\n ->", from);
	encrypted = rc4encrypt(rc4, (int8 *)from, stext);
	printbin(encrypted, stext);
	
	rc4uninit(rc4);
	printf("Initializing encryption..."); F;
	rc4 = rc4init((int8*)key,skey);
	printf("done\n");

	decrypted = rc4decrypt(rc4,encrypted, stext);
	printf("    ->'%s'\n", decrypted);
	rc4uninit(rc4);
	

	return 0;
}
