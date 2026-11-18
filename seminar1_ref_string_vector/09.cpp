#include <iostream>
#include <string>

using namespace std;

string repeat(int n) {
    string s = to_string(n);
    string res = "";
    for (int i = 0; i < n; i++) {
        res = res + s;
    }
    return res;
}

int main()
{
    cout << repeat(5) << endl;
    cout << repeat(10) << endl;
    cout << repeat(-1) << endl;
}
