#include <iostream>
#include <time.h>

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int compare(const void* val1, const void* val2) {
	return (*(int*)val1 - *(int*)val2);
};


int main(void) {
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end;
	int size = 1000000;

	int* a = (int*)malloc(sizeof(int) * size);
	int* b = (int*)malloc(sizeof(int) * size);
	int* c = (int*)malloc(sizeof(int) * size);
	int* d = (int*)malloc(sizeof(int) * size);


	srand(time(NULL));
	for (size_t i = 0; i < size; i++) {
		a[i] = rand() % 100 + 1;
	}
	start = clock();
	shell(a, size);
	end = clock();
	std::cout << "1. shell sort: " <<(float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;

	srand(time(NULL));
	for (size_t i = 0; i < size; i++) {
		a[i] = rand() % 100 + 1;
	}

	start = clock();
	qs(a, 0, size - 1);
	end = clock();
	std::cout << "1. qs sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;
	
	srand(time(NULL));
	for (size_t i = 0; i < size; i++) {
		a[i] = rand() % 100 + 1;
	}
	start = clock();
	qsort(a, size, sizeof(int), compare);
	end = clock();
	std::cout << "1. qsort c++ sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;



	for (size_t i = 0; i < size; i++) {
		b[i] = i * 2;
	}
	start = clock();
	shell(b, size);
	end = clock();
	std::cout << "2. shell sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;

	for (size_t i = 0; i < size; i++) {
		b[i] = i * 2;
	}
	start = clock();
	qs(b, 0, size - 1);
	end = clock();
	std::cout << "2. qs sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;

	for (size_t i = 0; i < size; i++) {
		b[i] = i * 2;
	}
	start = clock();
	qsort(b, size, sizeof(int), compare);
	end = clock();
	std::cout << "2. qsort c++ sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;



	for (size_t i = 0; i < size; i++) {
		c[i] = i * -2;
	}

	start = clock();
	shell(b, size);
	end = clock();
	std::cout << "3. shell sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;

	for (size_t i = 0; i < size; i++) {
		c[i] = i * -2;
	}

	start = clock();
	qs(b, 0, size - 1);
	end = clock();
	std::cout << "3. qs sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;

	for (size_t i = 0; i < size; i++) {
		c[i] = i * -2;
	}
	start = clock();
	qsort(c, size, sizeof(int), compare);
	end = clock();
	std::cout << "3. qsort c++ sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;



	for (size_t i = 0; i < size; i++) {
		if (i <= size / 2) {
			d[i] = i * 2;
		}
		else {
			d[i] = i / 2;
		}
	}
	start = clock();
	shell(d, size);
	end = clock();
	std::cout << "4. shell sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;

	for (size_t i = 0; i < size; i++) {
		if (i <= size / 2) {
			d[i] = i * 2;
		}
		else {
			d[i] = i / 2;
		}
	}
	start = clock();
	qs(d, 0, size - 1);
	end = clock();
	std::cout << "4. qs sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;
	
	for (size_t i = 0; i < size; i++) {
		if (i <= size / 2) {
			d[i] = i * 2;
		}
		else {
			d[i] = i / 2;
		}
	}
	start = clock();
	qsort(d, size, sizeof(int), compare);
	end = clock();
	std::cout << "4. qsort c++ sort: " << (float(end) - float(start)) / CLOCKS_PER_SEC << std::endl;

	return(0);
}
