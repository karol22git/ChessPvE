#include "../include/Queen.hpp"


Queen::Queen(wxBitmap _image, int x, int y) : Piece(_image,x,y) {}

std::vector<std::vector<int>> Queen::GetLegalMoves() {
    std::vector<std::vector<int>> newMoves;
    auto currentX = GetX();
    auto currentY = GetY();
    for(int i = 1 ; i + currentY <= 7 ; ++i) newMoves.push_back({currentX,currentY +i});
    for(int i = 1 ; currentY - i >= 0 ; ++i) newMoves.push_back({currentX,currentY - i});
    for(int i = 1 ; currentX +i <= 7 ; ++i) newMoves.push_back({currentX+i,currentY});
    for(int i = 1 ; currentX - i >=0 ; ++i) newMoves.push_back({currentX - i, currentY});
    for(int i = 1 ; currentX + i <= 7 && currentY +i <= 7 ; ++i) newMoves.push_back({currentX +i , currentY +i});
    for(int i = 1 ; currentX - i>= 0 && currentY - i >=0 ; ++i) newMoves.push_back({currentX -i, currentY - i});
    for(int i = 1 ; currentX +i <= 7 && currentY -i >=0 ; ++i) newMoves.push_back({currentX +i,currentY - i});
    for(int i = 1 ; currentX - i >= 0 && currentY +i <= 7 ; ++i) newMoves.push_back({currentX - i , currentY +i});
    return newMoves;
}