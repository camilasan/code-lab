#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    
    
    int sum = 0;
    int square = 0;
    int dif = 0;
    int i = 0;
    
      
    for(i =1;101>i;i++){ 
      sum = (i*i)+sum;
      square = square + i; 
    }
      
    square = square*square;
    dif = square - sum;
	
    printf("Sum of the squares: %d\n", sum);
    printf("The square of the sum: %d\n", square);
    printf("square - sum = %d\n", dif);

 
    return 0;
}