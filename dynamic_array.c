#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *element;
    int size;
    int cap;
} dynamic_arr;

int main() {
    dynamic_arr arr, arr_2;
    int arr_num, user_inp, choice, element;

    printf("Give the size of the array: ");
    scanf("%d", &arr_num);

    printf("----------------------------\n");

    //initialise array
    arr.element = calloc(1, sizeof(*arr.element));
    arr.size = 0;
    arr.cap = 1;

    //Checking for null return value and giving values to the array
    if (arr.element != NULL) {
        for (int i=0; i < arr_num; i++) {
            printf("Give the %d number of the array: ", i + 1);
            scanf("%d", &user_inp);
            arr.element = realloc(arr.element, (arr.cap + 1) * sizeof(*arr.element));
            if (arr.element != 0) {
                arr.element[arr.size] = user_inp;
                arr.size++;
                arr.cap++;
            }
            else {
                printf("The Memory Reallocation Failed!");
            }
        }
    }
    else {
        printf("The Memory Allocation Failed!");
    }

    //Checking if the user want to decrease the array
    printf("----------------------------\n");
    printf("1 for decrease | 2 for continue: ");
    scanf("%d", &choice);
    printf("----------------------------\n");

    if (choice == 1) {
        //Printing the elements of the list for the user
        for (int i=0; i < arr.size; i++) {
            printf("The %d element of the array is: %d\n", i + 1, arr.element[i]);
        }
        
        //Initialising second array
        arr_2.element = calloc(arr.size, sizeof(*arr_2.element));
        arr_2.size = 0;
        arr_2.cap = arr.size;

        printf("----------------------------\n");
        printf("Give the element you want to remove: ");
        scanf("%d", &element);
        printf("----------------------------\n");
        
        //Removing an element from the list
        if (arr_2.element != NULL) {
            for (int i=0; i < arr_2.cap; i++) {
                if (i != element - 1) {
                    arr_2.element[arr_2.size] = arr.element[i];
                    arr_2.size++;
                }
                else {
                    continue;
                }
            }
            free(arr.element);
        }
        else {
            printf("The Memory Allocatio Failed!");
        }
    }
    else {
        printf("The Program Has Ended!");
        free(arr.element);
        return 1;
    }

    //Printing new array elements
    for (int i=0; i < arr_2.size; i++) {
        printf("The %d element of the array is: %d\n", i + 1, arr_2.element[i]);
        if (i == arr_2.size - 1) {
            printf("----------------------------\n");
            printf("The Program Has Ended!");
        }
    }

    if (choice == 1) {
        free(arr_2.element);
    }

    return 0;
}
