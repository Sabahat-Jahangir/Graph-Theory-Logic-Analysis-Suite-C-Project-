#include <iostream>
#include <windows.h>

class MatrixRelations {
private:
    int **matrix;
    int size;

public:
    MatrixRelations(int size) : size(size) {
        matrix = new int *[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new int[size];
        }
    }

    void inputMatrix() {
        std::cout << "Enter the elements of the matrix (" << size << "x" << size << "):\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }

    void displayDirectedGraph() {
        std::cout << "\nDirected Graph Representation:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    int checkReflexive() const {
        for (int i = 0; i < size; ++i) {
            if (matrix[i][i] != 1) {
                return 0;
            }
        }
        return 1;
    }

    int checkSymmetric() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return 0;
                }
            }
        }
        return 1;
    }

    int checkAntisymmetric() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                    return 0;
                }
            }
        }
        return 1;
    }

    int checkTransitive() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] == 1) {
                    for (int k = 0; k < size; ++k) {
                        if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }

   void displayRelations() {
    int reflexive = checkReflexive();
    int symmetric = checkSymmetric();
    int antisymmetric = checkAntisymmetric();
    int transitive = checkTransitive();

    std::cout << "Relations detected:\n";

    if (reflexive) {
        std::cout << "Reflexive\n";
    }
    if (symmetric) {
        std::cout << "Symmetric\n";
    }
    if (antisymmetric) {
        std::cout << "Antisymmetric\n";
    }
    if (transitive) {
        std::cout << "Transitive\n";
    }

    if (!reflexive || !symmetric || !antisymmetric || !transitive) {
        std::cout << "\nPairs required to make respective relation:\n";
        if (!reflexive) {
            std::cout << "To make it Reflexive, add the following pairs:\n";
            for (int i = 0; i < size; ++i) {
                if (matrix[i][i] != 1) {
                    std::cout << i << "," << i << " ";
                }
            }
            std::cout << "\n";
        }
        if (!symmetric) {
            std::cout << "To make it Symmetric, add the following pairs:\n";
            for (int i = 0; i < size; ++i) {
                for (int j = i + 1; j < size; ++j) {
                    if (matrix[i][j] != matrix[j][i]) {
                        std::cout << i << "," << j << " ";
                    }
                }
            }
            std::cout << "\n";
        }
        if (!antisymmetric) {
            std::cout << "To make it Antisymmetric, remove the following pairs:\n";
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                        std::cout << i << "," << j << " ";
                    }
                }
            }
            std::cout << "\n";
        }
        if (!transitive) {
            std::cout << "To make it Transitive, add the following pairs:\n";
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (matrix[i][j] == 1) {
                        for (int k = 0; k < size; ++k) {
                            if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                                std::cout << i << "," << k << " ";
                            }
                        }
                    }
                }
            }
            std::cout << "\n";
        }
    }
}



    ~MatrixRelations() {
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};
// Function to set text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
int main() {
    using namespace std;
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "\t\t                   -----------------------" << endl;
	cout << "\t\t                  | WELCOME TO OUR CODE   |" << endl;
	cout << "\t\t                   -----------------------" << endl;
	cout << endl;
    
    cout << "\t\t         ------------------------------------------------" << endl;
	cout << "\t\t        | OUR CODE WILL DETERMINE THE TYPE OF RELATION  |" << endl;
	cout << "\t\t         ------------------------------------------------" << endl;
	cout << endl;
	
	setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    MatrixRelations matrixRelations(size);
    matrixRelations.inputMatrix();

    matrixRelations.displayRelations();
    matrixRelations.displayDirectedGraph();

    return 0;
}

