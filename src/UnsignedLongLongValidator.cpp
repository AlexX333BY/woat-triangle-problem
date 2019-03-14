#include "UnsignedLongLongValidator.h"

UnsignedLongLongValidator::UnsignedLongLongValidator() : wxValidator(), m_data()
{ }

bool UnsignedLongLongValidator::Validate(wxWindow *)
{
    wxWindow *window = GetWindow();
    if (window->IsKindOf(CLASSINFO(wxTextCtrl)))
    {
        unsigned long long value;
        return ((wxTextCtrl *)window)->GetValue().ToULongLong(&value) && (value > 0);
    }
    else
    {
        return false;
    }
}

wxObject* UnsignedLongLongValidator::Clone() const
{
    return new UnsignedLongLongValidator(*this);
}

bool UnsignedLongLongValidator::TransferFromWindow()
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

bool UnsignedLongLongValidator::TransferToWindow()
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
