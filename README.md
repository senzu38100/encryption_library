# RC4 Encryption Library

## Overview
This project is an implementation of the RC4 (Rivest Cipher 4) stream cipher, which is widely used in cryptographic applications. The implementation is based on the algorithm described on Wikipedia and follows the standard RC4 key scheduling and pseudo-random generation process.

### Improvements over Standard RC4
This library is based on the RC4 cipher, but I added some improvements to make it more secure.
One major issue with the RC4 algorithm is that its output is distinguishable from purely random data, which can be exploited to crack the encryption. For example, WEP (Wired Equivalent Privacy) used RC4 with small keys, making it vulnerable to cracking in seconds.

To mitigate this, I implemented a mechanism that discards the first 500 million output bytes to prevent statistical attacks. This technique enhances security even when using smaller keys.

You can learn more about these weaknesses on the [RC4 Wikipedia page](https://en.wikipedia.org/wiki/RC4).

## Features
- Implements RC4 encryption and decryption.
- Secure initialization to reduce vulnerability to key scheduling attacks.
- Simple API for initialization, encryption, and decryption.
- Includes a test program (`example.c`) to demonstrate usage.
- Lightweight and efficient implementation.

## Files
- `arcfour.h` - Header file defining the RC4 structure and function prototypes.
- `arcfour.c` - Implementation of the RC4 key scheduling and encryption/decryption functions.
- `example.c` - Demonstration program to showcase RC4 encryption and decryption.

## Compilation & Usage

### Compiling the Library and Example Program
Use `gcc` to compile the library and the example program:
gcc -c arcfour.c -o arcfour.o
ar rcs libarcfour.a arcfour.o
gcc example.c -L. -larcfour -o example

### Running the Example
Execute the compiled example:

./example


## API Usage
### 1. Initialize RC4 State

Arcfour *rc4 = rc4init((int8 *)key, key_length);

- `key` is a pointer to the encryption key.
- `key_length` is the length of the key in bytes.
- Returns a pointer to an `Arcfour` structure.

### 2. Encrypt/Decrypt Data

int8 *ciphertext = rc4encrypt(rc4, (int8 *)plaintext, text_length);
- `rc4` is the initialized Arcfour structure.
- `plaintext` is the data to be encrypted.
- `text_length` is the size of the plaintext in bytes.
- Returns a pointer to the encrypted data.

### 3. Free Memory

rc4uninit(rc4);

- Releases allocated memory for the RC4 structure.

## Example Output

Initializing encryption...done
'Shall I compare thee to a summer's day?'
 -> ef20 ac12 ... (hex representation of encrypted text)
Initializing encryption...done
    -> 'Shall I compare thee to a summer's day?'

## Notes
- RC4 encryption and decryption are identical (XOR operation).
- To decrypt, reinitialize the cipher with the same key and pass the encrypted data to `rc4encrypt()`.
- The `rc4whitewash()` function is included to reduce the risk of key leakage in memory.
- The first 500 million bytes of keystream are discarded to improve security and resist statistical attacks.


## Author
Developed by Khourchafi Hodeifa.
