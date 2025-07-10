#include "../include/Bishop.hpp"

Bishop::Bishop(wxBitmap _image, int x, int y, Color c): Piece(_image,x,y, c) {}

std::vector<std::vector<int>> Bishop::GetLegalMoves(std::vector<std::vector<Piece*>> pieces) {
    std::vector<std::vector<int>> newMoves;
    auto currentX = GetX();
    auto currentY = GetY();
    for(int i = 1 ; currentX + i <= 7 && currentY +i <= 7 ; ++i){
        if(pieces[currentX+i][currentY+i] == nullptr) newMoves.push_back({currentX+i,currentY+i,0});
        else {
            if(pieces[currentX+i][currentY+i]->GetColour() != color) newMoves.push_back({currentX+i, currentY+i,1});
            break;
        }
    }
    for(int i = 1 ; currentX - i>= 0 && currentY - i >=0 ; ++i){
        if(pieces[currentX-i][currentY-i] == nullptr) newMoves.push_back({currentX-i,currentY-i,0});
        else {
            if(pieces[currentX-i][currentY-i]->GetColour() != color) newMoves.push_back({currentX-i, currentY-i,1});
            break;
        }
    }
    for(int i = 1 ; currentX +i <= 7 && currentY -i >=0 ; ++i){
        if(pieces[currentX+i][currentY-i] == nullptr) newMoves.push_back({currentX+i,currentY-i,0});
        else {
            if(pieces[currentX+i][currentY-i]->GetColour() != color) newMoves.push_back({currentX+i, currentY-i,1});
            break;
        }
    }
    for(int i = 1 ; currentX - i >= 0 && currentY +i <= 7 ; ++i){
        if(pieces[currentX-i][currentY+i] == nullptr) newMoves.push_back({currentX-i,currentY+i,0});
        else {
            if(pieces[currentX-i][currentY+i]->GetColour() != color) newMoves.push_back({currentX-i, currentY+i,1});
            break;
        }
    }
    return newMoves;
}


bool Bishop::isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) {
    if(abs(position[0] - x) ! = abs(position[1] - y)) return false;
    int incrementX, incrementY;
    if(x - position[0] > 0) incrementX = 1;
    else incrementX = -1;
    if(y - position[1] <0) incrementY = -1;
    else incrementY = 1;
    int startX = position[0];
    int startY = position[1];
    while(true) {
        startX += incrementX;
        startY += incrementY;
        if(pieces[startX][startY] != nullptr) {
            if(startX == x && startY == y) return true;
            else return false;
        }
    }
    return false;
}