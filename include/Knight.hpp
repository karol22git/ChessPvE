#pragma once
#include "Piece.hpp"

class Knight: public Piece {
    public:
        Knight(wxBitmap _image, int x, int y, Color c);
        std::vector<std::vector<int>> GetLegalMoves(std::vector<std::vector<Piece*>>) override;
};