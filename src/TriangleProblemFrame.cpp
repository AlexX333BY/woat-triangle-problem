#include "TriangleProblemFrame.h"

const unsigned char m_sidesCount = 3;

TriangleProblemFrame::TriangleProblemFrame(const wxString &title, const int gap, const int border)
    : wxFrame(nullptr, wxID_ANY, title), m_sideSizeFields()
{
    const wxString analyzeButtonHint = "Analyze", sideInputHint = "Side #";
    const int rowCount = m_sidesCount, columnCount = 2;

    wxPanel *panel = new wxPanel(this);

    wxFlexGridSizer *inputSizer = new wxFlexGridSizer(rowCount, columnCount, gap, gap);
    inputSizer->AddGrowableCol(1, 1);

    wxTextCtrl *textCtrl;
    wxBoxSizer *sizer;
    for (unsigned char side = 0; side < m_sidesCount; ++side)
    {
        textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0,
                wxTextValidator(wxFILTER_EMPTY | wxFILTER_NUMERIC));
        m_sideSizeFields.push_back(textCtrl);
        inputSizer->Add(new wxStaticText(panel, wxID_ANY, wxString::Format("%s%d", sideInputHint, side + 1)), 0,
                wxALIGN_CENTER);

        sizer = new wxBoxSizer(wxHORIZONTAL);
        sizer->Add(textCtrl, 1, wxALIGN_CENTER);
        inputSizer->Add(sizer, 0, wxEXPAND);

        inputSizer->AddGrowableRow(side, 1);
    }

    wxBoxSizer *panelSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer->Add(inputSizer, 1, wxALL | wxEXPAND, border);
    panelSizer->Add(new wxButton(panel, wxID_ANY, analyzeButtonHint), 0, wxALL | wxALIGN_CENTER, border);
    panel->SetSizer(panelSizer);
}
