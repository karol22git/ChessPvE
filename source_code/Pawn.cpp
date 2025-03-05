#include "../include/Pawn.hpp"

Pawn::Pawn(wxBitmap _image, int x, int y) : Piece(_image,x,y), didMove(false) {}

std::vector<std::vector<int>> Pawn::GetLegalMoves() {
    std::vector<std::vector<int>> legalMoves;
    if(color == Colors::white) {
        if(!didMove) {
            legalMoves.push_back({position[0],position[1] +2});
        }
        legalMoves.push_back({position[0],position[1] +1});
    }
    else {
        if(!didMove) {
            legalMoves.push_back({position[0],position[1] -2});
        }
        legalMoves.push_back({position[0],position[1] -1});
    }
    return legalMoves;
}