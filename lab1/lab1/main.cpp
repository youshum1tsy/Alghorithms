#include <iostream>
#include <random>

int main() {

	int rows;
	int collumns;
	std::cout << "Enter the rows: ";
	std::cin >> rows;
	std::cout << "Enter the collumns: ";
	std::cin >> collumns;

	int** array = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) {
		array[i] = (int*)malloc(collumns * sizeof(int));
	}

	int max = INT_MIN;
	int min = INT_MAX;

	srand(time(NULL));

	std::cout << "mass:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collumns; j++) {
			array[i][j] = rand() % 150 - 75;
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collumns; j++) {
			if (array[i][j] < min) {
				min = array[i][j];
			}
			if (array[i][j] > max) {
				max = array[i][j];
			}
		}
	}

	std::cout << std::endl;
	std::cout << "max: " << max << " min: " << min << std::endl;
	std::cout << std::endl;

	int rowSum;

	for (int i = 0; i < rows; i++) {
		rowSum = 0;
		for (int j = 0; j < collumns; j++) {
			rowSum += array[i][j];
			// std::cout << "element: " << array[i][j] << " ";
		}
		// std::cout << std::endl;
		std::cout << "rowSum: " << rowSum << std::endl;
	}

	std::cout << std::endl;
	int collumnSum;

	for (int i = 0; i < collumns; i++) {
		collumnSum = 0;
		for (int j = 0; j < rows; j++) {
			collumnSum += array[j][i];
			// std::cout << "element: " << array[j][i] << " ";
		}
		// std::cout << std::endl;
		std::cout << "collumnSum: " << collumnSum << std::endl;
	}

	for (int i = 0; i < rows; ++i) {
		free(array[i]);
	}
	free(array);

}