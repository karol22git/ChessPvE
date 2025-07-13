#include "../include/Bishop.hpp"

Bishop::Bishop(const wxBitmap& _image, int x, int y, Color c): Piece(_image,x,y, c) {}

//std::vector<std::vector<int>> Bishop::GetLegalMoves(std::vector<std::vector<Piece*>> pieces) {
//    std::vector<std::vector<int>> newMoves;
//    auto currentX = GetX();
//    auto currentY = GetY();
//    for(int i = 1 ; currentX + i <= 7 && currentY +i <= 7 ; ++i){
//        if(pieces[currentX+i][currentY+i] == nullptr) newMoves.push_back({currentX+i,currentY+i,0});
//        else {
//            if(pieces[currentX+i][currentY+i]->GetColour() != color) newMoves.push_back({currentX+i, currentY+i,1});
//            break;
//        }
//    }
//    for(int i = 1 ; currentX - i>= 0 && currentY - i >=0 ; ++i){
//        if(pieces[currentX-i][currentY-i] == nullptr) newMoves.push_back({currentX-i,currentY-i,0});
//        else {
//            if(pieces[currentX-i][currentY-i]->GetColour() != color) newMoves.push_back({currentX-i, currentY-i,1});
//            break;
//        }
//    }
//    for(int i = 1 ; currentX +i <= 7 && currentY -i >=0 ; ++i){
//        if(pieces[currentX+i][currentY-i] == nullptr) newMoves.push_back({currentX+i,currentY-i,0});
//        else {
//            if(pieces[currentX+i][currentY-i]->GetColour() != color) newMoves.push_back({currentX+i, currentY-i,1});
//            break;
//        }
//    }
//    for(int i = 1 ; currentX - i >= 0 && currentY +i <= 7 ; ++i){
//        if(pieces[currentX-i][currentY+i] == nullptr) newMoves.push_back({currentX-i,currentY+i,0});
//        else {
//            if(pieces[currentX-i][currentY+i]->GetColour() != color) newMoves.push_back({currentX-i, currentY+i,1});
//            break;
//        }
//    }
//    return newMoves;
//}

std::vector<std::vector<int>> Bishop::GetLegalMoves(std::vector<std::vector<Piece*>> pieces) const {
    std::vector<std::vector<int>> newMoves;
    int x = GetX();
    int y = GetY();

    const int directions[4][2] = { {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };

    for (auto [dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;
        while (nx >= 0 && nx <= 7 && ny >= 0 && ny <= 7) {
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
bool Bishop::isReachable(int x, int y, std::vector<std::vector<Piece*>>& pieces) const {
    if (abs(GetX() - x) != abs(GetY() - y)) return false;

    int dx = (x > GetX()) ? 1 : -1;
    int dy = (y > GetY()) ? 1 : -1;

    int cx = GetX() + dx;
    int cy = GetY() + dy;

    while (cx != x && cy != y) {
        if (pieces[cx][cy] != nullptr) return false;
        cx += dx;
        cy += dy;
    }

    // Pole docelowe może być puste lub zawierać przeciwnika
    return (pieces[x][y] == nullptr || pieces[x][y]->GetColour() != color);
}

//bool Bishop::isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) {
//    if(abs(position[0] - x) != abs(position[1] - y)) return false;
//    int incrementX, incrementY;
//    if(x - position[0] > 0) incrementX = 1;
//    else incrementX = -1;
//    if(y - position[1] <0) incrementY = -1;
//    else incrementY = 1;
//    int startX = position[0];
//    int startY = position[1];
//    while(true) {
//        startX += incrementX;
//        startY += incrementY;
//        if(pieces[startX][startY] != nullptr) {
//            if(startX == x && startY == y) return true;
//            else return false;
//        }
//    }
//    return false;
//}