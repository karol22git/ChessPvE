#pragma once
#include "Piece.hpp"

class Rook: public Piece {
    public:
        Rook(wxBitmap _image, int x, int y, Color c);
        std::vector<std::vector<int>> GetLegalMoves(std::vector<std::vector<Piece*>>) override;
};