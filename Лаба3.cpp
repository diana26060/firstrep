#include <iostream>
#include <vector>
#include <limits>
using namespace std;
//функция для ввода матрицы и проверки правильности ввода 
int inputMatrxSize(){
    int size;
    do{
        cout<<"Enter size of matrix(from 1 to 10): "<<endl;
        cin>>size;
    }
    while(size<1 || size>10);
    return size;
}
// функция для ввода элементов матрицы с консоли
void inputMatrixElements(vector<vector<int>>& matrix, int size) {
    cout << "Enter elements of matrix :" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout<<"Element ["<<i<<"]["<<j<<"]: ";
            cin>>matrix[i][j];
        }
    }
}

// функция для инициализации матрицы, если i+j нечетное число
void inicializeMatrix(vector<vector<int>>& matrix, int size){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            matrix[i][j] = ((i+j)% 2 != 0) ? 1: 0;
        }
    }
}

// функция для вывода матрицы
void printMatrix(const vector<vector<int>>& matrix, int size) {
    cout << "Matrix: " << endl;
    for (int i = 0; i<size; ++i) {
        for (int j = 0; j<size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// функция для вычисления суммы элементов в строках, не содержащих нулей
int sumRowsWithoutZero(const vector<vector<int>>& matrix, int size) {
    int totalSum = 0;
    for (int i = 0; i<size; ++i) {
        bool hasZero = false;
        int rowSum = 0;
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
            rowSum += matrix[i][j];
        }
        if (!hasZero) {
            totalSum += rowSum;
        }
    }
    return totalSum;
}

int maxProductOfDiagonals(const vector<vector<int>>&matrix, int size){
    int maxProduct = numeric_limits<int>::min();


// Верхние диагонали
    for (int startCol = 1; startCol<size; ++startCol) {
        int product = 1;
        for (int i = 0, j = startCol; j<size; ++i, ++j) {
            product *= matrix[i][j];
        }
        if (product>maxProduct) {
            maxProduct = product;
        }
    }

    // Нижние диагонали
    for (int startRow = 1; startRow<size; ++startRow) {
        int product = 1;
        for (int i = startRow, j = 0; i<size; ++i, ++j) {
            product *= matrix[i][j];
        }
        if (product>maxProduct) {
            maxProduct = product;
        }
    }

    return maxProduct;

}

int main(){
    
    int size = inputMatrxSize();
    vector<vector<int>> matrix(size,vector<int>(size));

    inputMatrixElements(matrix,size);
    inicializeMatrix(matrix,size);
    printMatrix(matrix,size);
    int sum = sumRowsWithoutZero(matrix,size);
    cout<<"Sum of elements in rows without zeros: "<<sum<<endl;

    int maxProduct = maxProductOfDiagonals(matrix,size);
    cout<<"Max product of parallel diagonals: "<<maxProduct<<endl;
    return 0;
}