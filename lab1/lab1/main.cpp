#include <iostream>
#include <random>

int main() {
	int size;

	std::cout << "Enter size of array: ";
	std::cin >> size;

	float* array = (float*)malloc(size * sizeof(float));

	float max = FLT_MIN;
	float min = FLT_MAX;

	srand(time(NULL));

	std::cout << "mass: ";

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 1000 / 1000.0;
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < size; i++) {
		if (array[i] < min) {
			min = array[i];
		}
		if (array[i] > max) {
			max = array[i];
		}
	}
	free(array);
	std::cout << "max: " << max << " min: " << min << std::endl;
}