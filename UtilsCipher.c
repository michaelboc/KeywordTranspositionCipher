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

 
#include "UtilsCipher.h"


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
	
	// Generates the cipher 
    cipher* newkey  = malloc( sizeof(cipher) ); 
	
    // Eliminate dups, finds the length of the keyword, and sorts the keyword
    char foundchars[CHAR_TABLE] = { 0 }; 
    newkey->keylen = eliminatedups( keyword, foundchars );  
    
    //Generates the ciphertext matrix 
	unsigned char i = 0;  
    char ciphermatrix[newkey->keylen];  
    for( ; i < newkey->keylen; i++ ){
		ciphermatrix[i] = keyword[i];
    }
    	
	// Populates the rest of the array with the alphabet
	for( char j = 'a'; j <= 'z'; j++ ){
		if ( foundchars[j] == 0 ){
			ciphermatrix[i++] = j;	
		}	
	}
    
    // Iterate through each of the columns in the matrix
    i = 0; 
    for( char j = 0; i < newkey->keylen; j++ ){
        // While loop to collect the entire column 
        for( char row = 0; ; row++ ){
            char charptr = ciphermatrix[ (row*newkey->keylen) + j ]; 
            if( charptr != '\0' ){
                newkey->cipherkey[i++] = charptr;
            }
            else{
                break;
            } 
        } 
    }  
    
    return newkey;

} 
