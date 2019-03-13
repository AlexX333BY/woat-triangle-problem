#ifndef WOAT_TRIANGLE_PROBLEM_POSITIVEDOUBLEVALIDATOR_H
#define WOAT_TRIANGLE_PROBLEM_POSITIVEDOUBLEVALIDATOR_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class PositiveDoubleValidator : public wxValidator
{
public:
    PositiveDoubleValidator();
    virtual bool Validate(wxWindow *parent);
    virtual wxObject* Clone() const;
    virtual bool TransferFromWindow();
    virtual bool TransferToWindow();
protected:
    wxString m_data;
};

#endif //WOAT_TRIANGLE_PROBLEM_POSITIVEDOUBLEVALIDATOR_H
