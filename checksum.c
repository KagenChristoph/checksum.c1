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
  retval = read(fd,  (void *) &buf,bytes);  
  for(int i = 0; i < 10; i++)
    {
        int value = buf[i];
		if(value > max_int)
		{
			fprintf(stderr, "Error Detected In Input!\n"); 
		}
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
