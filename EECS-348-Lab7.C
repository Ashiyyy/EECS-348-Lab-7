#include <iostream>
#include <vector>

const int ROW = 4;
const int COL = 4;
int added[ROW][COL];
int multiply[ROW][COL];
int swap[ROW][COL];
int diag;
int reverse_diag;
class Matrices{
    private:
        std::vector<std::vector<int>> value;
    public:
        Matrices(int ROWs, int COLs): value(ROWs, std::vector<int>(COLs)){}

        int& operator()(int ROWs, int COLs){
            return value[ROWs][COLs];
        }

        //Adding matrices function with added array global variable
        Matrices operator+(int matrix2[ROW][COL]){
            for (int i = 0; i < ROW; i++){
                for (int x = 0; x < COL; x ++){
                    added[i][x] = (*this(i, x) + matrix2[i][x]);
                }
            }
        }

        //Multiply matrices function with multiply array global variable
        Matrices operator*(int matrix2[ROW][COL]){
            for (int i = 0; i < ROW; i++){
                for (int x = 0; x < COL; x++){
                    multiply[i][x] = 0;
                    for (int v = 0; v < ROW; v++){
                        //a11*b11 + a12*b21 + a13*b31...
                        //a21*b21 + a21*b21...
                        multiply[i][x] = (multiply(i, x) + (*this(i, v)*matrix2[v][x]));
                    }
                }
            }
        }

        //Swaps
        void swapMatrix(int matrix[ROW][COL], int row1, int row2){
            for (int j = 0; j < ROW; j++){
                for (int k = 0; k < COL; k++){
                    swap[j][k] = matrix[j][k];
                }
            }
            for (int i = 0; i < COL; i++){
                swap[row1][i] = matrix[row2][i];
                swap[row2][i] = matrix[row1][i];
            }
        }

        //Diagonal addition
        void diagMatrix(int matrix[ROW][COL]){
            int q = 0;
            for (int i = 0; i < ROW; i++){
                    for (int x = 0; x < COL; x++){
                        if (i == x){
                            diag = diag + matrix[i][x];
                        }
                        if (x == (COL - q)){
                            if (i == q){
                                reverse_diag = reverse_diag + matrix[i][x];
                                q = q + 1;
                            }
                        }
                    }
            }
        }

        //Formatting of printing matrices
        void printMatrix(int matrix1[ROW][COL]){
            std::cout << "\n";
            for (int i = 0; i < ROW; i++){
                for (int x = 0; x < COL; x ++){
                    std::cout << matrix1[i][x];
                    std::cout << "\t";
                }
                std::cout << "\n";
            }
        }
};



int main() {

        // User input rather than file
        //Input setup
        Matrices M;
        int m1[ROW][COL];
        int m2[ROW][COL];
        int row1;
        int row2;
        std::cout << "Please enter first Matrix";
        for (int i = 0; i < ROW; i++){
                for (int q = 0; q < COL; q++){
                    std::cout << "Please enter first matrix " << (i+1) << " row and " << (q+1) << " column number: ";
                    std::cin >> m1[i][q];
                }
            }
        std::cout << "\n";
        std::cout << "Please enter first Matrix";
        for (int i = 0; i < ROW; i++){
                for (int q = 0; q < COL; q++){
                    std::cout << "Please enter second matrix " << (i+1) << " row and " << (q+1) << " column number: ";
                    std::cin >> m1[i][q];
                }
            }
        std::cout << "Please enter your swap for row 1";
        std::cin >> row1;
        std::cout << "Please enter your swap for row 2";
        std::cin >> row2;


    /*File input
    //Input setup
    FILE *input_file = fopen("input_file.txt", "r");
    char* file_line = " ";
    for (int i = 0; i < 12; i++){
        fgets(file_line, 100, input_file);
        sales[i] = atof(file_line);
    }
    fclose(input_file);
    File input*/


//Printing section
    //Input file open to WRITE
    //FILE *output_file = fopen("output_file.txt", "w");

    //Matrices Added
    if (ROW == COL){  //If cols and rows of 1 match 2, add
        std::cout << "Matrices added: ";
        m1 + m2;
        M.printMatrix(m1 + m2);
        std::cout << "\n";
        std::cout << "\n";
    } else{
        std::cout << "Matrices cannot be added. Incompatible sizes";
        std::cout << "\n";
    }

    //Matrices Multiplied
    if (COL == ROW){  //If columns of 1 == rows of 2, multiply
        std::cout << "Matrices multiplied: ";
        m1 * m2;
        M.printMatrix(multiply);
        std::cout << "\n";
        std::cout << "\n";
    } else{
        std::cout << "Matrices cannot be multiplied. Incompatible sizes";
        std::cout << "\n";
    }

    //Matrix 1 swapped
    std::cout << "Matrix 1 swapped: ";
    M.swapMatrix(m1, row1, row2);
    M.printMatrix(swap);
    std::cout << "\n";
    std::cout << "\n";

    //Matrix 1 diagonal
    std::cout << "Matrix 1 diagonal sum: ";
    M.diagMatrix(m1);
    std::cout << diag;
    std::cout << "\n";
    std::cout << "\n";

    //Matrix 1 reverse diagonal
    std::cout << "Matrix 1 reverse diagonal sum: ";
    M.diagMatrix(m1);
    std::cout << reverse_diag;
    std::cout << "\n";
    std::cout << "\n";


    return 0;
}

