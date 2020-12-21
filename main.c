#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "isort.h"
#include "txtfind.h"
#define N 50

int main() {
	
	char string1[] = "this is check text hello \n this is second helloline\0";
	char hello[] = "hello";
	lines_part(string1, hello);

	
	return(0);
}

// main function
/*int main() {
    int arr[N];

    int i = 0;
    int* ip = arr;
    while(i < N) {
        printf("please insert %d: \n", i);
        scanf("%d", (ip + i));
        i++;
    }

    //int sorted[N] = {1,2,3,4,5,6,7,8,9,10};
    //shift_element(sorted, 7);
    insertion_sort(arr, N);
    print_array(arr, N);
    




    return 0;
}*/
