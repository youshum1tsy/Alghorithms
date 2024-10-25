#include <iostream>

int** createMatrix (int** matrix, int amount) {
  matrix = (int**)malloc(sizeof(int*) * amount);
  for (int i = 0; i < amount; i++) {
    matrix[i] = (int*)malloc(sizeof(int) * amount);
  }
  
  for (int i = 0; i < amount; i++) {
    for (int j = 0; j < amount; j++) {
      matrix[i][j] = 0;
    }
  }

  srand(time(NULL));
  for (int i = 0; i < amount; i++) {
    for (int j = i + 1; j < amount; j++) {
      if (i == j) {
        matrix[i][j] = 0;
      }
      else {
        matrix[i][j] = rand() % 2;
        matrix[j][i] = matrix[i][j];
      }
    }
  }

  return matrix;
}

void printMatrix(int** matrix, int amount) {

  for (int i = 0; i < amount; i++) {
    for (int j = 0; j < amount; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
  
}

int sizeMatrix(int** matrix, int amount) {

  int count = 0;
  for (int i = 0; i < amount; i++) {
    for (int j = i + 1; j < amount; j++) {
      if (matrix[i][j] == 1) {
        count++;
      }
    }
  }
  return count;
}

void whichVertexType(int** matrix, int amount) {
  for (int i = 0; i < amount; i++) {
    int count = 0;
    for (int j = 0; j < amount; j++) {
      if (matrix[i][j] == 1) {
        count++;
      }
    }
    if (count == 0) {
      std::cout << "Vertex " << i+1 << " isolated" << std::endl;
    }
    else if (count == 1) {
      std::cout << "Vertex " << i+1 << " end" << std::endl;
    }
    else if (count == amount-1) {
      std::cout << "Vertex " << i+1 << " dominant" << std::endl;
    }
  }
}

int main() {

  int amount;
  std::cout << "Enter amount vertex in matrix: ";
  std::cin >> amount;

  int** matrix = createMatrix(matrix, amount);
  printMatrix(matrix, amount); 
  std::cout << "size: " << sizeMatrix(matrix, amount) << std::endl;
  whichVertexType(matrix, amount);
  return 0;
}
