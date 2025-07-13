#pragma once
#include <wx/wx.h>
#include "SurrenderDialog.hpp"
class ActionPanel: public wxPanel {
    public:
        ActionPanel(wxWindow* parent, wxSize size);
    private:
        wxButton *drawButton;
        wxButton *surrenderButton;
        wxStaticText *infoField;
        wxStaticBoxSizer *actionPanelSizer;
        void CreateButtons();
        void CreateInfoField();
        void ArrangeSizer();
        void Surrender(wxCommandEvent& event);
        void Draw(wxCommandEvent& event);
};