#pragma once
#include <iostream>

class Vector2f
{
private:
    float x;
    float y;

public:
    Vector2f() {
        x = 0;
        y = 0;
    }

    Vector2f(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vector2f(const Vector2f& vector) {
        this->x = vector.x;
        this->y = vector.y;
    }

    float getX() const { return x; }
    float getY() const { return y; }
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    Vector2f operator+(const Vector2f& vector) const {
        return Vector2f(x + vector.x, y + vector.y);
    }

    Vector2f operator-(const Vector2f& vector) const {
        return Vector2f(x - vector.x, y - vector.y);
    }

    Vector2f operator*(float p) const {
        return Vector2f(x * p, y * p);
    }

    float operator*(const Vector2f& vector) const {
        return x * vector.x + y * vector.y;
    }

    Vector2f operator-() const {
        return Vector2f(-x, -y);
    }

    Vector2f operator+() const {
        return *this;
    }

    bool operator==(const Vector2f& vector) const {
        return (x == vector.x) && (y == vector.y);
    }

    bool operator!=(const Vector2f& vector) const {
        return !(*this == vector);
    }

    Vector2f& operator+=(const Vector2f& vector) {
        x += vector.x;
        y += vector.y;
        return *this;
    }

    Vector2f& operator-=(const Vector2f& vector) {
        x -= vector.x;
        y -= vector.y;
        return *this;
    }

    Vector2f& operator*=(float p) {
        x *= p;
        y *= p;
        return *this;
    }

    Vector2f& operator/=(float p) {
        x /= p;
        y /= p;
        return *this;
    }
};

Vector2f operator*(float p, const Vector2f& v) {
    return v * p;
}

std::ostream& operator<<(std::ostream& out, const Vector2f& v) {
    out << "(" << v.getX() << ", " << v.getY() << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2f& v) {
    float x, y;
    in >> x >> y;
    v.setX(x);
    v.setY(y);
    return in;
}
