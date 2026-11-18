#include <iostream>
#include <string>

struct Book{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& book){
    if(book.price > 1000) return true;
    else return false;
}

int main(){
    Book a;
    a.price = 500;

    Book b;
    b.price = 1500;

    std::cout << isExpensive(a) << " " << isExpensive(b) << std::endl;
}
