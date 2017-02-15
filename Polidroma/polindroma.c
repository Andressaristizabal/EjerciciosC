#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char cadena[100];
int isPoli(int i, int y);
int main(int argc, char const *argv[])
{

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
  int cont = 0;
  int cont2 = a-2;
  int l = isPoli(cont, cont2);
  if (l == 1){
    printf("Es Polindroma\n");
  }
  return 0;
}

int isPoli(int i, int y){

  if (i<y)
  {
    if (toupper(cadena[i])==toupper(cadena[y]))
    {
      if(isPoli(i+1,y-1)==1 || isPoli(i+1,y-1)==2 ){
        return 1;
      }else{
        return 0;
      }
    }else
    {
      return 0;
    }
  }
  else if (i == y)
  {
    if (cadena[i] == cadena[y])
    {
      return 1;
    }else
    {
      return 0;
    }
  }
  else{
    return 2;
  }

  
}