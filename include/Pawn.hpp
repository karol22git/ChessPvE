#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
    public:
        Pawn(wxBitmap _image, int x, int y);
        void GetLegalMoves() override;
    private:
        bool didMove = false;
};