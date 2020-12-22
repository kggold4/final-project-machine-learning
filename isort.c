#include <stdio.h>
#include "isort.h"

void shift_element(int* arr, int i) {
    for(int j = i; j > 0; --j) { *(arr + j) = *(arr + j - 1); }
}

void insertion_sort(int* arr, int len) {
    
    for (int i = 1; i < len; i++) { 
        int temp = *(arr + i), j = i - 1;
  
        while(j >= 0 && *(arr + j) > temp) { 
            *(arr + j + 1) = *(arr + j); 
            j = j - 1; 
        }
        *(arr + j + 1) = temp; 
    } 

}

void print_array(int* arr, int len) {
    for(int i = 0; i < len; i++) {
        int temp = *(arr + i);
        printf("%d",temp);
        if(i != len - 1) {
            printf(",");
        }
    }
    printf("\n");
}