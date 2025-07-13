#pragma once
#include <wx/dialog.h>
#include "Constants.hpp"
#include <string>

class SurrenderDialog : public wxDialog {
    public:
        SurrenderDialog(wxWindow* parent,std::string info);
    private:
        void OnClose(wxCloseEvent& event);
        void DialogExit(wxCommandEvent &event);
        void DialogContinue(wxCommandEvent &event);

};
