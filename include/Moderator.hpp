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
#include "Stockfish.hpp"
#include <map>
#include <vector>
#include <string>
class Moderator {
    public:
        Moderator(wxWindow* p);
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
        void GeneratePieces();
        void GenerateWhitePawns();
        void GenerateBlackPawns();
        void GenerateWhiteRooks();
        void GenerateBlackRooks();
        void GenerateWhiteKnights();
        void GenerateBlackKnights();
        void GenerateWhiteBishops();
        void GenerateBlackBishops();
        void GenerateWhiteQueen();
        void GenerateBlackQueen();
        void GenerateWhiteKing();
        void GenerateBlackKing();
        bool isMoveLegal(int,int,int,int);
        std::string Encode(int,int,int,int);
        std::vector<int> Decode(std::string);
        void GetOppMove();
        Color movable = Color::white;
        void SetPlayerColor(std::string);
        void SetOppElo(std::string);
        void LookForAnyWinCondition();
        bool isKingUnderAttack();
        void Setup();
        void InitializeGame();
        ~Moderator() {
            for (auto& row : pieces)
                for (auto& piece : row)
                    delete piece;
            delete engine;
        }

    private:
        wxWindow* parent;
        Color playerColor;
        std::string oppElo;
        //Color movable = Color::white;
        Player* whitePlayer, *blackPlayer;
        std::vector<std::vector<Piece*>> pieces;
        std::vector<Piece*> deadPieces;
        struct GraphicsResources gr;
        GraveyardPanel* gPanelPlayer;
        GraveyardPanel* gPanelOpp;
        King* whiteKing;
        King* blackKing;
        Piece* playersKing;
        Stockfish* engine;
        std::map<char, int> charToIntMap = {{'a',1},{'b',2},{'c',3},{'d',4},{'e',5},{'f',6},{'g',7},{'h',8}};
        std::map<int,char> intToCharMap = {{1,'a'},{2,'b'},{3,'c'},{4,'d'},{5,'e'},{6,'f'},{7,'g'},{8,'h'}};
};