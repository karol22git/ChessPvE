#include "../include/Chess.hpp"
#include "../include/ChessAppFrame.hpp"
#include "../include/SelectionDialog.hpp"
#include <string>
//Moderator* moderator = new Moderator();
bool Chess::OnInit() {
    wxInitAllImageHandlers();
    //moderator->GetGraphicsResources();
    ChessAppFrame* chessAppFrame = new ChessAppFrame();
    chessAppFrame->Show();
    SelectionDialog dlg(chessAppFrame);
    std::string elo;
    std::string color;
    if (dlg.ShowModal() == wxID_OK) {
        elo = dlg.GetSelectionFromChoice();
        color = dlg.GetSelectionFromRadioBox();
        chessAppFrame->PassData(color,elo);
    }
    
    return true;
}

