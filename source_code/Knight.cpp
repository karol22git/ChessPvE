#include "../include/Knight.hpp"

Knight::Knight(wxBitmap _image, int x, int y) : Piece(_image,x,y) {

}

std::vector<std::vector<int>> Knight::GetLegalMoves() {
    std::vector<std::vector<int>> newMoves;
    auto currentX = GetX();
    auto currentY = GetY();
    if(currentX + 1 <=7 && currentY - 2 >=0) newMoves.push_back({currentX + 1,currentY - 2});
    if(currentX +1 <= 7 && currentY +2 <=7) newMoves.push_back({currentX +1 , currentY + 2});
    if(currentX +2 <= 7 && currentY -1 >=0) newMoves.push_back({currentX +2, currentY -1});
    if(currentX + 2 <= 7 && currentY +1 <= 7) newMoves.push_back({currentX +2,currentY +1});
    if(currentX - 1 >= 0 && currentY -2 >=0) newMoves.push_back({currentX - 1, currentY -2});
    if(currentX -2 >=0 && currentY - 1>=0) newMoves.push_back({currentX -2 , currentY - 1});
    if(currentX -2 >=0 && currentY +1 <=7) newMoves.push_back({currentX -2 , currentY +1});
    if(currentX - 1 >=0 && currentY +2 <=7) newMoves.push_back({currentX - 1, currentY +2});
    return newMoves;
}