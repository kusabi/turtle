#include "../include/Math.hpp"

#include <cmath>

namespace Turtle
{
    float Math::abs(float value)
    {
        return std::abs(value);
    }

    float Math::ceil(float value)
    {
        return std::ceil(value);
    }

    float Math::clamp(float value, float min, float max)
    {
        return Math::min(max, Math::max(min, value));
    }

    float Math::wrap(float value, float min, float max)
    {
        // @todo make this better
        return min + std::fmod(value - min, max - min);
    }

    float Math::pingPong(float value, float min, float max)
    {
        // @todo Clean this method up
        float range = max - min;
        if (value > max) {
            float overBy = value - max;
            int wrappedTimes = (int) (overBy / range);
            float mod = std::fmod(overBy, range);
            if (fmod(wrappedTimes, 2) == 0) {
                return max - mod;
            } else {
                return min + mod;
            }
        } else if (value < min) {
            float underBy = min - value;
            int wrappedTimes = (int) (underBy / range);
            float mod = std::fmod(underBy, range);
            if (fmod(wrappedTimes, 2) == 0) {
                return min + mod;
            } else {
                return max - mod;
            }
        } else {
            return value;
        }
    }

    float Math::floor(float value)
    {
        return std::floor(value);
    }

    float Math::max(float a, float b)
    {
        return std::fmax(a, b);
    }

    float Math::min(float a, float b)
    {
        return std::fmin(a, b);
    }
}