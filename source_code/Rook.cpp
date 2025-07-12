#include "../include/Rook.hpp"

Rook::Rook(wxBitmap _image, int x, int y, Color c): Piece(_image,x,y,c) {}

std::vector<std::vector<int>> Rook::GetLegalMoves(std::vector<std::vector<Piece*>> pieces) {
    std::vector<std::vector<int>> newMoves;
    auto currentX = GetX();
    auto currentY = GetY();
    for(int i = 1 ; i + currentY <= 7 ; ++i) {
        if(pieces[currentX][currentY +i] == nullptr) newMoves.push_back({currentX,currentY +i,0});
        else {
            if(pieces[currentX][currentY + i]->GetColour() != color) newMoves.push_back({currentX, currentY +i,1});
            break;
        }
    }
    for(int i = 1 ; currentY - i >= 0 ; ++i){
        if(pieces[currentX][currentY -  i] == nullptr) newMoves.push_back({currentX,currentY - i,0});
        else {
            if(pieces[currentX][currentY - i]->GetColour() != color) newMoves.push_back({currentX, currentY - i,1});
            break;
        }
    }
    for(int i = 1 ; currentX +i <= 7 ; ++i){
        if(pieces[currentX+i][currentY ] == nullptr) newMoves.push_back({currentX+i,currentY,0});
        else {
            if(pieces[currentX+i][currentY]->GetColour() != color) newMoves.push_back({currentX+i, currentY,1});
            break;
        }
    }
    for(int i = 1 ; currentX - i >=0 ; ++i){
        if(pieces[currentX-i][currentY ] == nullptr) newMoves.push_back({currentX-i,currentY,0});
        else {
            if(pieces[currentX-i][currentY]->GetColour() != color) newMoves.push_back({currentX-i, currentY,1});
            break;
        }
    }
    return newMoves;
    
}

bool Rook::isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) {
        auto moves = GetLegalMoves(pieces);
    for(auto move: moves) {
        if(move[0] == x && move[1] == y) return true;
    }
    return false;
}