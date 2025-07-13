#include "../include/Piece.hpp"

Piece::Piece(const wxBitmap& _image, int _position[2]): image(_image), didMove(false) {
    position[0] = _position[0];
    position[1] = _position[1];
}

Piece::Piece(const wxBitmap& _image, int x, int y) :image(_image), didMove(false) {
    image = _image;
    position[0] = x;
    position[1] = y;
}

void Piece::Move(int x, int y) {
    position[0] = x;
    position[1] = y;
    if(!didMove) didMove = true;
}

wxBitmap Piece::GetImage() const{
    return image;
}

int* Piece::GetPosition(){
    return position;
}

int Piece::GetX() const {
    return position[0];
}

int Piece::GetY() const{
    return position[1];
}

Color Piece::GetColour() const {
    return color;
}

Piece::Piece(const wxBitmap& _image, int x, int y, Color c) :image(_image), color(c), didMove(false) {
    position[0] = x;
    position[1] = y;
}

void Piece::Verify(int x, int y, std::vector<std::vector<Piece*>> &pieces, std::vector<std::vector<int>> &moves) const {
    if(pieces[x][y] == nullptr) moves.push_back({x,y,0});
    else if(pieces[x][y]->GetColour() != color) moves.push_back({x,y,1});
}
