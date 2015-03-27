													/*Some macro that are going to be used in the program*/
#define FILE_READ "complete-shakespeare"			//file to read from
#define FILE_RITE "word_frequency"					//file to write to
#define READ_MODE "r"								//this is the mode to open the file to be read from
#define RITE_MODE "w+"								//the mode to be used to open the file to write to
#define N 40 										//n is the size of the buffer

													//the structure definitionto contain the words at runtime

typedef struct node *link;
struct node
{
	char *word;
	long freq;
	link left, right;
};



										//function definition
/*=============================FUNCTION=====================================*/
/*============================DEFINITIONS===================================*/
void read_word();						//read the word from the file
link find(char *, link);				//goes via the tree looking for the occurence of the char * variable
void printf_header(FILE *);				//prints the heading thats going to appear on the top of the file written to.
void freq_print(link, FILE *);			//prints the info of that node to the file
void printf_footer(FILE *);				//prints the footnote on the file

/*==========================================================================*/
/*==========================================================================*/

char buffer[N];
FILE *read, *rite;
