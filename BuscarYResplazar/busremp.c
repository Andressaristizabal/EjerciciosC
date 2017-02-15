#include <stdio.h>
#include <stdlib.h>

char cadena[100];
char cadena2[100];
FILE *archivo;
int inicio;
int final;
int cont;
int cont2;
int cont3;
int cont4;
char caracter;
void cambios();
void limpiar();
int revisar(int pos);
int addArray(int i,int *arry);
void reestrutura();
int inicioA[100]={0};
int finalA[100]={0};

int contador=0;
int indiceVec=0;

int main()
{
	int pos = 0;
	archivo = fopen("texto.txt","r+b");

//P1
	printf ("Introduzca una cadena: ");
	fgets (cadena, 100, stdin);
	int a = 0;
	int s = 0;
	while(s == 0){
		if(cadena[a] != '\0'){
			a = a+1;
			

		}else{
			s = 2;
		}
	}
	cont = 0;
	cont2 = a-2;

///P2
	printf ("Introduzca una cadena: ");
	fgets (cadena2, 100, stdin);
	int a1 = 0;
	int s1 = 0;
	while(s1 == 0){
		if(cadena2[a1] != '\0'){
			a1 = a1+1;
			

		}else{
			s1 = 2;
		}
	}
	cont3 = 0;
	cont4 = a1-2;


	if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
    else
        {
            int punt = 0;
            while (feof(archivo) == 0)
		    {	
                caracter =	 fgetc(archivo);
				if (caracter == cadena[0])
				{
					printf("%i-",pos);

		   			inicio = pos;
		   			contador = 0;
		   			if(revisar(pos) == 1){
		   				
		   			}
					
				}
		    	pos = pos+1;
		    }	
        }
       	cambios();
        
        fclose(archivo);
	return 0;
}

void limpiar(){
	printf("%i indiceVec : \n",indiceVec );
	for (int i = 0; i <= indiceVec; i++)
	{
		fseek(archivo,inicioA[i],SEEK_SET);
		for (int y = inicioA[i]; y < finalA[i] ; y++)
		{
			fseek(archivo,y,SEEK_SET);
			fputc('_',archivo);
		}

	}
    fclose(archivo);
    
	//cambios();
}

void cambios(){
	printf("%i\n",inicioA[0] );
	archivo = fopen("texto.txt","r+");
	printf("%i indiceVec : \n",indiceVec );
	for (int i = 0; i <= indiceVec; i++)
	{
		fseek(archivo,inicioA[i],SEEK_SET);
		for (int y = inicioA[i]; y < finalA[i] ; y++)
		{
			fseek(archivo,y,SEEK_SET);
			fwrite("_",1,1,archivo);
		}

	}
    reestrutura();
}
void reestrutura(){
	
	FILE *aux;
    aux = fopen("aux.txt","w");
    rewind(aux);
    fclose(aux);
    aux = fopen("aux.txt","a+");
    fseek(archivo,0,SEEK_SET);
    int positionActual = 0;
    int termino = 0; 
    while (termino == 0) //NO, no se puede limitar a el archivo origan ya que puede ser mas corto
   	{	
   		int bandera = 0;
   		
   		for (int i = 0; i < sizeof(inicioA); i++)
   		{
   			if (inicioA[i] == positionActual && i < 100)
   			{
   				printf("pos %i es %i \n",i,inicioA[i]);
   				bandera = 1;
   				break;
   			}
   		}
   		
   		if (bandera == 0 )
   		{
   	 		if(feof(archivo) != 0)
			{
				termino = 1;
			}else{
   	 		fseek(archivo,positionActual,SEEK_SET);
		    caracter =	 fgetc(archivo);
   			fputc(caracter,aux);
			positionActual = positionActual+1;
			}	

		}else if(bandera == 1){
			
			for (int y = 0; y <= cont4; y++)
			{
				fputc(cadena2[y],aux);
			}
			positionActual = positionActual + (cont4+(cont2-cont4+1));
		}
    }
    fclose(aux);
}

int revisar(int pos){
	
	fseek( archivo, pos, SEEK_SET );
	caracter = fgetc(archivo);

	if (caracter == cadena[contador])
	{	
		contador += 1;
		if (contador == cont2+1)
		{
			inicioA[indiceVec] = inicio;
			finalA[indiceVec] = inicio + contador;
			indiceVec += 1;
			//addArray(inicio,inicioA);
			//addArray(contador,finalA);
			return 1;

		}else
		{
			revisar(pos+1);
		}
	}else{
		contador = 0;
		return 0;
	}
}

int addArray(int i,int *arry){
	for(int x=0 ; x < sizeof(arry) ;x++){	
		if (arry[x] == 0)
			{
				arry[x] = i;
				break;
			}	
	}

}