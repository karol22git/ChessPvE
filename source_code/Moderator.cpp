#include "../include/Moderator.hpp"
#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include "../include/Queen.hpp"
Moderator::Moderator(wxWindow *p): pieces(8, std::vector<Piece*>(8, nullptr)) {
    engine = new Stockfish(p);
    engine->Init();
}

void Moderator::GetGraphicsResources() {
    GeneratePieces();
}

void Moderator::GeneratePieces() {
    GenerateWhitePawns();
    GenerateBlackPawns();
    GenerateWhiteRooks();
    GenerateBlackRooks();
    GenerateWhiteKnights();
    GenerateBlackKnights();
    GenerateBlackBishops();
    GenerateWhiteBishops();
    GenerateWhiteQueen();
    GenerateBlackQueen();
    GenerateWhiteKing();
    GenerateBlackKing();
    
}

void Moderator::GenerateWhitePawns() {
    pieces[0][1] = new Pawn(gr.whitePawnBitmap,0,1,Color::white);
    pieces[1][1] = new Pawn(gr.whitePawnBitmap,1,1,Color::white);
    pieces[2][1] = new Pawn(gr.whitePawnBitmap,2,1,Color::white);
    pieces[3][1] = new Pawn(gr.whitePawnBitmap,3,1,Color::white);
    pieces[4][1] = new Pawn(gr.whitePawnBitmap,4,1,Color::white);
    pieces[5][1] = new Pawn(gr.whitePawnBitmap,5,1,Color::white);
    pieces[6][1] = new Pawn(gr.whitePawnBitmap,6,1,Color::white);
    pieces[7][1] = new Pawn(gr.whitePawnBitmap,7,1,Color::white);
}

void Moderator::GenerateBlackPawns() {
    pieces[0][6] = new Pawn(gr.blackPawnBitmap,0,6,Color::black);
    pieces[1][6] = new Pawn(gr.blackPawnBitmap,1,6,Color::black);
    pieces[2][6] = new Pawn(gr.blackPawnBitmap,2,6,Color::black);
    pieces[3][6] = new Pawn(gr.blackPawnBitmap,3,6,Color::black);
    pieces[4][6] = new Pawn(gr.blackPawnBitmap,4,6,Color::black);
    pieces[5][6] = new Pawn(gr.blackPawnBitmap,5,6,Color::black);
    pieces[6][6] = new Pawn(gr.blackPawnBitmap,6,6,Color::black);
    pieces[7][6] = new Pawn(gr.blackPawnBitmap,7,6,Color::black);
}

void Moderator::GenerateWhiteRooks() {
    pieces[0][0] = new Rook(gr.whiteRookBitmap,0,0,Color::white);
    pieces[7][0] = new Rook(gr.whiteRookBitmap,7,0,Color::white);
}

void Moderator::GenerateBlackRooks() {
    pieces[0][7] = new Rook(gr.blackRookBitmap,0,7,Color::black);
    pieces[7][7] = new Rook(gr.blackRookBitmap,7,7,Color::black);
}

void Moderator::GenerateWhiteKnights() {
    pieces[1][0] = new Knight(gr.whiteKnightBitmap,1,0,Color::white);
    pieces[6][0] = new Knight(gr.whiteKnightBitmap,6,0,Color::white);
}

void Moderator::GenerateBlackKnights() {
    pieces[1][7] = new Knight(gr.blackKnightBitmap,1,7,Color::black);
    pieces[6][7] = new Knight(gr.blackKnightBitmap,6,7,Color::black);
}

void Moderator::GenerateWhiteBishops() {
    pieces[2][0] = new Bishop(gr.whiteBishopBitmap,2,0,Color::white);
    pieces[5][0] = new Bishop(gr.whiteBishopBitmap,5,0,Color::white);
}

void Moderator::GenerateBlackBishops() {
    pieces[2][7] = new Bishop(gr.blackBishopBitmap,2,7,Color::black);
    pieces[5][7] = new Bishop(gr.blackBishopBitmap,5,7,Color::black);
}

void Moderator::GenerateBlackQueen() {
    pieces[3][7] = new Queen(gr.blackQueenBitmap,3,7,Color::black);
}

void Moderator::GenerateWhiteQueen() {
    pieces[3][0] = new Queen(gr.whiteQueenBitmap,3,0,Color::white);
}

void Moderator::GenerateWhiteKing() {
    pieces[4][0] = new King(gr.whiteKingBitmap,4,0,Color::white);
}

void Moderator::GenerateBlackKing() {
    pieces[4][7] = new King(gr.blackKingBitmap,4,7,Color::black);
}
Piece* Moderator::GetPieceOnField(int x, int y) {
    return pieces[x][y];
}

void Moderator::MovePiece(Piece* pieceToMove, int x, int y) {
    engine->AddNewMoveToHistory(Encode(pieceToMove->GetX(),pieceToMove->GetY(),x,y));
    pieces[pieceToMove->GetX()][pieceToMove->GetY()] = nullptr;
    pieces[x][y] = pieceToMove;
    pieceToMove->Move(x,y);
}

std::vector<std::vector<Piece*>> Moderator::GetPieces() {
    return pieces;
}

void Moderator::SetGr(struct GraphicsResources _gr) {
    gr = _gr;
}

bool Moderator::isFree(int x, int y) {
    if (pieces[x][y] == nullptr) return true;
    else return false;
}

bool Moderator::isEnemy(const Color c, const int x, const int y) const {
    if(pieces[x][y] != nullptr && pieces[x][y]->GetColour() == c) return false;
    return true;
}

void Moderator::KillPiece(int x, int y) {
    auto piece = pieces[x][y];
    pieces[x][y] = nullptr;
    piece->Move(0,0);
    if(piece->GetColour() == Color::white) {
        gPanelPlayer->Add(piece);
        gPanelPlayer->Refresh();
    }
    else {gPanelOpp->Add(piece);gPanelOpp->Refresh();}
    deadPieces.push_back(piece);
} 

void Moderator::SetGraveyards(GraveyardPanel* player, GraveyardPanel* opp){
    gPanelOpp = opp;
    gPanelPlayer = player;
}

void Moderator::CanKingMove(Color c) {

}

bool Moderator::isMoveLegal(int x1, int y1, int x2, int y2) {
     return engine->isMoveLegal(Encode(x1,y1,x2,y2));
}

std::string Moderator::Encode(int x1, int y1, int x2, int y2) {
    std::string result = "";
    result.push_back(intToCharMap[x1+1]);
    result.push_back((y1+1)+'0');
    result.push_back(intToCharMap[x2+1]);
    result.push_back((y2+1)+'0');
    return result;
}

std::vector<int> Moderator::Decode(std::string move) {
    return {charToIntMap[move[0]]-1,(move[1]-'0')-1,charToIntMap[move[2]]-1,(move[3]-'0')-1};
}

void Moderator::GetOppMove() {
    auto move = engine->GetNextMove();
    auto moveDecoded = Decode(move);
    if(pieces[moveDecoded[2]][moveDecoded[3]] !=nullptr) {
        KillPiece(moveDecoded[2],moveDecoded[3]);
        MovePiece(pieces[moveDecoded[0]][moveDecoded[1]],moveDecoded[2],moveDecoded[3]);
    }
    else {
        MovePiece(pieces[moveDecoded[0]][moveDecoded[1]],moveDecoded[2],moveDecoded[3]);
    }
}

void Moderator::SetPlayerColor(std::string c) {
    if(c == "white") playerColor = Color::white;
    else playerColor = Color::black;
    Setup();
}

void Moderator::SetOppElo(std::string e) {
    oppElo = e;
    engine->SetElo(oppElo);
}

void Moderator::LookForAnyWinCondition() {
    if(engine->GetListOfMoves().size() == 0) {
        if(isKingUnderAttack()) return ;//true;
        else return ;//false;
    }
}

bool Moderator::isKingUnderAttack() {
    auto xPlayer = playersKing->GetX();
    auto yPlayer = playersKing->GetY();
    for(auto row: pieces) {
        for(auto piece: row) {
            if(piece->GetColour() != playerColor) {
                if(piece->isReachable(xPlayer, yPlayer,pieces)) return true;
            }
        }
    }
    return false;
}

void Moderator::Setup() {
    if(playerColor == Color::white) playersKing = pieces[4][0];
    else playersKing = pieces[4][7];
}