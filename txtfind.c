#include <stdio.h>
#include <string.h>
#include "txtfind.h"
#define LINE_SIZE 256

// option 1

// part the text into different lines
void lines_part(char* string, char* word) {

    // create temporery sting for each line in string
    char temp[LINE_SIZE];

    // empty constant line for strcpy after reading a line
    const char empty_line[LINE_SIZE] = "";

    // index fot insert chars to temp
    int k = 0;
    
    // go throw all text
    for(int i = 0; string[i] != 0; i++) {
        temp[k] = string[i];
        k++;

        // end line
        if(string[i] == '\n') {

            // check if the line contains the word
            lines_check(temp, word);

            // make temp be empty again
            memset(temp, 0, strlen(temp));
            strcpy(temp, empty_line);
            k = 0;
        }
    }

    // for the last line (not reach in the for loop)
    lines_check(temp, word);
}

// if the line contains the word - print line
void lines_check(char* string, char* word) {

    int contain = strstr(string, word) != NULL;
    if(contain) {
        printf("%s", string);
    }

}

// option 2

void words_part(char* string, char* word) {

    // create temporery sting for each line in string
    char temp[256];

    // empty constant line for strcpy after reading a line
    const char empty_line[256] = "";

    // index fot insert chars to temp
    int k = 0;
    
    // go throw all text
    for(int i = 0; string[i] != 0; i++) {
        temp[k] = string[i];
        k++;

        // end word
        if(string[i] == ' ' || string[i] == '\n') {

            // check if the word contains the word partly
            words_check(temp, word);

            // make temp be empty again
            memset(temp, 0, strlen(temp));
            strcpy(temp, empty_line);
            k = 0;
        }
    }
    // for the last word (not reach in the for loop)
    words_check(temp, word);
}

void words_check(char* string, char* word) {
    int count = 0;
    for(int i = 0, k = 0; string[i] != 0; i++) {
        if(string[i] == word[k]) {
            count++;
            k++;
        }
    }
    if(count >= 2) {
        printf("\nword: %s", string);
    }
}