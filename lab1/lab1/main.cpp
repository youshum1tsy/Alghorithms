#include <iostream>
#include <random>

int main() {
	int mass[10] = { 0 };
	int max = INT_MIN;
	int min = INT_MAX;

	srand(time(NULL));

	std::cout << "mass: ";

	for (int i = 0; i < 10; i++) {
		mass[i] = rand() % 150 - 75;
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;

	for (int number : mass) {
		if (number < min) {
			min = number;
		}
		if (number > max) {
			max = number;
		}
	}
	std::cout << "max: " << max << " min: " << min << std::endl;
}