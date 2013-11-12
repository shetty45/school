/**********************************************************************
* Name: Caleb Faruki
* Course: CISC3595 Operating Systems
* Date: September 30, 2013
* File: Bare-Bones cp Command
**********************************************************************/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char buf[BUFSIZ]; /*default buffer size of 256 bytes*/

int main(int argc, char** argv) {
	int src, dest; /*the two files being worked on*/
	int count; /*counts bytes in read file.*/

	if (argc!=3) { /*<cp> <source> <destination>*/
		printf("Error: Too few or too many arguments\n");
		return 1;
	}

	src = open(argv[1], O_RDONLY); /*open src as read-only*/
	if (src==-1) { /*-1: something went wrong.*/
		printf("Error: Can't open %s\n", argv[1]);
		return 1;
	}

	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
	/*O_WRONLY: write-only, O_CREAT: create file if none.
	  O_TRUNC: reset file length to 0.*/
	if (dest==-1) {
		printf("Error: Can't create %s\n", argv[2]);
		return 1;
	}

	/*while count reads bytes from src, write bytes to dest*/
	while((count = read(src, buf, BUFSIZ)) > 0)
		write(dest, buf, count);
	
	close(src);		/*close file descriptor 'src'*/
	close(dest);	/*close 'dest' file*/
	
	return 0;
}