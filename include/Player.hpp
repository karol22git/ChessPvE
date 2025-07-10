#pragma once
#include "Constants.hpp"
#include "Piece.hpp"
#include <vector>
class Player {
    public:
        Player(Color c);
        void GenerateBlackPieces();
        void GenerateWhitePieces();
        void GeneratePieces(Color c);
    private:
        Color color;
        std::vector<Piece*> pieces;
};