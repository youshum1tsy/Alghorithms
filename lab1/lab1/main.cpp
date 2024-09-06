#include <iostream>

int main() {
	int mass[10] = { 10, 15, 3, 8, 64, 124, 55, 20, 19, 13 };
	int max = INT_MIN;
	int min = INT_MAX;
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