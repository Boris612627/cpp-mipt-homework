#include <iostream>
#include "number.hpp"

using namespace std;

int main() 
{
    Number a;
    Number b = "12345678";
    Number c(b);
    a = c;
    a += b;
    cout << "a + b = " << a + b << endl;

    cout << endl << "F(1000) = " << fibonacci(1000) << endl;

    cout << endl << "12345678 isEven: " << b.isEven() << endl;
    cout << "12345679 isEven: " << (b + Number(1)).isEven() << endl;

    Number x(12);
    Number y(34);
    Number big_num("99999999999999999999");
    cout << endl << "x * y = " << x * y << endl;
    cout << "big_num * x = " << big_num * x << endl;
    cout << "big_num * big_num = " << big_num * big_num << endl;

    cout << endl << "1000! = " << factorial(1000) << endl;

    return 0;
}
