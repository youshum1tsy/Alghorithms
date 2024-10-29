#include <iostream>
#include <vector>

int** createMatrixS(int vertex) {
    int** matrix = (int**)malloc(sizeof(int*) * vertex);
    for (int i = 0; i < vertex; i++) {
        matrix[i] = (int*)calloc(vertex ,sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < vertex; i++) {
        for (int j = i + 1; j < vertex; j++) {
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

int** createMatrixI(int** matrixS, int vertex, int edges) {

    int** matrixI = (int**)malloc(vertex * sizeof(int*));
    for (int v = 0; v < vertex; v++) {
        matrixI[v] = (int*)calloc(edges, sizeof(int));
    }

    int currentEdge = 0;
    for (int i = 0; i < vertex; i++) {
        for (int j = i + 1; j < vertex; j++) {
            if (matrixS[i][j] == 1) {
                matrixI[i][currentEdge] = 1;
                matrixI[j][currentEdge]= 1;
                currentEdge++;
            }
        }
    }
    return matrixI;
}

void printMatrixS(int** matrix, int vertex) {

    for (int v = 0; v < vertex; v++) {
        for (int e = 0; e < vertex; e++) {
            std::cout << matrix[v][e] << " ";
        }
        std::cout << "\n";
    }
}

void printMatrixI(int** matrix, int vertex, int edges) {

    for (int v = 0; v < vertex; v++) {
        for (int e = 0; e < edges; e++) {
            std::cout << matrix[v][e] << " ";
        }
        std::cout << "\n";
    }
}

int sizeMatrixS(int** matrix, int vertex) {

    int count = 0;
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int sizeMatrixI(int** matrix, int vertex, int edges) {

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

void whichVertexTypeS(int** matrix, int vertex) {
    for (int i = 0; i < vertex; i++) {
        int count = 0;
        for (int j = 0; j < vertex; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
        if (count == 0) {
            std::cout << "Vertex " << i + 1 << " isolated" << std::endl;
        }
        else if (count == 1) {
            std::cout << "Vertex " << i + 1 << " end" << std::endl;
        }
        else if (count == vertex - 1) {
            std::cout << "Vertex " << i + 1 << " dominant" << std::endl;
        }
    }
}

void whichVertexTypeI(int** matrix, int vertex, int edges) {
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
            std::cout << "Vertex " << v + 1 << " isolated" << std::endl;
        }
        else if (count == 1) {
            std::cout << "Vertex " << v + 1 << " end" << std::endl;
        }
        else if (count == vertex) {
            std::cout << "Vertex " << v + 1 << " dominated" << std::endl;
        }
    }
}

int main() {

    int vertex;
    std::cout << "Enter amount vertex in matrix: ";
    std::cin >> vertex;

    int** matrixS = createMatrixS(vertex);
    
    printMatrixS(matrixS, vertex);
    std::cout << "size: " << sizeMatrixS(matrixS, vertex) << std::endl;
    whichVertexTypeS(matrixS, vertex);

    std::cout << "---" << std::endl;

    int edges = sizeMatrixS(matrixS, vertex) / 2;
    int** matrixI = createMatrixI(matrixS, vertex, edges);
    
    printMatrixI(matrixI, vertex, edges);
    std::cout << "size: " << sizeMatrixI(matrixI, vertex, edges) << std::endl;
    whichVertexTypeI(matrixI, vertex, edges);
    return 0;
}
