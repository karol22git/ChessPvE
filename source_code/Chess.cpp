#include "../include/Chess.hpp"
#include "../include/ChessAppFrame.hpp"

bool Chess::OnInit() {
    ChessAppFrame* chessAppFrame = new ChessAppFrame();
    chessAppFrame->Show();
   // int x,y;
   // chessAppFrame->GetSize(&x,&y);
    //wxLogMessage("Frame Position: (%d, %d)", chessAppFrame->GetSize().width, chessAppFrame->GetSize().height);
    //wxLogMessage("Frame Position: (%d, %d)", x, y);
    return true;
}

