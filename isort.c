#include <stdio.h>
#include "isort.h"
#define N 50

// move every element in the array one index right
void shift_element(int* arr, int i) {
    for(int j = i; j > 0; --j) { *(arr + j) = *(arr + j - 1); }
}

// insertion sort
void insertion_sort(int* arr, int len) {
    
    for(int i = 1; i < len; i++) { 
        int temp = *(arr + i), j = i - 1;
        while(j >= 0 && *(arr + j) > temp) { 
            *(arr + j + 1) = *(arr + j); 
            j = j - 1; 
        }
        *(arr + j + 1) = temp; 
    }
}

// printing array
void print_array(int* arr, int len) {
    for(int i = 0; i < len; i++) {

        int temp = *(arr + i);
        printf("%d",temp);

        // last int dont have ','
        if(i != len - 1) {
            printf(",");
        }
    }
    printf("\n");
}

// main function of isort
int main() {

    // getting from the user N integer to arr array
    int arr[N], i = 0;
    while(i < N) {
        int input;
        scanf("%d", &input);
        *(arr + i) = input;
        ++i;
    }

    // sorting
    insertion_sort(arr, N);

    // printing
    print_array(arr,N);
    return 0;
}