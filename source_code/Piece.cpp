#include "../include/Piece.hpp"

Piece::Piece(wxBitmap _image, int _position[2]) {
    image = _image;
    position[0] = _position[0];
    position[1] = _position[1];
}

Piece::Piece(wxBitmap _image, int x, int y) {
    image = _image;
    position[0] = x;
    position[1] = y;
}

void Piece::Move(int x, int y) {
    position[0] = x;
    position[1] = y;
    if(!didMove) didMove = true;
}

wxBitmap Piece::GetImage() {
    return image;
}

int* Piece::GetPosition() {
    return position;
}

int Piece::GetX() {
    return position[0];
}

int Piece::GetY(){
    return position[1];
}

Color Piece::GetColour() {
    return color;
}

Piece::Piece(wxBitmap _image, int x, int y, Color c){
    image = _image;
    position[0] = x;
    position[1] = y;
    color = c;
    didMove = false;
}

void Piece::Verify(int x, int y, std::vector<std::vector<Piece*>> &pieces, std::vector<std::vector<int>> &moves) {
    if(pieces[x][y] == nullptr) moves.push_back({x,y,0});
    else if(pieces[x][y]->GetColour() != color) moves.push_back({x,y,1});
}