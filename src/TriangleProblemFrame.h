#ifndef WOAT_TRIANGLE_PROBLEM_TRIANGLEPROBLEMFRAME_H
#define WOAT_TRIANGLE_PROBLEM_TRIANGLEPROBLEMFRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <vector>
#include "AnalyzeTriangleSidesEvent.h"

class TriangleProblemFrame : public wxFrame
{
public:
    TriangleProblemFrame(const wxString &title, int gap = 5, int border = 5);
protected:
    void OnAnalyzeTrianlgeClick(wxEvent &event);
    void OnAnalyze(AnalyzeTriangleSidesEvent &event);

    std::vector<wxTextCtrl *> m_sideSizeFields;
};

#endif //WOAT_TRIANGLE_PROBLEM_TRIANGLEPROBLEMFRAME_H
