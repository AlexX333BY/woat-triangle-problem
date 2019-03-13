#include "PositiveDoubleValidator.h"

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
