#ifndef WOAT_TRIANGLE_PROBLEM_TRIANGLE_H
#define WOAT_TRIANGLE_PROBLEM_TRIANGLE_H

#include <vector>

enum TriangleInitializationResult
{
    SUCCESS = 0,
    NOT_A_TRIANGLE,
    TOO_LARGE_SIDES
};

class Triangle
{
public:
    Triangle();
    TriangleInitializationResult Initialize(const std::vector<double> &sides);
    bool IsIsosceles();
    bool IsEquilateral();
    bool IsInitialized();
protected:
    bool m_isInitialized;
    double a, b, c;
};

#endif //WOAT_TRIANGLE_PROBLEM_TRIANGLE_H