#include "PositiveDoubleValidator.h"

PositiveDoubleValidator::PositiveDoubleValidator() : wxValidator(), m_data()
{ }

bool PositiveDoubleValidator::Validate(wxWindow *)
{
    wxWindow *window = GetWindow();
    if (window->IsKindOf(CLASSINFO(wxTextCtrl)))
    {
        double value;
        return ((wxTextCtrl *)window)->GetValue().ToDouble(&value) && (value > 0);
    }
    else
    {
        return false;
    }
}

wxObject* PositiveDoubleValidator::Clone() const
{
    return new PositiveDoubleValidator(*this);
}

bool PositiveDoubleValidator::TransferFromWindow()
{
    wxWindow *window = GetWindow();
    if (window->IsKindOf(CLASSINFO(wxTextCtrl)))
    {
        m_data = ((wxTextCtrl *)window)->GetValue();
        return true;
    }
    else
    {
        return false;
    }
}

bool PositiveDoubleValidator::TransferToWindow()
{
    wxWindow *window = GetWindow();
    if (window->IsKindOf(CLASSINFO(wxTextCtrl)))
    {
        ((wxTextCtrl *)window)->SetValue(m_data);
        return true;
    }
    else
    {
        return false;
    }
}
