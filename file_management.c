#include <stdio.h>

int main() {
    FILE *fptr;
    char file[50], c;

    printf("Give the file path: ");
    scanf("%s", &file);

    printf("\n");

    //Opening the file 
    fptr = fopen(file, "r");

    //Read and printing the contents of the file
    if (fptr != NULL) {
        printf("\nThe file contents\n");
        printf("--------------------\n");
        while ((c = fgetc(fptr)) != EOF) {
            printf("%c", c);
        }
        printf("--------------------");
        printf("\nThe file has been readed successfully!");
    }

    return 0;
}