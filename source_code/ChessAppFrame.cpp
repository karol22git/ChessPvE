#include "../include/ChessAppFrame.hpp"
#include "../include/BoardPanel.hpp"
#include "../include/Constants.hpp"
#include "../include/GraveyardPanel.hpp"

ChessAppFrame::ChessAppFrame() :wxFrame(NULL,wxID_ANY,wxString("Chess"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) {
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *sizer2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *sizer3 = new wxBoxSizer(wxVERTICAL);
    GraveyardPanel *gPanel = new GraveyardPanel(this,wxID_ANY,wxPoint(0,0),wxSize(800,50));
    wxPanel *testPanel22 = new wxPanel(this,wxID_ANY,wxPoint(0,0),wxSize(240,560));
    wxStaticBoxSizer *sz = new wxStaticBoxSizer(wxVERTICAL,testPanel22, "Actions");
    wxButton *button1 = new wxButton(testPanel22, wxID_ANY, "Draw",wxDefaultPosition,wxSize(150,50));
    wxButton *button2 = new wxButton(testPanel22, wxID_ANY, "Surrender",wxDefaultPosition,wxSize(150,50));
    wxStaticText *sText = new wxStaticText(testPanel22,wxID_ANY,"  Youre turn! ",wxDefaultPosition,button1->GetSize(),wxALIGN_CENTER_HORIZONTAL |wxALIGN_CENTER_VERTICAL );
    sText->SetBackgroundStyle(wxBG_STYLE_COLOUR);
    sz->Add(button1,0,wxALL,10);
    sz->Add(sText,0,wxLEFT,10);
    sz->Add(button2,0,wxALL,10);
    GraveyardPanel *gPanelBottom = new GraveyardPanel(this,wxID_ANY,wxPoint(0,0),wxSize(800,50));
    BoardPanel* b = new BoardPanel(this,wxID_ANY,wxDefaultPosition,wxSize(560,560));
    sizer2->Add(b,0);
    testPanel22->SetSizerAndFit(sz);
    sizer3->Add(testPanel22, 1, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL|wxLEFT,40);
    sizer2->Add(sizer3, 1, wxALIGN_CENTER_HORIZONTAL |wxALIGN_CENTER_VERTICAL);
    sizer->Add(gPanel,0,wxALL,10);
    sizer->Add(sizer2,0,wxALL,10);
    sizer->Add(gPanelBottom,0,wxALL,10);
    this->SetSizerAndFit(sizer);
}