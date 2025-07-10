#pragma once
#include "Player.hpp"
#include "Constants.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Moderator.hpp"
#include "Pawn.hpp"
#include "GraveyardPanel.hpp"
class Moderator {
    public:
        Moderator();
        Piece* GetPieceOnField(int x, int y);
        void MovePiece(Piece* pieceToMove, int x, int y);
        std::vector<std::vector<Piece*>> GetPieces();
        void GetGraphicsResources();
        void SetGr(struct GraphicsResources);
        bool isFree(int x, int y);
        bool isEnemy(const Color c, const int x, const int y) const;
        void KillPiece(int x, int y);
        void SetGraveyards(GraveyardPanel* player, GraveyardPanel* opp);
        void CanKingMove(Color c);
    private:
        Player* whitePlayer, *blackPlayer;
        std::vector<std::vector<Piece*>> pieces;
        std::vector<Piece*> deadPieces;
        struct GraphicsResources gr;
        GraveyardPanel* gPanelPlayer;
        GraveyardPanel* gPanelOpp;
        King* whiteKing;
        King* blackKing;
};