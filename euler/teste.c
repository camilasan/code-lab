#include <stdio.h>

#include <stdbool.h>

int listLength ( int A[], int N ) {
  
      int i;
    int length = 0;
  
    for(i = 0; i < N; i++)
    {
      if(A[i] != i)
	length+=1;
    }
    
    return length;
}

int main(int argc, char **argv)
{
  
  int B[] = {1, 1, 2, 5, 4, 5, 6, 7, 8, 9, 10};
  printf("%d", listLength(B, 10));
  return 0;
  
}