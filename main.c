#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "isort.h"
#include "txtfind.h"
#define N 50

int main() {
	
	char main_string[] = "this is a text file\nlooking for the word cat\nthe program should print also cats\nafter cats crat and lcat are printed\nthe program shouldn’t print\nthe word caats\0";
	char hello[] = "cat";

    //char string1[];
    //strcpy
	//lines_part(main_string, hello);

    printf("\n\npart 2\n\n");

    words_part(main_string, hello);

	
	return(0);
}