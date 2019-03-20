#ifndef WOAT_TRIANGLE_PROBLEM_TRIANGLE_H
#define WOAT_TRIANGLE_PROBLEM_TRIANGLE_H

#include <vector>

enum TriangleInitializationResult
{
    SUCCESS = 0,
    NOT_A_TRIANGLE,
    TOO_LARGE_SIDES
};

enum TriangleType
{
    SCALENE,
    ISOSCELES,
    EQUILATERAL
};

class Triangle
{
public:
    Triangle();
    TriangleInitializationResult Initialize(const std::vector<unsigned long long> &sides);
    bool IsIsosceles();
    bool IsEquilateral();
    bool IsInitialized();
    TriangleType GetType();
protected:
    bool m_isInitialized;
    unsigned long long m_a, m_b, m_c;
};

#endif //WOAT_TRIANGLE_PROBLEM_TRIANGLE_H
