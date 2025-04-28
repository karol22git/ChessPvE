#pragma once
#include "Player.hpp"
#include "Constants.hpp"

class Moderator {
    public:
        Moderator();
        Piece* GetPieceOnField(int x, int y);
        void MovePiece(Piece* pieceToMove, int x, int y, int oldx, int oldy);
        std::vector<std::vector<Piece*>> GetPieces();
    private:
        Player* whitePlayer, *blackPlayer;
        std::vector<std::vector<Piece*>> pieces;
};