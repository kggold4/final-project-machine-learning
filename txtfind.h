#ifndef TXTFIND_H
#define TXTFIND_H

// first option functions
void lines_part(char* string, char* word);
void lines_check(char* string, char* word);

// second option functions
void words_part(char* string, char* word);
void words_check(char* string, char* word);

// function that do nothing for ignore warnnings if the use of the char array is in inner scope,
// bu do not have use in the global scope of the function
void doNothing(char* string);

#endif // ISORT_H