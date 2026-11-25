#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Number 
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

public:
    Number() 
    {
        capacity = 1;
        size = 1;
        data = new char[capacity];
        data[0] = 0;
    }

    Number(int a) 
    {
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        if (capacity == 0) 
            capacity = 1;

        data = new char[capacity];

        for (std::size_t i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        size = capacity;
    }

    Number(const Number& other) 
    {
        capacity = other.capacity;
        size = other.size;
        data = new char[capacity];

        for (std::size_t i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
    }

    Number(const std::string& str) 
    {
        if (str.empty()) 
        {
            capacity = 1;
            size = 1;
            data = new char[capacity];
            data[0] = 0;
            return;
        }

        std::size_t len = str.size();
        capacity = (len + 1) / 2;
        size = capacity;
        data = new char[capacity];

        for (std::size_t i = 0; i < capacity; ++i) 
        {
            int num = 0;
            int mult = 1;
            for (int j = 0; j < 2; ++j) 
            {
                int index = len - 1 - i * 2 - j;
                if (index >= 0) 
                {
                    num += (str[index] - '0') * mult;
                    mult *= 10;
                }
            }
            data[i] = num;
        }

        while (size > 1 && data[size - 1] == 0) 
        {
            size--;
        }
    }

    Number& operator=(const Number& other) 
    {
        if (this == &other) 
            return *this;

        delete[] data;

        capacity = other.capacity;
        size = other.size;
        data = new char[capacity];
        for (std::size_t i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    bool operator==(const Number& other) const 
    {
        if (size != other.size)
            return false;

        for (std::size_t i = 0; i < size; ++i) 
        {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Number& other) const 
    {
        return !(*this == other);
    }

    bool isEven() const 
    {
        if (data[0] % 2 == 0)
            return true;
        else
            return false;
    }

    Number operator+(const Number& other) const 
    {
        Number result;
        std::size_t max_len;
        if (size > other.size)
            max_len = size;
        else
            max_len = other.size;

        result.size = max_len + 1;
        result.capacity = result.size;
        delete[] result.data;
        result.data = new char[result.capacity];

        int perenos = 0;
        for (std::size_t i = 0; i < result.size; ++i) 
        {
            int sum = perenos;
            if (i < size) 
                sum += data[i];
            if (i < other.size) 
                sum += other.data[i];

            result.data[i] = sum % base;
            perenos = sum / base;
        }

        if (result.data[result.size - 1] == 0) 
            result.size--;

        return result;
    }

    Number& operator+=(const Number& other) 
    {
        *this = *this + other;
        return *this;
    }

    Number operator*(const Number& other) const 
    {
        Number result;
        result.size = size + other.size;
        result.capacity = result.size;
        delete[] result.data;
        result.data = new char[result.capacity];

        for (std::size_t i = 0; i < result.size; ++i) 
            result.data[i] = 0;

        for (std::size_t i = 0; i < size; ++i) 
        {
            int perenos = 0;
            for (std::size_t j = 0; j < other.size; ++j) 
            {
                int temp = data[i] * other.data[j] + result.data[i + j] + perenos;
                result.data[i + j] = temp % base;
                perenos = temp / base;
            }
            if (perenos > 0) 
                result.data[i + other.size] += perenos;
        }

        while (result.size > 1 && result.data[result.size - 1] == 0) 
            result.size--;

        return result;
    }

    Number& operator*=(const Number& other) 
    {
        *this = *this * other;
        return *this;
    }

    ~Number() 
    {
        delete[] data;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    stream << static_cast<int>(num.data[num.size - 1]);

    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}

Number fibonacci(int n) 
{
    if (n == 0) return Number(0);
    if (n == 1) return Number(1);

    Number first(0);
    Number second(1);
    Number next;

    for (int i = 2; i <= n; ++i) 
    {
        next = first + second;
        first = second;
        second = next;
    }
    return second;
}

Number factorial(int n) 
{
    Number answer(1);
    for (int i = 2; i <= n; ++i) 
    {
        answer *= Number(i);
    }
    return answer;
}
