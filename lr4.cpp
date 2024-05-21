//Задание 1
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double x, y;
    x = -1;
    cout << setw(15) << "x" << setw(15) << "f(x)" << endl;
    while(x >= -1 and x <= 3){
        if(x < 0){
            y = -x;
            cout << setw(15) << x << setw(15) << y << endl;
        }
        if(x <= 1 and x >= 0){
            y = cos(x);
            cout << setw(15) << x << setw(15) << y << endl;
        }
        if(x >= 1){
            y = x * x - 1;
            cout << setw(15) << x << setw(15) << y << endl;
        }
        x += 0.25;
    }
    return 0;
}



//Задание 2
#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    int n = 0, x = 0, y = 0;
    cout << "Введите размер массива: ";
    cin >> n;
    int mass[n], i;
    for(i = 0; i < n; i++){
        cout << "Введите " << i << " элемент массива" << "\n";
        cin >> mass[i];
    }
    while(x != n){
        if(mass[0] < mass[x]){
            y++;
            x++;
        }
        else x++;
    }
    cout << "Количество чисел больше первого: " << y;
    return 0;
}


//Задание 3
#include <iostream>

using namespace std;

void func(int x){
    int p = 1;
    while(x > 0){
        p *= x % 10;
        x /= 10;
    }
    cout << "Произведение цифр: " << p;
}


int main(){
    setlocale(LC_ALL, "RUS");
     int n = 0, x = 0, y = 0;
    cout << "Введите размер массива: ";
    cin >> n;
    int mass[n], i;
    for(i = 0; i < n; i++){
        cout << "Введите " << i << " элемент массива" << "\n";
        cin >> mass[i];
    }
     for(i = 0; i < n; i++){
        if(mass[i] % 3 == 0){
            func(mass[i]);
            break;
        }
    }
    return 0;
}
