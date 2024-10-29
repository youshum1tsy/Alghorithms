#include <iostream>
#include <vector>

int** createMatrix (int** matrix, int vertex, int edges) {

  matrix = (int**) malloc(sizeof(int*) * vertex);
  for (int v = 0; v < vertex; v++) {
    matrix[v] = (int*) calloc(edges, sizeof(int));
  }

  srand(time(NULL));
  for (int e = 0; e < edges; e++) {
    
    int v1 = rand() % vertex;
    int v2 = rand() % vertex;
    
    while (v2 == v1) {
      v2 = rand() % vertex;
    }

    matrix[v1][e] = 1;
    matrix[v2][e] = 1;
  }


  return matrix;
}

void printMatrix(int** matrix, int vertex, int edges) {

  for (int v = 0; v < vertex; v++) {
    for (int e = 0; e < edges; e++) {
      std::cout << matrix[v][e] << " ";
    }
    std::cout << "\n";
  }
  
}

int sizeMatrix(int** matrix, int vertex, int edges) {

  int count = 0;
  for (int v = 0; v < vertex; v++) {
    for (int e = 0; e < edges; e++) {
      if (matrix[v][e] == 1) {
        count++;
      }
    }
  }
  return count / 2;
}

void whichVertexType(int** matrix, int vertex, int edges) {
  for (int v = 0; v < vertex; v++) {
    int count = 0;
    std::vector<int> massEdgesIndex;
    for (int e = 0; e < edges; e++) {
      if (matrix[v][e] == 1) {
        count++;
        massEdgesIndex.push_back(e);
      }
    }
    if (count == 0) {
      std::cout << "Vertex " << v+1 << " isolated" << std::endl;
    }
    else if (count == 1) {
      std::cout << "Vertex " << v+1 << " end" << std::endl;
    }
    else if (count == vertex - 1) {
      bool isDominant = true;
      for (int currentV = 0; currentV < vertex; currentV++) {
        if (currentV == v) {
          continue;
        }

        bool connected = false;
        for (int eIndex : massEdgesIndex) {
          if (matrix[currentV][eIndex] == 1) {
            connected = true;
            break;
          }
        }
        if (!connected) {
          isDominant = false;
          break;
        }
      }
      if (isDominant) {
        std::cout << "Vertex " << v+1 << " dominant" << std::endl;
      }
    }
  }
}

int main() {

  int vertex;
  std::cout << "Enter amount vertex in matrix: ";
  std::cin >> vertex;

  int edges;
  std::cout << "Enter amount edges in matrix: ";
  std::cin >> edges;
  
  int maxEdges = vertex * (vertex - 1) / 2;
  
  while (edges > maxEdges) {    

    std::cout << "Enter edges in matrix <= " << maxEdges << " : ";
    std::cin >> edges;
  }

  int** matrix = createMatrix(matrix, vertex, edges);
  
  printMatrix(matrix, vertex, edges); 
  std::cout << "size: " << sizeMatrix(matrix, vertex, edges) << std::endl;
  whichVertexType(matrix, vertex, edges);
  return 0;
}
