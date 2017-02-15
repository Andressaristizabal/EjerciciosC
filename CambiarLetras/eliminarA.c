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
                switch (caracter){
                	case 'a':
                		fseek( archivo, pos, SEEK_SET );
						fputc('e', archivo);
                		break;
                	case 'e':
                		fseek( archivo, pos, SEEK_SET );
						fputc('i', archivo);
                		break;
               		case 'i':
                		fseek( archivo, pos, SEEK_SET );
						fputc('o', archivo);
                		break;
               		case 'o':
                		fseek( archivo, pos, SEEK_SET );
						fputc('u', archivo);
                		break;
               		case 'u':
                		fseek( archivo, pos, SEEK_SET );
						fputc('a', archivo);
                		break;
               		case 'A':
                		fseek( archivo, pos, SEEK_SET );
						fputc('i', archivo);
                		break;
               		case 'E':
                		fseek( archivo, pos, SEEK_SET );
						fputc('O', archivo);
                		break;
               		case 'I':
                		fseek( archivo, pos, SEEK_SET );
						fputc('U', archivo);
                		break;
               		case 'O':
                		fseek( archivo, pos, SEEK_SET );
						fputc('h', archivo);
                		break;
               
                }
				pos = pos+1;
		    }	
        }
        fclose(archivo);
	return 0;
}