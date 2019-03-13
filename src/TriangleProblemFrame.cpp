#include "TriangleProblemFrame.h"
#include "PositiveDoubleValidator.h"

const unsigned char m_sidesCount = 3;

TriangleProblemFrame::TriangleProblemFrame(const wxString &title, const int gap, const int border)
    : wxFrame(nullptr, wxID_ANY, title), m_sideSizeFields()
{
    const wxString analyzeButtonHint = "Analyze", sideInputHint = "Side #";
    const int rowCount = m_sidesCount, columnCount = 2;

    m_panel = new wxPanel(this);

    wxFlexGridSizer *inputSizer = new wxFlexGridSizer(rowCount, columnCount, gap, gap);
    inputSizer->AddGrowableCol(1, 1);

    wxTextCtrl *textCtrl;
    wxBoxSizer *sizer;
    for (unsigned char side = 0; side < m_sidesCount; ++side)
    {
        textCtrl = new wxTextCtrl(m_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0,
                PositiveDoubleValidator());
        m_sideSizeFields.push_back(textCtrl);
        inputSizer->Add(new wxStaticText(m_panel, wxID_ANY, wxString::Format("%s%d", sideInputHint, side + 1)), 0,
                wxALIGN_CENTER);

        sizer = new wxBoxSizer(wxHORIZONTAL);
        sizer->Add(textCtrl, 1, wxALIGN_CENTER);
        inputSizer->Add(sizer, 0, wxEXPAND);

        inputSizer->AddGrowableRow(side, 1);
    }

    wxBoxSizer *panelSizer = new wxBoxSizer(wxVERTICAL);
    panelSizer->Add(inputSizer, 1, wxALL | wxEXPAND, border);
    panelSizer->Add(new wxButton(m_panel, m_analyzeButtonId, analyzeButtonHint), 0, wxALL | wxALIGN_CENTER, border);
    m_panel->SetSizer(panelSizer);

    Bind(wxEVT_BUTTON, &TriangleProblemFrame::OnAnalyzeClick, this);
}

void TriangleProblemFrame::OnAnalyzeClick(wxCommandEvent &event)
{
    if (event.GetId() == m_analyzeButtonId)
    {
        if (m_panel->Validate())
        {
            std::vector<double> sides;
            double value;
            for (unsigned long side = 0; side < m_sideSizeFields.size(); ++side)
            {
                m_sideSizeFields[side]->GetValue().ToDouble(&value);
                sides.push_back(value);
            }
        }
        else
        {
            wxMessageBox("Invalid data typed", "Error", wxCENTRE | wxOK | wxICON_ERROR);
        }
    }
    else
    {
        event.Skip();
    }
}
