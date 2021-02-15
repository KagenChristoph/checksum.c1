/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
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
  byte buf[10];
  int fd;
  size_t nbyte;
  nbyte = sizeof(buf);
  int retval;

  /* the following is the prototype for the read system call */
  retval = read(fd,  (void *) &buf,nbyte);  
  for(int counter = 0; counter < 10; counter++)
    {
        
        printf((int)buf[counter]);
    }
  
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}
