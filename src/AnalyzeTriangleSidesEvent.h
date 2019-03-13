#ifndef WOAT_TRIANGLE_PROBLEM_ANALYZETRIANGLESIDESEVENT_H
#define WOAT_TRIANGLE_PROBLEM_ANALYZETRIANGLESIDESEVENT_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <vector>

class AnalyzeTriangleSidesEvent : public wxEvent
{
public:
    AnalyzeTriangleSidesEvent(const std::vector<double> &sides, int winId = 0, wxEventType eventType = wxEVT_NULL);
    double GetSide(unsigned char sideNumber);
    virtual wxEvent *Clone() const;
protected:
    const std::vector<double> m_sides;
};

#endif //WOAT_TRIANGLE_PROBLEM_ANALYZETRIANGLESIDESEVENT_H
