#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *archivo;
	char caracter;
	int pos = 0;
	archivo = fopen("texto.txt","r+b");
	
	if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
    else
        {
            
            while (feof(archivo) == 0)
		    {	
                caracter =	 fgetc(archivo);
				if (caracter == 'a' || caracter == 'A')
				{
		   			fseek( archivo, pos, SEEK_SET );
					fputc(' ', archivo);
				}
		    	pos = pos+1;
		    }	
        }
        fclose(archivo);
	return 0;
}