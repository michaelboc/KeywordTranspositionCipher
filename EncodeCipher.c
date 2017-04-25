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


// Function which replaces any found duplicates with NULL characters. 
//
// @param keyword         string which the function will investigate for
//                      duplicates.
char* eliminatedups( char* keyword ){
    // Iterates through the string until a NULL character is found, 
    unsigned char i = 0;
    while( keyword[i] != '\0' ){
    // If     

    }
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
    // Sorts the keyword 
    qsort( keyword, strlen(keyword), sizeof(char), comparator); 

    return NULL;
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
    makecipher(argv[1]);
    
    printf("%s", argv[1]);    
    return EXIT_SUCCESS;
}
