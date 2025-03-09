#pragma once
#include "Constant.hpp"
#include "Piece.hpp"
#include "vector>"
class Player {
    public:
        Player(Color c);
    private:
        Color color;
        std::vector<Piece*> pieces;
};