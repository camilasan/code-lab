#include <stdio.h>
 
int main(int argc, char **argv)
{
    int i;
    int resultado = 0;
    for(i = 1; i < 1000; i++)
    {
        if((i%3 == 0) || (i%5 == 0))
            resultado += i;
    }
 
    printf("Resultado: %d\n", resultado);
 
    return 0;
}