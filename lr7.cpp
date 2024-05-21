#include <iostream>

using namespace std;

int main() {
    setlocale(0, "rus");
    int n;
    cout << "Введите размерность квадратной матрицы: ";
    cin >> n;

    double** matrix = new double*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
    }

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Элемент[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    int firstNegativeRow = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < 0) {
                firstNegativeRow = i;
                break;
            }
        }
        if (firstNegativeRow != -1) {
            break;
        }
    }

    if (firstNegativeRow != -1) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (matrix[firstNegativeRow][j] < matrix[firstNegativeRow][j + 1]) {
                    double temp = matrix[firstNegativeRow][j];
                    matrix[firstNegativeRow][j] = matrix[firstNegativeRow][j + 1];
                    matrix[firstNegativeRow][j + 1] = temp;
                }
            }
        }

        cout << "Упорядоченная строка по убыванию: ";
        for (int j = 0; j < n; ++j) {
            cout << matrix[firstNegativeRow][j] << " ";
        }
        cout << endl;
    } else {
        cout << "Отрицательных элементов не найдено.\n";
    }

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}



#include <iostream>

using namespace std;

const int MAX_SIZE = 100; 

void insertionSort(double arr[], int n) {
    for (int i = 1; i < n; ++i) {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Введите размерность квадратной матрицы (не более " << MAX_SIZE << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        cout << "Некорректный размер матрицы.\n";
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE];

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Элемент[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; ++i) {
        int j = i;
        double diagonal[MAX_SIZE - i];
        
        while (j < n) {
            diagonal[j - i] = matrix[j][n - j - 1];
            ++j;
        }

        insertionSort(diagonal, n - i);

        j = i;
        for (int k = 0; k < n - i; ++k) {
            matrix[j][n - j - 1] = diagonal[k];
            ++j;
        }
    }

    cout << "Упорядоченная матрица по побочной диагонали:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
