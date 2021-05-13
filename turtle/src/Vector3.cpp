#include "../include/Vector3.hpp"

#include <cmath>

namespace Turtle
{
    Vector3::Vector3()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vector3::Vector3(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3 &Vector3::normalise()
    {
        return (*this) /= this->length();
    }

    Vector3 Vector3::normalised() const
    {
        return *this / this->length();
    }

    float Vector3::length() const
    {
        return std::sqrt((x * x) + (y * y) + (z * z));
    }

    Vector3 Vector3::operator+(const Vector3 &other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vector3 Vector3::operator-(const Vector3 &other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vector3 Vector3::operator*(const Vector3 &other) const
    {
        return {x * other.x, y * other.y, z * other.z};
    }

    Vector3 Vector3::operator/(const Vector3 &other) const
    {
        return {x / other.x, y / other.y, z / other.z};
    }

    Vector3 Vector3::operator*(float amount) const
    {
        return {x * amount, y * amount, z * amount};
    }

    Vector3 Vector3::operator/(float amount) const
    {
        return {x / amount, y / amount, z / amount};
    }

    Vector3 &Vector3::operator+=(const Vector3 &other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Vector3 &Vector3::operator-=(const Vector3 &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }

    Vector3 &Vector3::operator*=(const Vector3 &other)
    {
        this->x *= other.x;
        this->y *= other.y;
        this->z *= other.z;
        return *this;
    }

    Vector3 &Vector3::operator/=(const Vector3 &other)
    {
        this->x /= other.x;
        this->y /= other.y;
        this->z /= other.z;
        return *this;
    }

    Vector3 &Vector3::operator*=(float amount)
    {
        this->x *= amount;
        this->y *= amount;
        this->z *= amount;
        return *this;
    }

    Vector3 &Vector3::operator/=(float amount)
    {
        this->x /= amount;
        this->y /= amount;
        this->z /= amount;
        return *this;
    }
}