#include "Triangle.h"
#include <cfenv>

Triangle::Triangle() : m_isInitialized(false)
{ }

TriangleInitializationResult Triangle::Initialize(const std::vector<double> &sides)
{
    const unsigned long sidesSize = sides.size();
    m_isInitialized = false;
    if (sidesSize != 3)
    {
        return NOT_A_TRIANGLE;
    }

    for (const double &side : sides)
    {
        if (side <= 0)
        {
            return NOT_A_TRIANGLE;
        }
    }

    double tempResult;
    for (unsigned long i = 0; i < sidesSize; ++i)
    {
        for (unsigned long j = i + 1; j < sidesSize; ++j)
        {
            std::feclearexcept(FE_UNDERFLOW);
            tempResult = sides[i] + sides[j];

            if (std::fetestexcept(FE_UNDERFLOW))
            {
                return TOO_LARGE_SIDES;
            }

            if (tempResult <= sides[sidesSize - i - j])
            {
                return NOT_A_TRIANGLE;
            }
        }
    }

    a = sides[0];
    b = sides[1];
    c = sides[2];
    m_isInitialized = true;

    return SUCCESS;
}

bool Triangle::IsInitialized()
{
    return m_isInitialized;
}

bool Triangle::IsEquilateral()
{
    return m_isInitialized && (a == b) && (a == c);
}

bool Triangle::IsIsosceles()
{
    return m_isInitialized && ((a == b) || (a == c) || (b == c));
}
