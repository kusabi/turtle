#ifndef TURTLE_VECTOR2_HPP
#define TURTLE_VECTOR2_HPP

namespace Turtle
{
    class Vector2
    {
        public:
            float x = 0.0f;
            float y = 0.0f;

            Vector2();

            Vector2(float, float);

            float length() const;

            Vector2 &normalise();

            Vector2 normalised() const;

            Vector2 operator+(const Vector2 &other) const;

            Vector2 operator-(const Vector2 &other) const;

            Vector2 operator*(const Vector2 &other) const;

            Vector2 operator/(const Vector2 &other) const;

            Vector2 operator*(float amount) const;

            Vector2 operator/(float amount) const;

            Vector2 &operator+=(const Vector2 &other);

            Vector2 &operator-=(const Vector2 &other);

            Vector2 &operator*=(const Vector2 &other);

            Vector2 &operator/=(const Vector2 &other);

            Vector2 &operator*=(float amount);

            Vector2 &operator/=(float amount);
    };
}


#endif
