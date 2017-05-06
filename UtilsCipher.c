// 
// @author Michael Boc <email@michaelboc.com>
// @date April 23, 2017
// @filename EncodeCipher.c
// @language C (99 Dialect) 
//
// This file contains the implementation of utility functions to encode and
// decode data.  
//
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///

 
#include <UtilsCipher.h>


// Function which replaces any found duplicates with NULL characters. 
//
// @param keyword       string which the function will investigate for
//                      duplicates.
// @returns             int which represents the length of the keyword
unsigned char eliminatedups( char* keyword, char* foundchars ){
    
	// Iterates through the string until a NULL character is found, 
    unsigned char i = 0;
    while( *keyword != '\0' ){
        // Santizes capital letters
        if( *keyword <= 'Z' ){
            *keyword = tolower(keyword[i]);
        }
        // First time encountering a word
        if( foundchars[*keyword] == 0 ){
            foundchars[*keyword] = 1;
            keyword++, i++; 
        }  
        else {
            *keyword = NULL;
            keyword++; 
        } 
    }
	return i;

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
cipher* makecipher( char* keyword ){
   
	// Generates the cipher below 
    cipher* newkey  = malloc( sizeof(cipher) ); 
	
	// Eliminate dups, finds the length of the keyword, and sorts the keyword
    char foundchars[CHAR_TABLE] = { 0 }; 
    newkey->key_len = eliminatedups( keyword, foundchars );  
    
	unsigned char i = 0;   
    for( ; i < keylen; i++ ){
		newkey->cipher_key[i] = keyword[i];
    }
	
	// Populates the rest of the array with the alphabet
	for( unsigned char j = 'a'; j <= 'z'; j++ ){
		if ( foundchars[j] == 0 ){
			new->cipher_key[i++] = j;	
		}	
	}	
	return cipher_key;    

} 
