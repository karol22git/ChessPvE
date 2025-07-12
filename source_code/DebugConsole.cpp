#include "../include/DebugConsole.hpp"

DebugConsole::DebugConsole(wxWindow* parent)
    : wxFrame(parent, wxID_ANY, "Konsola debugowania", wxDefaultPosition, wxSize(600, 300))
{
    m_textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize,
                                wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH);
}

void DebugConsole::LogMessage(const wxString& msg)
{
    m_textCtrl->AppendText(msg + "\n");
}
