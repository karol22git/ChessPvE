#include "../include/Moderator.hpp"
#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include "../include/Queen.hpp"
Moderator::Moderator(): pieces(8, std::vector<Piece*>(8, nullptr)) {
    wxImage image;
    if (!image.LoadFile(resourcesDir + "white_queen.svg.png", wxBITMAP_TYPE_ANY)) {
        wxLogError("Failed to load the image.");
        return;
    }
    wxBitmap bitmap(image);
    pieces[5][5] = new Queen(bitmap,5,5);
}

Piece* Moderator::GetPieceOnField(int x, int y) {
    return pieces[x][y];
}

void Moderator::MovePiece(Piece* pieceToMove, int x, int y, int oldx, int oldy) {
    pieces[oldx][oldy] = nullptr;
    pieces[x][y] = pieceToMove;
}

std::vector<std::vector<Piece*>> Moderator::GetPieces() {
    return pieces;
}