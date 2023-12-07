#include <stdio.h>

int main() {
	int raws, columns, n_raws, n_columns;

	printf("Give the number of raws: ");
	scanf("%d", &raws);

	printf("Give the number of columns: ");
	scanf("%d", &columns);

	printf("\n---------------------------------\n");

	//Declaring array
	int arr[raws][columns];

	//Calculating the size of raws and columns
	n_raws = sizeof(arr) / sizeof(arr[0]);
	n_columns = sizeof(arr[0]) / sizeof(arr[0][0]);

	//Giving values to the array
	for (int i = 0; i < n_raws; i++) {
		for (int j = 0; j < n_columns; j++) {
			printf("Give the %d element of the %d raw: ", j + 1, i + 1);
			scanf("%d", &arr[i][j]);
		}
		printf("---------------------------------\n");
	}

	//Printing the values of the array
	for (int i = 0; i < n_raws; i++) {
		for (int j = 0; j < n_columns; j++) {
			printf("The numbers of the %dst raw is: %d\n", i + 1, arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}