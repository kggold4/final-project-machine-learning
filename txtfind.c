#include <stdio.h>
#include <string.h>
#include "txtfind.h"

// option 1

// part the text into different lines
void lines_part(char* string, char* word) {
    int new_len = 50;
    char new_string[new_len];
    for(int i = 0; string[i] != 0; i++) {
        new_string[i] = string[i];
        if(string[i] == '\n' || string[i] == 0) {
            lines_check(new_string, word);
            empty_string(new_string, new_len);
            //printf("\n\n\n");
        }
        printf("%c!", *(string + i));
    }
}

// if the line contains the word print it
void lines_check(char* string, char* word) {
    int contain = strstr(string, word) != NULL;
    if(contain) {
        printf("!!%s\n", string);
    }
}

void empty_string(char* string, int new_len) {
    for(int i = 0; i < new_len; i++) {
        *string = '\0';
        //string[i] = "";
    }
}

// option 2