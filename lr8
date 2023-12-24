#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int sized_text = 0;
    string text;
    string exitText;

    cout << "Введите текст: \n";
    getline(cin, text);
    sized_text = text.size();

    for (int i = 0; i < sized_text; i++) {
        if (text[i] == '"' && text[i + 1] != ' ') {
            for (int j = i; j < sized_text; j++) {
                exitText += text[j];
                if (text[j + 1] == '"') {
                    exitText += text[j + 1];
                    break;
                }
            }
            exitText += " ";
        }
    }

    cout << exitText;
    return 0;
}
