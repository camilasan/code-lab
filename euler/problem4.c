#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    
    int i = 100;
    int j = 100;
    int big = 10000;
    for(i = 100;1000>i;i++){
      for(j = 100;1000>j;j++){      
	int palind = i*j;
	char string[5];
	sprintf(string, "%d", palind);
	char aux_string[5];	
	int len = 5;
	int x = 0;
	
	while(x<6){
	  aux_string[x]=string[len];
	  x++;
	  len--;
	}
	

	if(strcmp(string, aux_string)==0 && palind>big)
	  big = palind;

      }
    } 
	
    printf("Big: %d\n", big);

 
    return 0;
}


Python Basic:
// 1
var myObj = {};
// 2
var myVal = myObj['name'];
var myVal2;
alert(myVal2);
if(myVal == null) {
    alert('Missing: ' + 'name');
}
Input data:
calls = [ 
                ( 'n1', 'n2', 'success' ),
                ( 'n1', 'n3', 'failed' ),
                ( 'n1', 'n2', 'failed' ),
                ( 'n2', 'n1', 'failed' )
]
function() {
}
Result should be:
n1 => n2: 50%
n2 => n1: 0%
n1 => n3: 0%
