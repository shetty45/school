/**********************************************************************
 *
 * CISC 3595, Fall 2013
 * A simple version of the Unix "echo" command
 *
 * Author: A. G. Werschulz
 * Date:   23 Sept 2013
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>

#define BUFSIZE 1024

char buf[BUFSIZE];

int main(int argc, char** argv)
{
   int i;

   for (i = 1; i < argc; i++)
      printf("%s ", argv[i]);
   printf("\n");
}
