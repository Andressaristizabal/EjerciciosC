#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a; 
    printf("introdusca un numero\n"); 
    scanf("%i", &a); 
    int i = 1;
    while(i<a){        
        if ( (a % i) == 0)
        {
           if (i != 1 && i != 0)
           {
               printf("El numero %i es factor de %i y es primo \n",i,a );
           }
        }
        i = i+1;
    }
    return 0;
}