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
	//Arcfour *rc4;
	int16 skey, stext; //size key and text
	char *key, *from, *encrypted, *decrypted;

	key=from=encrypted=decrypted=0;
	from=key;

	skey=stext=0;
	
	key = "tomatoes"; 
	skey = strlen(key);
	from = "Shall i compare thee to a summer's day?";
	stext = strlen(from);

	printf("Initializing encryption...");
	//rc4 = rc4init(key, skey);
	printf("done\n");

	printf("'%s'\n ->", from);
	//encrypted = rc4encrypt(from, stext);
	printbin((int8 *)key,skey);
	

	return 0;
}
