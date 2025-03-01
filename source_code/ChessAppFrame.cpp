#include "../include/ChessAppFrame.hpp"
#include "../include/Constants.hpp"


ChessAppFrame::ChessAppFrame() :wxFrame(NULL,wxID_ANY,wxString("Chess"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) {
    InitializePlayground();
    ArrangeMiddleSizer();
    ArrangeMainSizer();
    this->SetSizerAndFit(mainSizer);
}

void ChessAppFrame::ArrangeMainSizer() {
    mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(oppGraveyardPanel,0,wxALL,10);
    mainSizer->Add(middleSizer,0,wxALL,10);
    mainSizer->Add(playerGraveyardPanel,0,wxALL,10);
}

void ChessAppFrame::ArrangeMiddleSizer() {
    wxBoxSizer* helperSizer = new wxBoxSizer(wxVERTICAL);
    middleSizer =  new wxBoxSizer(wxHORIZONTAL);
    helperSizer->Add(actionPanel, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL|wxLEFT,40);
    middleSizer->Add(boardPanel,0,wxALL,10);
    middleSizer->Add(helperSizer, 1, wxALIGN_CENTER_HORIZONTAL |wxALIGN_CENTER_VERTICAL);
}

void ChessAppFrame::InitializePlayground() {
    oppGraveyardPanel = new GraveyardPanel(this,wxID_ANY,wxPoint(0,0),wxSize(800,50));
    playerGraveyardPanel = new GraveyardPanel(this,wxID_ANY,wxPoint(0,0),wxSize(800,50));
    boardPanel = new BoardPanel(this,wxID_ANY,wxDefaultPosition,wxSize(560+2*offset,560+2*offset));
    actionPanel = new ActionPanel(this,wxSize(240,560));
}