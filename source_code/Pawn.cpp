#include "../include/Pawn.hpp"

Pawn::Pawn(wxBitmap _image, int x, int y, Color c) : Piece(_image,x,y, c) {}

std::vector<std::vector<int>> Pawn::GetLegalMoves(std::vector<std::vector<Piece*>> pieces) {
    std::vector<std::vector<int>> legalMoves;
    if(color == Color::white) {
        if(!didMove) {
            legalMoves.push_back({position[0],position[1] +2,0});
        }
        if(position[1]+1 <=7 && pieces[position[0]][position[1]+1] == nullptr) legalMoves.push_back({position[0],position[1] +1,0});
        if(position[0] - 1 >=0 && position[1]+1 <=7 && pieces[position[0] - 1][position[1]+1]!= nullptr) {
            if(pieces[position[0]-1][position[1]+1]->GetColour() != color) legalMoves.push_back({position[0]-1, position[1]+1,1});
        }
        if(position[0] +1 <=7 &&position[1]+1 <=7 && pieces[position[0] + 1][position[1]+1]!= nullptr) {
            if(pieces[position[0]+1][position[1]+1]->GetColour() != color) legalMoves.push_back({position[0]+1, position[1]+1,1});
        }
    }
    else {
        if(!didMove) {
            legalMoves.push_back({position[0],position[1] -2,0});
        }
        if(position[1]-1 >=0 && pieces[position[0]][position[1]-1] ==nullptr) legalMoves.push_back({position[0],position[1] -1,0});
        if(position[0] - 1 >=0 &&position[1] -1 >=0 && pieces[position[0] - 1][position[1]-1]!= nullptr) {
            if(pieces[position[0]-1][position[1]-1]->GetColour() != color) legalMoves.push_back({position[0]-1, position[1]-1,1});
        }
        if(position[0] +1 <=7 && position[1] -1 >=0 && pieces[position[0] + 1][position[1]-1]!= nullptr) {
            if(pieces[position[0]+1][position[1]-1]->GetColour() != color) legalMoves.push_back({position[0]+1, position[1]-1,1});
        }
    }
    return legalMoves;
}


bool Pawn::isReachable(int x, int y, std::vector<std::vector<Piece*>> &pieces) {
    if(color == Color::white) {
        if((x == position[0]-1 && y == position[1] +1 )|| (x == position[0]+1 && y == position[1] +1)) return true;
    }
    else {
         if((x == position[0]-1 && y == position[1] -1 )|| (x == position[0]+1 && y == position[1] -1)) return true;
    }
    return false;
}