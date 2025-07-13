#include "King.hpp"

King::King(const wxBitmap& _image, int x, int y, Color c) : Piece(_image,x,y,c) {
}


std::vector<std::vector<int>> King::GetLegalMoves(std::vector<std::vector<Piece*>> pieces) const  {
    std::vector<std::vector<int>> newMoves;
    const int directions[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
    auto x = GetX();
    auto y = GetY();
    for(const auto [dx,dy]: directions) {
        auto nx = x + dx;
        auto ny = y + dy;
        if(nx >= 0 && ny<=7 && ny>=0 && ny<=7) Verify(nx,ny,pieces,newMoves);
    }
    return newMoves;
}

bool King::isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) const{
    return false;
}