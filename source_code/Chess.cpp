#include "../include/Chess.hpp"
#include "../include/ChessAppFrame.hpp"
Moderator* moderator = new Moderator();
bool Chess::OnInit() {
    wxInitAllImageHandlers();
    //moderator->GetGraphicsResources();
    ChessAppFrame* chessAppFrame = new ChessAppFrame();
    chessAppFrame->Show();
    return true;
}

