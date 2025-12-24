#include <iostream>
#include <vector>
#include <string>
#include <locale> 

using namespace std;


bool isAlphabetical(const string& s) {
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] < s[i - 1]) return false;
    }
    return true;
}


bool isPalindromeColumn(const vector<string>& matrix, int col) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        if (matrix[i][col] != matrix[n - i - 1][col])
            return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    int n, m;
    cout << "Введите количество строк и столбцов: ";
    cin >> n >> m;

    vector<string> matrix(n);
    cout << "Введите строки матрицы:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i];
    }

    cout << "\nСтроки в алфавитном порядке:" << endl;
    for (int i = 0; i < n; ++i) {
        if (isAlphabetical(matrix[i])) {
            cout << matrix[i] << endl;
        }
    }

    cout << "\nСтолбцы-палиндромы:" << endl;
    for (int j = 0; j < m; ++j) {
        if (isPalindromeColumn(matrix, j)) {
            for (int i = 0; i < n; ++i) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
