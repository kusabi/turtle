#include "../include/Vector2.hpp"

#include <cmath>

namespace Turtle
{
    Vector2::Vector2()
    {
        this->x = 0;
        this->y = 0;
    }

    Vector2::Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    Vector2 &Vector2::normalise()
    {
        return (*this) /= this->length();
    }

    Vector2 Vector2::normalised() const
    {
        return *this / this->length();
    }

    float Vector2::length() const
    {
        return std::sqrt((x * x) + (y * y));
    }

    Vector2 Vector2::operator+(const Vector2 &other) const
    {
        return {x + other.x, y + other.y};
    }

    Vector2 Vector2::operator-(const Vector2 &other) const
    {
        return {x - other.x, y - other.y};
    }

    Vector2 Vector2::operator*(const Vector2 &other) const
    {
        return {x * other.x, y * other.y};
    }

    Vector2 Vector2::operator/(const Vector2 &other) const
    {
        return {x / other.x, y / other.y};
    }

    Vector2 Vector2::operator*(float amount) const
    {
        return {x * amount, y * amount};
    }

    Vector2 Vector2::operator/(float amount) const
    {
        return {x / amount, y / amount};
    }

    Vector2 &Vector2::operator+=(const Vector2 &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Vector2 &Vector2::operator-=(const Vector2 &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Vector2 &Vector2::operator*=(const Vector2 &other)
    {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    Vector2 &Vector2::operator/=(const Vector2 &other)
    {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }

    Vector2 &Vector2::operator*=(float amount)
    {
        this->x *= amount;
        this->y *= amount;
        return *this;
    }

    Vector2 &Vector2::operator/=(float amount)
    {
        this->x /= amount;
        this->y /= amount;
        return *this;
    }
}