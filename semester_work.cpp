//1
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int a, b, c;
	double x;
	cout << "Введите a - "; cin >> a; //Первое число
	cout << "Введите b - "; cin >> b; //Второе число
	cout << "Введите c - "; cin >> c; //Третье число
	x = pow(a * b * c, 1.0 / 3);   //Вычисление среднего арифметического
	cout << "Дробная часть - " << (x - int(x)) << "\n";
	return 0;
}



//2
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	bool a;
	double x, y;
	cout << "Введите координаты точки x и y \n";
	cout << "Введите х: \n";
	cin >> x;					//Ввод координаты х
	cout << "Введите y: \n";
	cin >> y;					//Ввод координаты у
	if (((0 <= y and y <= 1) and (-2 <= x and x <= 0)) or (y == 1 - x) or (y == -1 + x)) {			//Проверка на вхождение в область
		a = true;
		cout << boolalpha << a;
	}
	else {
		a = false;
		cout << boolalpha << a;
	}
	return 0;
}



//7

#include <iostream>
#include <math.h>
using namespace std;

double func(double a, int m) {
	if (m < 0) {                             //n меньше нуля
		cout << (1 / pow(a, -m));
		return 0;
	}
	if (m > 0) {									 //n больше нуля
		cout << (pow(a, 2 * m));
		return 0;
	}
	if (m == 0) {								 //n равен нулю
		cout << 1;
		return 0;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Введите значения x и n\n";
	double x;
	int n;
	cout << "Введите х: \n";
	cin >> x;						//Ввод первого числа
	cout << "Введите n: \n";
	cin >> n;							//Ввод второго числа
	func(x, n);
	return 0;
}



//3
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  setlocale(LC_ALL, "Russian");
  const double eps = 0.00000001;
  double x, y = 0, z = 1;
  int n;
  cout << "Введите x: ";
  cin >> x;							//Вводится нужное значение х
  if (x <= 0.5) {
      cout << "Введено слишком маленькое число!";
  }
  else {
      for (n = 1; n > 0; n++) {
          if (abs(z) < eps) {					//Выполняется сравнение с эпсилон
              break;
          }
          else {
              z = 0;
              y += (pow((x - 1), n)) / n * pow(x, n); //Вычисляется сумма бесконечного ряда
              z += y;
          }
      }
      cout << "Полученное значение: " << y << "\n";
      cout << "ln(x) = " << log(x);
  }
  return 0;
}

//6
#include <iostream>
#include <string>
#include <windows.h>


using namespace std;


int main() {
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   string text;
   cout << "Введите строку: ";
   getline(cin, text);

   size_t lastSpace = text.find_last_of(" ");         // Находим последнее слово
   string lastWord = text.substr(lastSpace + 1);

   size_t start = 0;               // Проходимся по словам, отличным от последнего, и заменяем первую букву
   size_t end = text.find(" ");
   while (end != -1) {
       string word = text.substr(start, end - start);
       setlocale(0, "rus");
       if (word != lastWord) {
           word[0] = toupper(word[0]);
           cout << word << " ";
       }

       start = end + 1;                    // Обновляем индексы для следующего слова
       end = text.find(" ", start);
   }
   return 0;
}

//5

#include <iostream>

void sum(int** mass, int count) {
   for (int sum, i = 0; i < count; i++) {
       sum = 0;
       for (int j = 0; j < count; j++) {
           if (mass[j][i]) {
               sum += mass[j][i];
           }
       }
       if (sum) {
           std::cout << "Summ of " << i + 1 << " column = " << sum << std::endl;
       }
   }
}

int main() {
   int N;
   setlocale(0, "rus");
   // Вводим размерность матрицы
   std::cout << "Введите размерность матрицы N: ";
   std::cin >> N;

   // Проверяем корректность ввода
   if (N <= 0) {
       std::cout << "Некорректный размер матрицы.\n";
       return 1;
   }

   // Выделяем память для матрицы и сумм столбцов
   int** matrix = new int* [N];
   for (int i = 0; i < N; ++i) {
       matrix[i] = new int[N];
   }

   int* columnSums = new int[N]();

   std::cout << "Введите элементы матрицы A(" << N << "x" << N << "):\n";
   for (int i = 0; i < N; ++i) {
       for (int j = 0; j < N; ++j) {
           std::cin >> matrix[i][j];
           columnSums[j] += matrix[i][j];
       }
   }

   std::cout << "Матрица:\n";
   for (int i = 0; i < N; ++i) {
       for (int j = 0; j < N; ++j) {
           std::cout << matrix[i][j] << " ";
       }
       std::cout << "\n";
   }

   // Сортируем столбцы по убыванию сумм их элементов
   int* columnIndices = new int[N];
   for (int i = 0; i < N; ++i) {
       columnIndices[i] = i;
   }

   for (int i = 0; i < N - 1; ++i) {
       for (int j = i + 1; j < N; ++j) {
           if (columnSums[columnIndices[i]] < columnSums[columnIndices[j]]) {
               std::swap(columnIndices[i], columnIndices[j]);
           }
       }
   }

   sum(matrix, N);

   // Выводим результат, переставляя столбцы в новом порядке
   std::cout << "Новая матрица (столбцы в порядке убывания сумм их элементов):\n";
   for (int i = 0; i < N; ++i) {
       for (int j = 0; j < N; ++j) {
           std::cout << matrix[i][columnIndices[j]] << " ";
       }
       std::cout << "\n";
   }


   // Освобождаем выделенную память
   for (int i = 0; i < N; ++i) {
       delete[] matrix[i];
   }
   delete[] matrix;
   delete[] columnSums;
   delete[] columnIndices;

   return 0;
}

//4
#include <iostream>

using namespace std;

int* sort(int num[], int n) {   // Функция сортировки элементов по четному и нечетному номеру в массиве
   int p = 0;
   int* mas = new int[n];  

   for (int i = 0; i < n; i++) {   // Ввод в массив чисел, находящихся на четных номерах
       if (i % 2 == 0) {
           mas[p] = num[i];
           p++;
       }
   }

   for (int i = 0; i < n; i++) {   // Ввод в массив чисел, находящихся на нечетных номерах
       if (i % 2 != 0) {
           mas[p] = num[i];
           p++;
       }
   }

   return mas;
}

int main() {
   setlocale(LC_ALL, "RUS");

   int n;
   cout << "Введите размер массива: ";
   cin >> n;

   int* mass1 = new int[n];  

   for (int i = 0; i < n; i++) {
       cout << "Введите " << i << "-й элемент" << endl;
       cin >> mass1[i];
   }

   int min = abs(mass1[0]);

   for (int i = 1; i < n; i++) {
       if (abs(mass1[i]) < min) {  // Нахождение минимального элемента в массиве
           min = abs(mass1[i]);
       }
   }

   cout << "Минимальный элемент: " << min << endl;

   int sum = 0;

   for (int i = 0; i < n; i++) {   // Нахождение суммы модулей элементов массива
       if (mass1[i] == 0) {
           for (int l = i; l < n; l++) {
               sum += abs(mass1[l]);
           }
           break;
       }
   }

   cout << "Сумма модулей элементов: " << sum << endl;

   int* sortedArray = sort(mass1, n);

   cout << "Отсортированный массив: ";
   for (int i = 0; i < n; i++) {
       cout << sortedArray[i] << "  ";
   }

   delete[] mass1;  // Освобождаем память, выделенную для массивов
   delete[] sortedArray;

   return 0;
}
