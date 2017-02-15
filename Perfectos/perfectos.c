#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a; 
    printf("introdusca un numero\n"); 
    scanf("%i", &a); 
    int i = 1;
    int s = 0;
    while(i<a){        
        if ( (a % i) == 0)
        {
          s = s + i;
        }
        i += 1;
    }
    if (s == a)
    {
      printf("Es un numero perfecto %i\n",s );
    }
  
    return 0;
}