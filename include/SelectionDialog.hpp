#pragma once
#include <wx/dialog.h>

class SelectionDialog : public wxDialog
{
public:
    SelectionDialog(wxWindow* parent)
        : wxDialog(parent, wxID_ANY, "Choose options", wxDefaultPosition, wxSize(300, 200))
    {
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

        // Etykieta
        mainSizer->Add(new wxStaticText(this, wxID_ANY, "Select OPP elo"),
                       0, wxALL | wxEXPAND, 10);

        // wxChoice
        wxArrayString choices;
        choices.Add("1350");
        choices.Add("1725");
        choices.Add("2100");
        choices.Add("2475");
        choices.Add("2850");
        choice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choices);
        choice->SetSelection(0);
        mainSizer->Add(choice, 0, wxALL | wxEXPAND, 10);

        // wxRadioBox
        wxString radioOptions[] = { "White", "Black" };
        radioBox = new wxRadioBox(this, wxID_ANY, "Choose color",
            wxDefaultPosition, wxDefaultSize, WXSIZEOF(radioOptions), radioOptions, 1, wxRA_SPECIFY_ROWS);
        mainSizer->Add(radioBox, 0, wxALL | wxEXPAND, 10);

        // Przycisk OK
        mainSizer->Add(new wxButton(this, wxID_OK, "Confirm"), 0, wxALL | wxALIGN_CENTER, 10);

        SetSizerAndFit(mainSizer);

        // Powiązanie zdarzenia zamknięcia
        Bind(wxEVT_CLOSE_WINDOW, &SelectionDialog::OnClose, this);
    }
    std::string GetSelectionFromChoice() {
        int index = choice->GetSelection();
        return choice->GetString(index).ToStdString();
    }
    std::string GetSelectionFromRadioBox() {
        int index = radioBox->GetSelection();
        return radioBox->GetString(index).ToStdString();
    }
private:
    void OnClose(wxCloseEvent& event)
    {
        wxWindow* parent = GetParent();
        parent->Close(true);
        wxTheApp->Exit();
    }
    wxChoice* choice;
    wxRadioBox* radioBox;
};
