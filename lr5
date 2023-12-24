#include <iostream>
#include <windows.h>

using namespace std;

string month[12] = {"январь" , "февраль", "март", "апрель", "май", "июнь", "июль", "август", 
"сентябрь", "октябрь", "ноябрь", "декабрь"};

int d[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void func(){
    char m[13] = {"Январь"};
    int mon, day, s;
    cout << "Введите дату: \nдень";
    cin >> day;
    cout << "\nмесяц(номер) ";
    cin >> mon;
    if(d[mon - 1] < day && (mon != 2 && day != 29))
        cout << "\nВведенная дата не верна";
    else{
        s = 0;
        for(int i = 1; i < mon; i++)
            s += d[i - 1];
            s += day;
            if(mon > 2)
                cout << "\nЭтот день " << s << "-й в обычном году и " << s + 1 << "-й в високосном";
            else
                cout << "\nЭтот день " << s << "-й в году ";
    }
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i;
    for(i = 0; i < 12; i++)
        cout << "Месяц " << month[i] << " --- " << d[i] << "день\n";
    func();
    return 0;
}
