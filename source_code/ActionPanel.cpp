#include "../include/ActionPanel.hpp"
#include "ChessAppFrame.hpp"
ActionPanel::ActionPanel(wxWindow* parent, wxSize size) : wxPanel(parent,wxID_ANY,wxPoint(0,0),size) {
    CreateButtons();
    CreateInfoField();
    ArrangeSizer();
    SetSizerAndFit(actionPanelSizer);
    surrenderButton->Bind(wxEVT_BUTTON,&ActionPanel::Surrender,this);
    drawButton->Bind(wxEVT_BUTTON,&ActionPanel::Draw,this);
}

void ActionPanel::CreateButtons() {
    drawButton = new wxButton(this, wxID_ANY, "Draw",wxDefaultPosition,wxSize(150,50));
    surrenderButton = new wxButton(this, wxID_ANY, "Surrender",wxDefaultPosition,wxSize(150,50));
}

void ActionPanel::CreateInfoField() {
    infoField = new wxStaticText(this,wxID_ANY,"  Youre turn! ",wxDefaultPosition,drawButton->GetSize(),wxALIGN_CENTER_HORIZONTAL |wxALIGN_CENTER_VERTICAL );
    infoField->SetBackgroundStyle(wxBG_STYLE_COLOUR);
    infoField->SetBackgroundColour(*wxRED);
}

void ActionPanel::ArrangeSizer() {
    actionPanelSizer =  new wxStaticBoxSizer(wxVERTICAL,this, "Actions");
    actionPanelSizer->Add(drawButton,0,wxALL,10);
    actionPanelSizer->Add(infoField,0,wxLEFT,10);
    actionPanelSizer->Add(surrenderButton,0,wxALL,10);
}

void ActionPanel::Surrender(wxCommandEvent& event) {
    wxWindow* parent = GetParent();
    ChessAppFrame* d = dynamic_cast<ChessAppFrame*>(parent);
    SurrenderDialog sDialog(GetParent(),"You lost by surrender");
    if (sDialog.ShowModal() == wxID_OK) {
    }
}

void ActionPanel::Draw(wxCommandEvent &event) {
    SurrenderDialog sDialog(GetParent(),"Game drawed.");
    if (sDialog.ShowModal() == wxID_OK) {
    }
}