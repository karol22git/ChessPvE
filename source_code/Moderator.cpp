#include "../include/Moderator.hpp"
#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include "../include/Queen.hpp"
Moderator::Moderator(): pieces(8, std::vector<Piece*>(8, nullptr)) {

}

void Moderator::GetGraphicsResources() {
    //struct GraphicsResources gr = GraphicsResources();
    //pieces[5][5] = new Queen(gr.blackQueenBitmap,5,5,Color::black);
    pieces[3][3] = new King(gr.whiteKingBitmap,3,3,Color::white);
    pieces[5][5] = new Pawn(gr.blackPawnBitmap,5,5,Color::black);
}

Piece* Moderator::GetPieceOnField(int x, int y) {
    return pieces[x][y];
}

void Moderator::MovePiece(Piece* pieceToMove, int x, int y) {
    pieces[pieceToMove->GetX()][pieceToMove->GetY()] = nullptr;
    pieces[x][y] = pieceToMove;
    pieceToMove->Move(x,y);
}

std::vector<std::vector<Piece*>> Moderator::GetPieces() {
    return pieces;
}

void Moderator::SetGr(struct GraphicsResources _gr) {
    gr = _gr;
}

bool Moderator::isFree(int x, int y) {
    if (pieces[x][y] == nullptr) return true;
    else return false;
}

bool Moderator::isEnemy(const Color c, const int x, const int y) const {
    if(pieces[x][y] != nullptr && pieces[x][y]->GetColour() == c) return false;
    return true;
}

void Moderator::KillPiece(int x, int y) {
    auto piece = pieces[x][y];
    pieces[x][y] = nullptr;
    piece->Move(0,0);
    if(piece->GetColour() == Color::white) {
        gPanelPlayer->Add(piece);
        gPanelOpp->Refresh();
    }
    else {gPanelOpp->Add(piece);gPanelOpp->Refresh();}
    deadPieces.push_back(piece);
} 

void Moderator::SetGraveyards(GraveyardPanel* player, GraveyardPanel* opp){
    gPanelOpp = opp;
    gPanelPlayer = player;
}

void Moderator::CanKingMove(Color c) {
    //Piece* king;
    //if(c == Color::white) king = whiteKing;
    //else king = blackKing;
    //auto moves = king->GetLegalMoves(pieces);
}