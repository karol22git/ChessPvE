#include "../include/SurrenderDialog.hpp"
#include "../include/ChessAppFrame.hpp"

SurrenderDialog::SurrenderDialog(wxWindow* parent,std::string info)
: wxDialog(parent, wxID_ANY, "Attention.", /*wxDefaultPosition*/wxPoint(frameWidth/2, frameHeight/2), wxSize(300, 150)) {
wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(new wxStaticText(this, wxID_ANY, info),
                       0, wxALL | wxEXPAND, 10);
        wxButton* okButton = new wxButton(this, wxID_OK, "Exit");
        wxButton* cancelButton = new wxButton(this, wxID_CANCEL, "Play again");

        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
        buttonSizer->Add(okButton, 1, wxALL, 5);
        buttonSizer->Add(cancelButton, 1, wxALL, 5);

        sizer->AddStretchSpacer();
        sizer->Add(buttonSizer, 0, wxALIGN_CENTER);
        sizer->AddStretchSpacer();

        SetSizerAndFit(sizer);
        okButton->Bind(wxEVT_BUTTON,&SurrenderDialog::DialogExit,this);
        cancelButton->Bind(wxEVT_BUTTON, &SurrenderDialog::DialogContinue, this);
        Bind(wxEVT_CLOSE_WINDOW, &SurrenderDialog::OnClose, this);

}

void SurrenderDialog::OnClose(wxCloseEvent& event) {
    wxWindow* parent = GetParent();
        parent->Close(true);
        wxTheApp->Exit();
}

void SurrenderDialog::DialogExit(wxCommandEvent &event){
    wxWindow* parent = GetParent();
        parent->Close(true);
        wxTheApp->Exit();
        EndModal(wxID_OK);
}

void SurrenderDialog::DialogContinue(wxCommandEvent &event) {
     wxWindow* parent = GetParent();
        ChessAppFrame* d = dynamic_cast<ChessAppFrame*>(parent);
        auto mod = d->GetMod();
        mod->InitializeGame();
        d->RedrawBoard();
        EndModal(wxID_CANCEL);
}