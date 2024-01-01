#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct
{
	int *elements;
	int size;
	int cap;
} dynamic;

int main(int argc, char **argv)
{
	int user_size, user_num, choice, rm_element;
	dynamic array;
	errno = 0;

	printf("Give the size of the array: ");
	scanf("%d", &user_size);
	printf("----------------------------------------------\n");

	//Initialise array
	array.elements = calloc(1, sizeof(*array.elements));
	array.size = 0;
	array.cap = 1;

	//Giving values to the array and check for errors
	if (array.elements != NULL)
	{
		for (int i = 0; i < user_size; i++)
		{
			printf("Give the %d number of the array: ", i + 1);
			scanf("%d", &user_num);
			array.elements = realloc(array.elements, (array.cap + 1) * sizeof(*array.elements));

			if (array.elements != NULL)
			{
				array.elements[i] = user_num;
				array.size++;
				array.cap++;
			}
			else
			{
				fprintf(stderr, "Error: %s", strerror(errno));
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "Error: %s", strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("----------------------------------------------\n");

	//Decision making
	printf("1 Decrease | 2 End : ");
	scanf("%d", &choice);

	printf("----------------------------------------------\n");	

	if (choice == 1)
	{
		//Creating and initialising new array
		dynamic new_array;
		new_array.elements = calloc(array.size, sizeof(*new_array.elements));
		new_array.size = 0;
		new_array.cap = array.size;

		for (int i = 0; i < array.size; i++)
		{
			printf("Item %d: %d\n", i + 1, array.elements[i]);
		}

		printf("----------------------------------------------\n");

		printf("Chose the item you want to remove: ");
		scanf("%d", &rm_element);

		printf("----------------------------------------------\n");

		//Copying array to new_array
		for (int i = 0; i < array.size; i++)
		{
			if (i == rm_element - 1)
			{
				continue;
			}
			else
			{
				new_array.elements[new_array.size] = array.elements[i];
				new_array.size++;
			}
		}

		free(array.elements);

		//Printing new_array
		for (int i = 0; i < new_array.size; i++)
		{
			printf("Item %d: %d\n", i + 1, new_array.elements[i]);
		}

		free(new_array.elements);
		
		printf("----------------------------------------------\n");
		printf("The program has ended.\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("The program has ended.\n");
		free(array.elements);
		exit(EXIT_SUCCESS);
	}

	return 0;
}
