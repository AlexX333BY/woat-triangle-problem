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
    void OnAnalyzeClick(wxCommandEvent &event);
    void OnAnalyze(AnalyzeTriangleSidesEvent &event);

    std::vector<wxTextCtrl *> m_sideSizeFields;
    wxPanel *m_panel;

    const int m_analyzeButtonId = wxID_OK;
};

#endif //WOAT_TRIANGLE_PROBLEM_TRIANGLEPROBLEMFRAME_H
