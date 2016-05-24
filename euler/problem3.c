#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char **argv)
{
    //600851475143
    long long int num = 600851475143;
    //int num = (int)n;
    
    printf("Num: %d\n", num);
    getchar();
    
    //int factor = (int)sqrt(num);
		
		int factor = sqrt(num);
    
    printf("Factor: %d\n", factor);
    getchar();    
    
    int big = 2;
    int i = 2;
    bool prime = false;
    
    while(factor>2)
    {      
      if(num%factor == 0){
				prime = false;
				for(i = 1;factor>i;i++){
					if(factor%i==0){
						if(i==1 || i==factor){
							prime = true;
						}else{
							prime = false;
						}
					}
					//printf("I: %d\n", i);
				} 
				
				if(prime){	
					
					if(factor > big)
						big = factor;
				}
	
      }
	
      factor = factor - 1;
          
      //printf("Factor: %d\n", factor);
      //printf("Big: %d\n", big);
      
    }
    
    printf("-----------------\n");
    //printf("Factor: %d\n", factor);
    printf("Big: %llu\n", big);
 
    return 0;
}