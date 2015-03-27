/*Name:			Word count*/
/*Description:	Read from a file, get all the words in that file and compute the number*/
/*				of times each word occurs in that file and write the results to a new file*/
/*Date:			Finished on 27/11/2013: 7:22am*/
/*Author:		Moba Melvis */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include"declarations.h"

/*THIS CODE WORKS PERFECTLY. IT USES THE BINARY TREE IMPLEMENTATION*/

int main(void)
{

	struct node dum;
	link head=&dum;
	strcpy(head->word, "n,m");
	head->left=head->right=NULL;
	
	
	

	//printf("welcome to the frequency tester\n\n");

/*----------------------------------------------------------------------*/
	if ( (read=fopen(FILE_READ, READ_MODE) ) == NULL )					//
	{																	//
		printf("Error while reading from the file\n\n"); 				//
		exit(1);														//
	}																	//
																		//
	if((rite=fopen(FILE_RITE, RITE_MODE)) == NULL )						//
	{ 																	//
		puts("file to be written to could not be opened"); 				//
		exit(0);														//
 	}																	//
/*----------------------------------------------------------------------*/


	while(!feof(read))
	{
		read_word();
		if( strcmp(buffer, "") == 0 )
			continue;
		head=find(buffer, head);
	} 

	

printf_header(rite);
freq_print(head->right, rite);
freq_print(head->left, rite);

fclose(read);
fclose(rite);
return 0;
system("cat word_frequency");
}
//end of main

