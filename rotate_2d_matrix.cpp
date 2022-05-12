#include <iostream>
#include <vector>
#include <string>

void printMatrix (std::vector<std::vector<int> >& matrix) {
    int n = matrix[0].size();

    std::string border = "";

    for (int i = 0; i < n; i++) {
        border += "----";
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) std::cout << border << std::endl;
        for (int j = 0; j < n; j++) {
            std::string correctedSpace = matrix[i][j] > 9 ? "" : " ";
            std::cout << " " << matrix[i][j] << correctedSpace << " |";
        }
        std::cout << std::endl;
    }
    std::cout << border << std::endl;
}

void rotateMatrix (std::vector<std::vector<int> >& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                std::swap(matrix[a][a+i], matrix[a+i][b]);
                std::swap(matrix[a][a+i], matrix[b][b-i]);
                std::swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
}

int main () {

    int m = 20;

    std::vector<std::vector<int> > matrix (m, std::vector<int>(m));
    int n = matrix[0].size();
    int count = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = count++;
            //            std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << std::endl;
        }
    }

    printMatrix(matrix);
    rotateMatrix(matrix);
    rotateMatrix(matrix);
    printMatrix(matrix);

    return 0;
}
