#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void countLetters(const string& str, int& L, int& D) {
    L = 0;
    D = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            L++;
        }
        if (isdigit(str[i])) {
            D++;
        }
    }
}

int main() {
    string text = "Число e 2.718";

    int letters = 0;
    int digits = 0;

    countLetters(text, letters, digits);

    cout << "Букв: " << letters << endl;
    cout << "Цифр: " << digits << endl;

    return 0;
}
