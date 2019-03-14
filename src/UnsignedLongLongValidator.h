#ifndef WOAT_TRIANGLE_PROBLEM_UNSIGNEDLONGLONGVALIDATOR_H
#define WOAT_TRIANGLE_PROBLEM_UNSIGNEDLONGLONGVALIDATOR_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class UnsignedLongLongValidator : public wxValidator
{
public:
    UnsignedLongLongValidator();
    virtual bool Validate(wxWindow *parent);
    virtual wxObject* Clone() const;
    virtual bool TransferFromWindow();
    virtual bool TransferToWindow();
protected:
    wxString m_data;
};

#endif //WOAT_TRIANGLE_PROBLEM_UNSIGNEDLONGLONGVALIDATOR_H
