#include <iostream>
#include <string>

bool isDomainName(const std::string& str) {
    if (str.starts_with("www.") && str.ends_with(".com")) {
        return true;
    }
    return false;
}

int main()
{
    std::cout << isDomainName("www.google.com") << std::endl;
    std::cout << isDomainName("abc") << std::endl;
    std::cout << isDomainName("hello.com") << std::endl;
}
