// 
// @author Michael Boc <email@michaelboc.com>
// @date April 23, 2017
// @filename UtilsCipher.h
// @language C (99 Dialect) 
//
// Header file to define the common utility functions common to encoding, and
// decoding of plaintext data. : 
//
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///

 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CHAR_TABLE sizeof(char)<<8
#define CIPHER_LEN 26


// Defines a datatype which will store the cipher, and the length of the secret
// keyword
//
typedef struct cipher_struct {
	// String to represent the cipher key	
	char cipherkey[CHAR_TABLE];
	// Length of the keyword
	unsigned char keylen;		

} cipher;


// Function which replaces any found duplicates with NULL characters. 
//
// @param keyword       string which the function will investigate for
//                      duplicates.
// @returns             int which represents the length of the keyword
unsigned char eliminatedups( char* keyword, char* foundchars );


// This function creates an array representing a look up table for the cipher
// text.
//
// @param cipherword    this is the password which the translation encryptr will
//                      use to encode the plain text data.
cipher* makecipher( char* keyword );


// Compare function intended to help sort the characters in the user provided
// keyword
//
// @param c1            the first object being compared by the function
// @param c2            the second object being compared by the function
int comparator( const void* c1, const void* c2 );
