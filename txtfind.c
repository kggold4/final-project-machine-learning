#include <stdio.h>
#include <string.h>
#include "txtfind.h"
#define LINE_SIZE 256
#define MAX_LINE_SIZE 250

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

            // delete '\n' new line from the word
            strtok(temp, "\n");

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
    if(count >= strlen(word) - 1) {
        printf("%s\n", string);
    }
}

// function that do nothing
void doNothing(char* string) {}

int main() {

    // empty line
    const char empty_line[LINE_SIZE] = "";

    // the word in the text
    char word[LINE_SIZE];

    // option is 'a' or 'b' that get from the text
    char option[1];

    int i = 0;
    while(i < MAX_LINE_SIZE) {

        // getting every line seperate
        char line[LINE_SIZE];
        fgets(line, LINE_SIZE, stdin);

        // getting information from the first line
        if(i == 0) {

            memset(word, 0, strlen(word));
            strcpy(word, empty_line);

            //printf("\n%d\n",count);
            for(int j = 0; j < strlen(line) - 4; ++j) {
                word[j] = line[j];
            }
            option[0] = line[strlen(line) - 3];

        } else {
            
            // option a
            if(option[0] == 'a') {
                lines_check(line, word);
                
            // option b
            } else if(option[0] == 'b') {
                words_part(line, word);
            }
        }

        // for ignore warning that option is not been used in his main scope
        doNothing(option);

        // end of text
        if(line[0] == '\0' && i > 2) {
            printf("\n");
            break;
        }

        // make line empty for the next line
        memset(line, 0, strlen(line));
        strcpy(line, empty_line);
        i++;
    }

    return 0;
}