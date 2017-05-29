// 
// @author Michael Boc <email@michaelboc.com>
// @date April 23, 2017
// @filename EncodeCipher.c
// @language C (99 Dialect) 
//
// This program is an implementation of a transposition encryptor. 
//
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///
 

#include "UtilsCipher.h"


// This function will take a keyword, and plaintext data and encrypts the data 
//
// @param cipherlookup  a two dimentional array which maps the orginal ASCII
//                      value  to the encrypted ASCII values
// @param plaindata     the plaintext data which this function will encrypt
char* encrypt( cipher* cipher, char* plaintext ){
    // Creates a string which will house the encrypted text
    size_t textlen = strlen( plaintext ); 
    char* codetext = malloc( sizeof(char) * textlen );   
    // Loop to interate through and generate the secret text
    for( size_t i = 0; i < textlen; i++ ){
        codetext[i] = cipher->cipherkey[plaintext[i]]; 
    } 
 
    return codetext;
}


// This main function will have two modes associated with its operation. It will
// have a interactive mode which will encode the entered strings following a
// keyword. And the second mode of operatation where it will encode an entire
// file. 
//
// @param argc The count of arug 
int main( int argc, char* argv[] ) {
    // Create the key which will encrypt the plaintext data
    cipher* secretkey = makecipher(argv[1]);

    //Encrypts the plaintext data
    char* codetext = encrypt( secretkey, argv[2] );    

  	printf("%s", codetext); 
	 
    return EXIT_SUCCESS;
}
