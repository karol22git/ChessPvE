#include "../include/Knight.hpp"

Knight::Knight(const wxBitmap& _image, int x, int y,Color c) : Piece(_image,x,y,c) {

}

std::vector<std::vector<int>> Knight::GetLegalMoves(std::vector<std::vector<Piece*>> pieces) const  {
    std::vector<std::vector<int>> newMoves;
    const int directions[8][2] = {{1,-2},{1,2},{2,-1},{2,1},{-1,-2},{-2,-1},{-2,+1},{-1,2}};

    auto x = GetX();
    auto y = GetY();
    for(const auto [dx,dy]: directions) {
        auto nx = x + dx;
        auto ny = y + dy;
        if(nx >=0 && nx<=7 && ny>=0 && ny<=7) Verify(nx,ny,pieces,newMoves);
    }
    return newMoves;
}

bool Knight::isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) const {
    auto moves = GetLegalMoves(pieces);
    for(auto move: moves) {
        if(move[0] == x && move[1] == y) return true;
    }
    return false;
}