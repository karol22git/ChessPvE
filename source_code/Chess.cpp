#include "../include/Chess.hpp"
#include "../include/ChessAppFrame.hpp"

bool Chess::OnInit() {
    ChessAppFrame* chessAppFrame = new ChessAppFrame();
    chessAppFrame->Show();
    return true;
}

