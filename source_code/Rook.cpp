#include "../include/Rook.hpp"

Rook::Rook(wxBitmap _image, int x, int y): Piece(_image,x,y), didMove(false) {}

std::vector<std::vector<int>> Rook::GetLegalMoves() {
    std::vector<std::vector<int>> newMoves;
    auto currentX = GetX();
    auto currentY = GetY();
    for(int i = 1 ; i + currentY <= 7 ; ++i) newMoves.push_back({currentX,currentY +i});
    for(int i = 1 ; currentY - i >= 0 ; ++i) newMoves.push_back({currentX,currentY - i});
    for(int i = 1 ; currentX +i <= 7 ; ++i) newMoves.push_back({currentX+i,currentY});
    for(int i = 1 ; currentX - i >=0 ; ++i) newMoves.push_back({currentX - i, currentY});
    return newMoves;
    
}