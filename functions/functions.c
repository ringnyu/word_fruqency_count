#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"declarations.h"

/*============================================================================================*/
/*=====================READ   READ   READ   READ   READ  READ=================================*/
/*============================================================================================*/

void read_word()
{
	char c;
	register int  i=0;
	while( isalpha(   (int)(c=getc(read))  ) )
	{
		*(buffer+i)=c;
		i++;
	}
	*(buffer+i)='\0';

}


/*============================================================================================*/
/*=====================TEST  TEST  TEST  TEST  TEST  TEST  TEST===============================*/
/*============================================================================================*/



link find(char *buffer, link h)
{	
	if(h == NULL)
	{
		h=malloc(sizeof*h);
		h->word=(char *)malloc(sizeof(h->word)* strlen(buffer) + 1);
		strcpy(h->word, buffer);
		h->freq=1;
		h->left=h->right=NULL;
		return h;
	}
	
	

	if (strcasecmp( buffer, h->word) == 0 )
		h->freq+=1;	
	

	else
	{
		if (strcasecmp( buffer, h->word) > 0 )
			h->right=find(buffer, h->right);	
		else
			h->left=find(buffer, h->left); 
	}

return h;	
}





/*============================================================================================*/
/*=============FILE  FILE  FILE  FILE  FILE  FILE  FILE  FILE  FILE ==========================*/
/*============================================================================================*/

void printf_header(FILE *rite)
{
	fprintf(rite, "\t_-_ | FILE READ FREQUENCY WRITE ANALYSIS REPORT | _-_\n\n" );
	fprintf(rite, "\t--------------------------------------------------\n"  );
	fprintf(rite, "\t  | %-20s\t|\t%6s |\n", "Word_from_file",  "Frequency" 		);
	fprintf(rite, "\t--------------------------------------------------\n"  );
}

void freq_print(link head, FILE *rite)
{
	if(head == NULL )
		return;
	
	
    fprintf(rite, "\t  | %-20s\t|\t%6ld    |\n", head->word, head->freq			);
	
	

	freq_print(head->right, rite);
	freq_print(head->left, rite);
	
}

void printf_footer(FILE *rite)
{
	fprintf(rite, "\t------------------------------------------------------\n"	);
}

