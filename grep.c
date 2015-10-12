/*
This is grep command
*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	
	if(argc != 3){
		
		printf("USAGE: Use only two arguments, the text you want to search followed by the filename in which the text is to be searched\n");
		return 0;
	}

	FILE *file = fopen(argv[2], "r");
	        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else 
        {
            int i, j, x, len = strlen(argv[2]);
	    char **lines = (char **)malloc(sizeof(char *));
            /* read one character at a time from file, stopping at EOF, which
               indicates the end of the file.  Note that the idiom of "assign
               to a variable, check the value" used below works because
               the assignment statement evaluates to the value assigned. */
	
		for(i=0;x != EOF;i++)
		{
			
			*(lines+i) = (char *)malloc(sizeof(char));
			for( j=0;(x=fgetc(file)) != EOF;j++)
			{
				
				*(*(lines+i)+j) = x;
				*(lines+i) = (char *)realloc( *(lines+i) , (j+2) * sizeof(char));
				
				if(x == '\n')
				{	
					lines  = (char **)realloc( lines , (i+2) * sizeof(char *));
					break; 
				}
			}
		}
		
		
		for(i=0; i < len;i++)
		{
			if( strstr(*(lines+i), argv[1]) )
			{
				printf("%s", lines[i]);
			}
		}

		
            fclose( file );
        }
  

	return 0;
}


