#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    cout << "Введите x и y: " << endl;
    int x, y;
    cout << "Введите x: \n";
    cin >> x;
    cout << "Введите y: \n";
    cin >> y;
    if(x * y > 100){
        x = 2*(x*x*x);
        y = y/2;
    }
    cout << "Первое число: " << x << endl;
    cout << "Второе число: " << y << endl;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    int a,b,c,k,m;
    const double e = 2.71828182845904;
    double y;
    cout << "Введите а: \n";
    cin >> a;
    cout << "Введите b: \n";
    cin >> b;
    cout << "Введите c: \n";
    cin >> c;
    cout << "Введите k (Допустимые значения - 0, 1, 2): \n";
    cin >> k;
    if(k == 1 or k == 2 or k == 0){
        m = (a + pow(b, 2))/c;
        if(k == 0){
            y = pow(e,m+c);
            cout << "Ответ: " << y;
        }
        if(k == 1){
            y = log(a/b);
            cout << "Ответ: " << y;
        }
        if(k == 2){
            y = pow(a+b, 2) + c;
            cout << "Ответ: " << y;
        }
    }
    else{
        cout << "Введено некорректное число";
    }
    return 0;
}

#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    tm now;
    time_t t;
    time(&t);
    localtime_r(&t, &now);
    cout << "Дата: ";
    cout << setw(2) << setfill('0') << now.tm_year + 1900 << ":" << setw(2) << now.tm_mon << ":" << setw(2) << now.tm_mday << ":" << setw(2) << now.tm_wday << "\n";
    return 0;
}
