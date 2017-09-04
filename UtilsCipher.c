// 
// @author Michael Boc <email@michaelboc.com>
// @date Semptember, 4 2017
// @filename EncodeCipher.c
// @language C (99 Dialect) 
//
// This file contains the implementation of utility functions to encode and
// decode data.  
//
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///


// The header file that this code is a implementation of 
#include "UtilsCipher.h"


// Function which replaces any found duplicates with NULL characters. This
// function will keep count of the length of the provided string and return this
// information.
//
// @param keyword       string which the function will investigate for
//                      duplicates.
//
// @param foundchars	an array which contains desribes which letters of the
// 						alphabet have been found in the keyword input string	
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
            *keyword = '\0';
            keyword++; 
        } 
    }
	return i;

}


// Compare function intended to help sort the characters in the user provided
// keyword
//
// @param c1            the first object being compared by the function
//
// @param c2            the second object being compared by the function
//
// @return				returns an int describing which number is of greater
// 						value
int comparator( const void* c1, const void* c2 ){
    
    return ( *(char*)c1 - *(char*)c2 );
}


// This function create the cipher object which contains information about the
// cipher lookup table. This lookup table will be use later to encode or decode
// the user provided data. 
//
// @param cipherword    this is the password which the translation encryptr will
//                      use to encode the plain text data.
//
// @param mode			this character representu the current mode that the
// 						function should operate in. The value 0 for ENCODE, and
// 						any other value for decode
//
// @returns				a cipher object which contains the lookup table for the
// 						cipher 
cipher* makecipher( char* keyword, char mode ){
	
	// Generates the cipher 
    cipher* newkey  = malloc( sizeof(cipher) ); 
	
    // Eliminate dups, finds the length of the keyword, and sorts the keyword
    char foundchars[CHAR_TABLE] = { 0 }; 
    newkey->keylen = eliminatedups( keyword, foundchars );  
    
    //Generates the ciphertext matrix 
   	char i = 0; 
	char ciphermatrix[CHAR_TABLE] = { '\0' };  
    for( ; i < newkey->keylen; i++ ){
		ciphermatrix[i] = keyword[i];
    }
			
	// Populates the rest of the array with the alphabet
	for( char j = 'a'; j <= 'z'; j++ ){
		if ( foundchars[j] == 0 ){
			ciphermatrix[i++] = j;	
		}	
	}

	if( mode != ENCODE ){ 
		// Iterate through each of the columns in the matrix
		i = 0; 
		for( char j = 0; j < newkey->keylen; j++ ){
			// While loop to collect the entire column 
			for( char row = 0; ; row++ ){
				char charptr = ciphermatrix[ (row*newkey->keylen) + j ]; 
				if( charptr != '\0' ){
					newkey->cipherkey['a' + i++] = charptr;	
				}
				else{
					break;
				}	
			} 
		}
   	}
	else{
		// Iterate through each of the columns in the matrix
		i = 0; 
		for( char j = 0; j < newkey->keylen; j++ ){
			// While loop to collect the entire column 
			for( char row = 0; ; row++ ){
				char charptr = ciphermatrix[ (row*newkey->keylen) + j ]; 
				if( charptr != '\0' ){
					newkey->cipherkey[charptr] = ('a' + i++);	
				}
				else{
					break;
				}	
			} 
		}
	} 
	
	return newkey;

}


// This function will take a keyword, and plaintext data and encrypts the data 
//
// @param cipherlookup  a two dimentional array which maps the orginal ASCII
//                      value  to the encrypted ASCII values
//
// @param plaindata     the plaintext data which this function will encrypt
//
// @returns				a string which represents either the ciphertext or plain
// 						text depending on the mode
char* transcribe( cipher* cipher, char* plaintext ){
    
	// Creates a string which will house the encrypted text
    size_t textlen = strlen( plaintext ); 
    char* codetext = malloc( sizeof(char) * (textlen+1) );   
    // Loop to interate through and generate the secret text
    for( size_t i = 0; i < textlen; i++ ){
		// Sanitize capitial letters 		
		if( *plaintext <= 'Z' ){
            *plaintext = tolower(*plaintext);
        }
		// Creates the output
        codetext[i] = cipher->cipherkey[*plaintext++]; 
    } 
 
    return codetext;
}
