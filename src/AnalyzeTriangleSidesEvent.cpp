#include "AnalyzeTriangleSidesEvent.h"

AnalyzeTriangleSidesEvent::AnalyzeTriangleSidesEvent(const std::vector<double> &sides, int winId, wxEventType eventType)
    : wxEvent(winId, eventType), m_sides(sides)
{ }

wxEvent* AnalyzeTriangleSidesEvent::Clone() const
{
    return new AnalyzeTriangleSidesEvent(*this);
}

double AnalyzeTriangleSidesEvent::GetSide(unsigned char sideNumber)
{
    if (sideNumber < m_sides.size())
    {
        return m_sides[sideNumber];
    }
    else
    {
        return 0;
    }
}
