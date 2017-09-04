// 
// @author Michael Boc <email@michaelboc.com>
// @date September 4, 2017
// @filename EncodeCipher.c
// @language C (99 Dialect) 
//
// This program is an implementation of a transposition encryptor. 
//
/// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// /// ///
 

#include "UtilsCipher.h"


// This is the main implementation of the program. This main function has two
// modes, the first mode will encrypt the user provided data, and output the
// cipher text. The second mode will decrypt the user provided text, and output
// the plaintext meaning of the cipher text. 
//
// @param argc The count of arguements provided by the user
// @param argv The array of c-srtings which contain the user arguements 
int main( int argc, char* argv[] ) {
	
	// Usage warning
	if( argc < 3 ){ 
		printf("usage: MainCipher [mode flag] [passphrase] [user text]\n" );
		printf("The only available flags are -e for encode or -d for decode\n\n");	
		return EXIT_SUCCESS;	
	}	
   	// Create the key which will encrypt the plaintext data
    cipher* secretkey = makecipher(argv[2], argv[1][1] == 'e');

	// Iterates through each of the provided words into the commandline
	for( unsigned char i = 3; i < argc; i++ ){
    	//Codes the word, and print it to standard out
    	char* codetext = transcribe( secretkey, argv[i] );    
		printf( "%s ", codetext );
		// Clears the heap at the completion of the program's execution		
		free( codetext ); 
	}
	printf( "\n" ); 
	free( secretkey );

	// End of program
    return EXIT_SUCCESS;
}
