#include "TriangleProblemFrame.h"
#include "PositiveDoubleValidator.h"
#include "Triangle.h"

const unsigned char m_sidesCount = 3;
const wxString equilateralMessage = "Triangle is equilateral", isoscelesMessage = "Triangle is isosceles",
    ordinaryMessage = "Triangle is not equilateral nor isosceles", tooLargeSidesMessage = "Triangle sides are too large",
    notTriangleMessage = "Values specified don't represent triangle";

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
            for (wxTextCtrl *side : m_sideSizeFields)
            {
                side->GetValue().ToDouble(&value);
                sides.push_back(value);
            }

            Triangle triangle;
            switch (triangle.Initialize(sides))
            {
                case SUCCESS:
                    if (triangle.IsEquilateral())
                    {
                        wxMessageBox(equilateralMessage);
                    }
                    else if (triangle.IsIsosceles())
                    {
                        wxMessageBox(isoscelesMessage);
                    }
                    else
                    {
                        wxMessageBox(ordinaryMessage);
                    }
                    break;
                case NOT_A_TRIANGLE:
                    wxMessageBox(notTriangleMessage);
                    break;
                case TOO_LARGE_SIDES:
                    wxMessageBox(tooLargeSidesMessage);
                    break;
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
