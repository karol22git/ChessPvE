#pragma once
#include "Piece.hpp"


class King : public Piece {
    public:
        King(const wxBitmap& _image, int x, int y, Color c);
        std::vector<std::vector<int>> GetLegalMoves(std::vector<std::vector<Piece*>>) const override;
        bool isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) const override;
};