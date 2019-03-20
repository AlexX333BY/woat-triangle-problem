#ifndef WOAT_TRIANGLE_PROBLEM_MESSAGEPROVIDER_H
#define WOAT_TRIANGLE_PROBLEM_MESSAGEPROVIDER_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "Triangle.h"
#include <map>

class MessageProvider
{
public:
    MessageProvider();
    const wxString &GetTriangleTypeMessage(TriangleType type);
    const wxString &GetInitializationResultMessage(TriangleInitializationResult result);
    const wxString &GetInvalidDataMessage();
protected:
    std::map<TriangleType, wxString> m_typeMessages;
    std::map<TriangleInitializationResult, wxString> m_resultMessages;
    wxString m_invalidDataMessage;
};

#endif //WOAT_TRIANGLE_PROBLEM_MESSAGEPROVIDER_H
