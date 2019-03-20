#include "MessageProvider.h"

MessageProvider::MessageProvider() : m_typeMessages(), m_resultMessages(),
    m_invalidDataMessage(wxT("Invalid data typed. Triangle sides should be positive integral number not larger than "
                             "2^64 – 1."))
{
    m_typeMessages[SCALENE] = wxT("Triangle is scalene.");
    m_typeMessages[ISOSCELES] = wxT("Triangle is isosceles.");
    m_typeMessages[EQUILATERAL] = wxT("Triangle is equilateral.");

    m_resultMessages[SUCCESS] = wxT("Successfully initialized.");
    m_resultMessages[NOT_A_TRIANGLE] = wxT("Values specified don't represent triangle. They should satisfy the rule: "
                                           "sum of two side's lengths should exceed third side's length.");
    m_resultMessages[TOO_LARGE_SIDES] = wxT("Triangle sides are too large. Sum of any two sides shouldn't exceed "
                                            "2^64 – 1.");
}

const wxString& MessageProvider::GetInitializationResultMessage(TriangleInitializationResult result)
{
    return m_resultMessages[result];
}

const wxString& MessageProvider::GetTriangleTypeMessage(TriangleType type)
{
    return m_typeMessages[type];
}

const wxString& MessageProvider::GetInvalidDataMessage()
{
    return m_invalidDataMessage;
}
