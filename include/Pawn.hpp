#pragma once
#include "Piece.hpp"

class Pawn : public Piece {
    public:
        Pawn(wxBitmap _image, int x, int y);
        std::vector<std::vector<int>> GetLegalMoves() override;
    private:
        bool didMove;
};