#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int rows, cols, n, mode;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

   
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Исходная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; 
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Введите n (сдвиг): ";
    cin >> n;
    cout << "Режим (1 - вправо, -1 - влево): ";
    cin >> mode;

    int size = rows * cols;
    n = n % size; 

   
    vector<int> arr(size);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i * cols + j] = matrix[i][j];

    
    vector<int> shifted(size);

    for (int i = 0; i < size; i++) {
        int newIndex;
        if (mode == 1) // вправо
            newIndex = (i + n) % size;
        else           // влево
            newIndex = (i - n + size) % size;
        shifted[newIndex] = arr[i];
    }

    
    cout << "\nМатрица после сдвига:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = shifted[i * cols + j];
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
