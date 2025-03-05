#pragma once
#include "Piece.hpp"

class Knight: public Piece {
    public:
        Knight(wxBitmap _image, int x, int y);
        std::vector<std::vector<int>> GetLegalMoves() override;
};