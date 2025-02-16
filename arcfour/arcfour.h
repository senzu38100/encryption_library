/* arcfour.h */

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

// define a constant for a memory scrub time multiplier
#define MS					500

//macros for function attributes and aliases
#define export				__attribute__((visibility("default")))
#define rc4decrypt(x,y,z)		rc4encrypt(x,y,z) // since RC4 decryption is the same as encryption
#define rc4uninit(x)		free(x) //macro to deallocate memory
									
// Function to introduce artificial delay (whitewashing memory to mitigate key leaks
#define rc4whitewash(x,y)		for(x=0; x<(MS*1000000); x++) \
									(volatile int8)rc4byte(y);

//typedefs for readability
typedef struct s_arcfour Arcfour;
typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

//struct to hold the rc4 state
struct s_arcfour {
	int16 i, j, k;
	int8 s[256];

};


//function prototypes
export Arcfour *rc4init(int8*, int16);
int8 rc4byte(Arcfour*);
export int8 *rc4encrypt(Arcfour*, int8*, int16);

