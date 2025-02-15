#include "../include/ChessAppFrame.hpp"
#include "../include/Constants.hpp"
ChessAppFrame::ChessAppFrame() :wxFrame(NULL,wxID_ANY,wxString("Chess"),wxDefaultPosition,wxDefaultSize,wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER) {
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
   // wxBoxSizer *sizer2 = new wxBoxSizer(wxHORIZONTAL);
    wxPanel *testPanel = new wxPanel(this,wxID_ANY, wxPoint(0,0),wxSize(800,50));
    wxPanel *testPanel2 = new wxPanel(this,wxID_ANY, wxPoint(0,0),wxSize(560,560));
    wxPanel *testPanel3 = new wxPanel(this,wxID_ANY, wxPoint(0,0),wxSize(800,50));
   // wxPanel *testPanel4 = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(560)
    testPanel->SetBackgroundColour(*wxGREEN);
    testPanel2->SetBackgroundColour(*wxCYAN);
    testPanel3->SetBackgroundColour(*wxBLUE);
    sizer->Add(testPanel,0,wxALL,10);
    sizer->Add(testPanel2,0,wxALL,10);
    sizer->Add(testPanel3,0,wxALL,10);
    this->SetSizerAndFit(sizer);
    SetSize(wxSize(frameWidth, frameHeight));
}