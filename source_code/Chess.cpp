#include "../include/Chess.hpp"
#include "../include/ChessAppFrame.hpp"

bool Chess::OnInit() {
    ChessAppFrame* chessAppFrame = new ChessAppFrame();
    chessAppFrame->Show();
    //wxLogMessage("Frame Position: (%d, %d)", chessAppFrame->GetPosition().x, chessAppFrame->GetPosition().y);
    return true;
}

