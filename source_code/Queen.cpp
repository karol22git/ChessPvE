#include "../include/Queen.hpp"


Queen::Queen(const wxBitmap& _image, int x, int y, Color c) : Piece(_image,x,y,c) {}



bool Queen::isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) const {
        auto moves = GetLegalMoves(pieces);
    for(auto move: moves) {
        if(move[0] == x && move[1] == y) return true;
    }
    return false;
}


std::vector<std::vector<int>> Queen::GetLegalMoves(std::vector<std::vector<Piece*>> pieces) const {
    std::vector<std::vector<int>> newMoves;
    const int directionsAsBishop[4][2] = {{1,1}, {-1,-1}, {1,-1} , {-1,1}};
    const int directionsAsRook[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int x = GetX();
    int y = GetY();
    for(const auto [dx,dy]: directionsAsBishop) {
        auto nx = x + dx;
        auto ny = y + dy;
        while(nx>=0 && nx<=7 && ny>=0 && ny<=7) {
            if (pieces[nx][ny] == nullptr) {
                newMoves.push_back({nx, ny, 0});
            } else {
                if (pieces[nx][ny]->GetColour() != color)
                    newMoves.push_back({nx, ny, 1});
                break;
            }
            nx += dx;
            ny += dy;
        }
    }
    x = GetX();
    y = GetY();
    for(const auto [dx,dy] : directionsAsRook) {
        auto nx = x + dx;
        auto ny = y + dy;
        while(nx >= 0 && nx <=7 && ny>=0 && ny<=7) {
            if (pieces[nx][ny] == nullptr) {
                newMoves.push_back({nx, ny, 0});
            } else {
                if (pieces[nx][ny]->GetColour() != color)
                    newMoves.push_back({nx, ny, 1});
                break;
            }
            nx += dx;
            ny += dy;
        }
    }
    return newMoves;
}