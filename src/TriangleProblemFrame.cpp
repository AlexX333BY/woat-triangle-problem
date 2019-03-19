#include "TriangleProblemFrame.h"
#include "UnsignedLongLongValidator.h"
#include "Triangle.h"
#include <wx/filename.h>

const unsigned char m_sidesCount = 3;
const wxString equilateralMessage = "Triangle is equilateral", isoscelesMessage = "Triangle is isosceles",
    ordinaryMessage = "Triangle is scalene", tooLargeSidesMessage = "Triangle sides are too large",
    notTriangleMessage = "Values specified don't represent triangle", invalidDataMessage = "Invalid data typed";

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
                UnsignedLongLongValidator());
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

    wxMenuBar *menuBar = new wxMenuBar();
    wxMenu *menu;

    menu = new wxMenu();
    menu->Append(wxID_EXIT, "Exit");
    menuBar->Append(menu, "File");

    menu = new wxMenu();
    menu->Append(wxID_HELP, "Help");
    menu->Append(wxID_ABOUT, "About");
    menuBar->Append(menu, "About");

    SetMenuBar(menuBar);
    Bind(wxEVT_BUTTON, &TriangleProblemFrame::OnAnalyzeClick, this);
    Bind(wxEVT_MENU, &TriangleProblemFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &TriangleProblemFrame::OnHelp, this, wxID_HELP);
}

void TriangleProblemFrame::OnAnalyzeClick(wxCommandEvent &event)
{
    if (event.GetId() == m_analyzeButtonId)
    {
        if (m_panel->Validate())
        {
            std::vector<unsigned long long> sides;
            unsigned long long value;
            for (wxTextCtrl *side : m_sideSizeFields)
            {
                side->GetValue().ToULongLong(&value, 10);
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
                    wxMessageBox(notTriangleMessage, wxMessageBoxCaptionStr, wxCENTRE | wxOK | wxICON_ERROR);
                    break;
                case TOO_LARGE_SIDES:
                    wxMessageBox(tooLargeSidesMessage);
                    break;
            }
        }
        else
        {
            wxMessageBox(invalidDataMessage, wxMessageBoxCaptionStr, wxCENTRE | wxOK | wxICON_ERROR);
        }
    }
    else
    {
        event.Skip();
    }
}

void TriangleProblemFrame::OnExit(wxEvent &)
{
    Close();
}

void TriangleProblemFrame::OnHelp(wxEvent &)
{
    wxFileName name("../help/help.html");
    name.Normalize();
    wxLaunchDefaultBrowser(name.GetFullPath());
}
