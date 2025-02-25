#include "../include/ActionPanel.hpp"

ActionPanel::ActionPanel(wxWindow* parent, wxSize size) : wxPanel(parent,wxID_ANY,wxPoint(0,0),size) {
    CreateButtons();
    CreateInfoField();
    ArrangeSizer();
    SetSizerAndFit(actionPanelSizer);
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