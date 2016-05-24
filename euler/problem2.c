#include <stdio.h>

int main(int argc, char **argv)
{
    int max = 4000*1000;
    int total = 2;
    int third = 3;
    int fir = 1;
    int sec = 2;
    int sum = 2;   
   
    
    while(third<max)
    {           
      if(third%2 == 0)
	sum += third;
      fir = sec;
      sec = third;
      third = fir + sec; 
    }
    
    printf("Max: %d\n", max);
    printf("Resultado: %d\n", sum);
 
    return 0;
}