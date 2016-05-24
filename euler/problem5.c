#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    int j = 0;     
    int d = 0; 
		int i = 0;
		int total = 1;
		div_t divresult;
      
    while(total > 0){
			
			d++;
			int result[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
			total = 0;
			
      for(i=0;i<20;i++){ 	
				divresult = div(d, result[i]);
				if(divresult.quot > 0 && divresult.rem == 0){	  
					result[i] = divresult.rem;	
				}	
      }      
      
      for (j = 0; j < 20; j++ ){
				total = total + result[j];
			}
    }
    printf("Smallest: %d\n", d);
    return 0;
}