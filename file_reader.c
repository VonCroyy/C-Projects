#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
        FILE *fptr;
        char file[255], c;
        errno = 0;

        printf("Give the file path: ");
        scanf("%254s", file);

        if (access(file, F_OK) != -1)
        {
                fptr = fopen(file, "r");

                if (fptr != NULL)
                {
                        while ((c = fgetc(fptr)) != EOF)
                        {
                                printf("%c", c);
                        }

                        fclose(fptr);
                }
                else
                {
                        fprintf(stderr, "Error: %s", strerror(errno));
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                fprintf(stderr, "Error: %s", strerror(errno));
                exit(EXIT_FAILURE);
        }

        return 0;
}
