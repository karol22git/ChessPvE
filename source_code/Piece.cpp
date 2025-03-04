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