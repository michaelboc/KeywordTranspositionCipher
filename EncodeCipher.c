// 
// @author Michael Boc <email@michaelboc.com>
// @date April 23, 2017
// @filename EncodeCipher.c
// @language C (99 Dialect) 
//
// This program is an implementation of a transposition encryptor. 
//
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///

 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHAR_TABLE sizeof(char)<<3
#define CIPHER_LEN 26


// Function which replaces any found duplicates with NULL characters. 
//
// @param keyword       string which the function will investigate for
//                      duplicates.
// @returns             int which represents the length of the keyword
unsigned char eliminatedups( char* keyword, char* foundchars ){
    
	// Iterates through the string until a NULL character is found, 
    unsigned char i = 0;
    while( keyword[i] != '\0' ){
        // Santizes capital letters
        if( keyword[i] > 'Z' ){
            keyword[i] = tolower(keyword[i]);
        }
        // First time encountering a word
        if( foundchars[keyword[i]] == 0 ){
            foundchars[keyword[i++]] = 1;
        }  
        else {
            keyword[i++] = NULL;
        } 
    }
    
	return ++i;
}


// Compare function intended to help sort the characters in the user provided
// keyword
//
// @param c1            the first object being compared by the function
// @param c2            the second object being compared by the function
int comparator( const void* c1, const void* c2 ){
    
    return ( *(char*)c1 - *(char*)c2 );
}


// This function creates an array representing a look up table for the cipher
// text.
//
// @param cipherword    this is the password which the translation encryptr will
//                      use to encode the plain text data.
char* makecipher( char* keyword ){
   
	// Eliminate dups, and find the length of the keyword
    char foundchars[CHAR_TABLE] = { 0 }; 
    unsigned char keylen = eliminatedups( keyword, foundchars );  
    // Sorts the keyword 
    qsort( keyword, strlen(keyword), sizeof(char), comparator); 
   
	// Generates the cipher below 
    char* cipher = malloc( sizeof(char) * CIPHER_LEN); 
    for( unsigned char i = 0; i < keylen; i++ ){
		cipher[i] = keyword[i];
    }
	
	// Populates the rest of the array with the alphabet
	for( unsigned char j = 'a'; j <= 'z'; j++ ){
		if ( foundchars[j] == 0 ){
			cipher[j] = j;	
		}	
	}	
	
	return cipher;    
} 


// This function will take a keyword, and plaintext data and encrypts the data 
//
// @param cipherlookup  a two dimentional array which maps the orginal ASCII
//                      value  to the encrypted ASCII values
// @param plaindata     the plaintext data which this function will encrypt
char* encryptor( char** cipherlookup, char* plaindata ){
    
    return NULL;
}


// This main function will have two modes associated with its operation. It will
// have a interactive mode which will encode the entered strings following a
// keyword. And the second mode of operatation where it will encode an entire
// file. 
//
// @param argc The count of arug 
int main( int argc, char* argv[] ) {
    char* test = makecipher(argv[1]);
  	printf("%s", test); 
	 
    return EXIT_SUCCESS;
}
