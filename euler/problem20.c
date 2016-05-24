#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define NUM 30
#define MAX 50

 
int main(int argc, char **argv)
{
    int i;
    int mult = 1;
    for(i = NUM; i > 0; i--)
    {
      mult = mult*i;
    }
    
    char s[MAX];
    snprintf(s, MAX,"%d", mult);
     
    printf("Mult: %d\n", mult);
    
    int soma = 0;
    int size = strlen(s);
    
    printf("Size: %d\n", size);
    
    
    
    for(i = 0; i < size-1; i++)
    {
      int conv = s[i] - '0';
      printf("conv: %d\n", conv);
      soma = soma + conv;
    }
    
    printf("Soma: %d\n", soma);
    
    return 0;
}