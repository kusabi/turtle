#ifndef TURTLE_MATH_HPP
#define TURTLE_MATH_HPP

namespace Turtle
{
    class Math
    {
        public:
            constexpr static const float PI = 3.1415926;

            constexpr static const float Deg2Rad = (PI * 2) / 360;

            constexpr static const float Rad2Deg = 360 / (PI * 2);

            static float abs(float value);

            static float ceil(float value);

            static float clamp(float value, float min, float max);

            static float wrap(float value, float min, float max);

            static float pingPong(float value, float min, float max);

            static float floor(float value);

            static float max(float a, float b);

            static float min(float a, float b);
    };
}

#endif
