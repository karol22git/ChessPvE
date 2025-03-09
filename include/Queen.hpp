#pragma once
#include "Piece.hpp"

class Queen: public Piece {
    public:
        Queen(wxBitmap _image, int x, int y);
        std::vector<std::vector<int>> GetLegalMoves() override;
};