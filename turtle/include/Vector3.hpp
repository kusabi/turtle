#ifndef TURTLE_VECTOR3_HPP
#define TURTLE_VECTOR3_HPP

namespace Turtle
{
    class Vector3
    {
        public:
            float x = 0.0f;
            float y = 0.0f;
            float z = 0.0f;

            Vector3();

            Vector3(float, float, float);

            float length() const;

            Vector3 &normalise();

            Vector3 normalised() const;

            Vector3 operator+(const Vector3 &other) const;

            Vector3 operator-(const Vector3 &other) const;

            Vector3 operator*(const Vector3 &other) const;

            Vector3 operator/(const Vector3 &other) const;

            Vector3 operator*(float amount) const;

            Vector3 operator/(float amount) const;

            Vector3 &operator+=(const Vector3 &other);

            Vector3 &operator-=(const Vector3 &other);

            Vector3 &operator*=(const Vector3 &other);

            Vector3 &operator/=(const Vector3 &other);

            Vector3 &operator*=(float amount);

            Vector3 &operator/=(float amount);
    };
}

#endif
