#include <stdio.h>

typedef struct {
    int *element;
    int size;
    int cap;
} arithmetic;

int main() {
    arithmetic dynamicArray;
    int usr_inp, usr_num;
    int i;

    printf("Give the size of the numbers: ");
    scanf("%d", &usr_inp);

    printf("--------------------------------------\n");

    //initialise array
    dynamicArray.size = 0;
    dynamicArray.element = calloc(1, sizeof(*dynamicArray.element));
    dynamicArray.cap = 1;

    //checking for NULL return value && adjust memory as needed
    if(dynamicArray.element != NULL) {
        for(i=0; dynamicArray.size < usr_inp; i++) {
            printf("Give the %dst number: ", i + 1);
            scanf("%d", &usr_num);
            dynamicArray.element = realloc(dynamicArray.element, (dynamicArray.cap + 1) * sizeof(*dynamicArray.element));
            if(dynamicArray.element != NULL) {
                dynamicArray.element[dynamicArray.size] = usr_num; 
                dynamicArray.size ++;
                dynamicArray.cap ++;
            } 
            else {
                printf("The memory reallocation failed!");
                return 1;
            }
        }
    } 
    else {
        printf("The memory allocation failled!");
        return 1;
    }

    printf("--------------------------------------\n");

    //printing the elements of the array
    for(i=0; i < dynamicArray.size; i++) {
        printf("The %dst element of the Dynamically Allocated Array is: %d\n", i, dynamicArray.element[i]);
    }

    //freeing the memory after use
    free(dynamicArray.element);

    return 0;
}
