/********************************/
/* Program Name: checksum.c     */
/* Author:     Kagen Christoph  */
/* Date:          2/13/2021     */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  byte checksum; 
  byte complement;
  byte remainder;
  byte quotient;
  byte buf[count];
  int fd;
  size_t bytes;
  bytes = sizeof(buf);
  int retval;
  int checkPass = 5;

  /* the following is the prototype for the read system call */
  retval = read(0,  (void *) &buf,10);  
  for(int i = 0; i < 10; i++)
    {
        int value = buf[i];
	  printf("Numbers Entered: %d \n", value);
  }
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}
