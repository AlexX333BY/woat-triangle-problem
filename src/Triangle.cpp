#include <cstddef>
#include <climits>
#include "Triangle.h"
#include <stdexcept>

Triangle::Triangle() : m_isInitialized(false)
{ }

TriangleInitializationResult Triangle::Initialize(const std::vector<unsigned long long> &sides)
{
    const size_t sidesSize = sides.size();
    m_isInitialized = false;
    if (sidesSize != 3)
    {
        return NOT_A_TRIANGLE;
    }

    for (const unsigned long long &side : sides)
    {
        if (side <= 0)
        {
            return NOT_A_TRIANGLE;
        }
    }

    for (size_t i = 0; i < sidesSize; ++i)
    {
        for (size_t j = i + 1; j < sidesSize; ++j)
        {
            if (sides[i] > ULLONG_MAX - sides[j])
            {
                return TOO_LARGE_SIDES;
            }

            if ((sides[i] + sides[j]) <= sides[sidesSize - i - j])
            {
                return NOT_A_TRIANGLE;
            }
        }
    }

    m_a = sides[0];
    m_b = sides[1];
    m_c = sides[2];
    m_isInitialized = true;

    return SUCCESS;
}

bool Triangle::IsInitialized()
{
    return m_isInitialized;
}

bool Triangle::IsEquilateral()
{
    return m_isInitialized && (m_a == m_b) && (m_a == m_c);
}

bool Triangle::IsIsosceles()
{
    return m_isInitialized && ((m_a == m_b) || (m_a == m_c) || (m_b == m_c));
}

TriangleType Triangle::GetType()
{
    if (!m_isInitialized)
    {
        throw std::logic_error("m_isInitialized");
    }

    if (IsEquilateral())
    {
        return EQUILATERAL;
    }
    else if (IsIsosceles())
    {
        return ISOSCELES;
    }
    else
    {
        return SCALENE;
    }
}
