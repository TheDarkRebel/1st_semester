#include <iostream>

using namespace std;

void sum(double* ptr, const size_t& size) {
	double sum_elem = 0;
	bool start = false;
	for (size_t i = 0; i < size; i++) {
		if ((*(ptr + i) < 0) and not start) {
			start = true;
			continue;
		}
		if ((*(ptr + i) < 0) and start) break;
		if (start){ 
            sum_elem += *(ptr + i);
        }
	}
    cout << "Сумма между 1м и 2м отрицательными элементами: " << sum_elem << endl;
}



int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    double p = 0;
    cout << "Введите кол-во элементов в массиве: ";
    cin >> n;
    if (n < 3){
        cout << "Ошибка: введено слишком мало элементов!";
    }
    else{
        double *mass = new double[n];
        for(int i = 0; i < n; i++){
            cout << "Введите " << i << "-й элемент: " << endl;
            cin >> mass[i];
        }
        sum(mass, n);
        int o = 0, k;
        double *mas = new double[n];
        for (int i = 0; i < n; i++) {
            if (abs(mass[i]) < 0.9999) {
                mas[o] = mass[i];
                o++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (abs(mass[i]) > 0.9999) {
                mas[o] = mass[i];
                o++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << mas[i] << "   ";
        }
    }
    return 0;
}
