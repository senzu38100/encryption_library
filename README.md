--------------------- Coding my own encryption library ---------------------

	This library is based on the RC4 cypher but i added some improvements to 
make it a little bit more secure.
The issue with the RC4 library is that the output of the encryption is 
distinguishable when compared to purely random data. So that could be used to 
backtrack and crack the encryption (for example, the WEP used this encryption
with small keys and people were able to crack it within seconds.
So we will create a mechanism which will disregard the first 500millions
output bytes which should stop the cracking techniques.
You can learn about this on the RC4 wikipedia page
Arcfour is still secure if you use a big enough key, but i'll try to
make it safe even with small keys.


To code this library, i mainly used the rc4 library code and it's
wikipedia page
