/***************************************************************************
 * studlib.c - a small library for functions I often use during my program
 ***************************************************************************
 * Dependencies:
 ***************
 * <stdio.h>
 * <stdlib.h>
 * <time.h>
 * <string.h>
 ***************************************************************************
 * Feel free to send issues/pull requests! <3
 ***************************************************************************/

/**************
 * User Input *
 **************/

// Inputs string in *s (allocate memory first!) and returns string length
int string(char *s, int maxlen) {
	int len;

	s = fgets(s, maxlen , stdin); 
		if(s == NULL)
			return 0;
	len = strlen(s);
	if (s[len - 1] == '\n')
		s[--len] = '\0'; // remove line break

	return len; 
} 

// Input integer
int getInt() {
	int z;
	scanf("%d", &z);
	return z;
}

// Input double
double getDouble() {
	double z;
	scanf("%lf", &z);
	return z;
}

// Input single char
char getChar() {
	char z;
	scanf("%c", &z);
	return z;
}

/**************
 *** Arrays ***
 **************/

// Returning array with specific size
int* createArray(int size) {
	int* array = malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}

	return array;
}

// Shuffles array, make sure to run seedInit() first!
void shuffleArray(int* array, int size) {
	int temp = 0;
	int j = 0;
	
	for (int i = size - 1; i >= 0; i--) {
		j = rand() % (i + 1);
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}
}


// Creating an array with specific size and randomizing it
int* createRandArray(int size) {
	int* array = malloc(size * sizeof(int));
	int j = 0, temp = 0;
	
	// Creating array with ordered set numbers
	for (int i = 0; i < size; i++) {
		array[i] = i;
	}

	// Shuffle array
	for (int i = size - 1; i >= 0; i--) {
		j = rand() % (i + 1);
		temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}

	return array;
}

// Print array
void printArray(int* array, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d", array[i]);

		if (i != size - 1) {
			printf(",");
		}
	}
	printf("]\n");
}

/**************
 *** Matrix ***
 **************/

// Create n-by-n matrix
int* create2DMatrix(int n) {
	int* array = malloc(n * sizeof(int));

	if (!array) {
		printf("Error while allocating memory. NULL pointer returned\n");
		return NULL;
	}

	else {
		return array;
	}
}

// Fill 2D Matrix with 0
void zeroMatrix(int** array, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			array[i][j] = 0;
		}
	}
}
 
// Create a custom sized 2D Matrix
int** createCustom2DMatrix(int n, int m) {
	int** array = malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		array[i] = malloc(n * sizeof(int));
	}

	if (!array) {
		printf("Error while allocating memory. NULL pointer returned\n");
		return NULL;		
	}
	else {
		//printf("%dx%d matrix created.\n", n, m);
		return array;
	}
}

// Print n-by-n matrix
void print2DMatrix(int** array, int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//printf("%d/%d: %d\t", i, j, array[i][j]);
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}

// Print custom sized 2D Matrix
void printCustom2DMatrix(int** array, int n, int m) {
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//printf("%d/%d: %d\t", i, j, array[i][j]);
			printf("%d\t", array[i][j]);			
		}
		printf("\n");
	}	
}

/**************
 **** Misc ****
 **************/

// Randomizing seed
void seedInit() {
	srand(time(0));
	rand();
}
