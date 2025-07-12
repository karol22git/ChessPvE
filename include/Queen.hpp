#pragma once
#include "Piece.hpp"

class Queen: public Piece {
    public:
        Queen(wxBitmap _image, int x, int y, Color c);
        std::vector<std::vector<int>> GetLegalMoves(std::vector<std::vector<Piece*>>) override;
        bool isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) override;
};