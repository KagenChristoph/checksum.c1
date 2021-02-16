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
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  int checksum;         // The value of the 6th input integer
  int quotient;             // The result of evaluating the assignment:  quotient   = sum / (max_int + 1);
  int remainder;            // The result of evaluating the assignment:  remainder  = sum % (max_int + 1 );
  int complement;   
  byte buf[10];
  int fd;
  size_t nbyte;
  nbyte = sizeof(buf);
  int retval;
  int checkPass = 5;

  /* the following is the prototype for the read system call */
  retval = read(fd,  (void *) &buf,nbyte);  
  for(int i = 0; i < 10; i++)
    {
        int value = buf[i];
    if(i == checkPass)
		{
			checksum = value;
			value = 0;
		}
		sum += value;
    }
  quotient   = sum / (max_int + 1);
	remainder  = sum % (max_int + 1 );
	sum = quotient + remainder;
	complement = max_int - sum;
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}
