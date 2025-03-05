#include "../include/Bishop.hpp"

Bishop::Bishop(wxBitmap _image, int x, int y): Piece(_image,x,y) {}

std::vector<std::vector<int>> Bishop::GetLegalMoves() {
    std::vector<std::vector<int>> newMoves;
    auto currentX = GetX();
    auto currentY = GetY();
    for(int i = 1 ; currentX + i <= 7 && currentY +i <= 7 ; ++i) newMoves.push_back({currentX +i , currentY +i});
    for(int i = 1 ; currentX - i>= 0 && currentY - i >=0 ; ++i) newMoves.push_back({currentX -i, currentY - i});
    for(int i = 1 ; currentX +i <= 7 && currentY -i >=0 ; ++i) newMoves.push_back({currentX +i,currentY - i});
    for(int i = 1 ; currentX - i >= 0 && currentY +i <= 7 ; ++i) newMoves.push_back({currentX - i , currentY +i});
    return newMoves;
}