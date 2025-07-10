#include "../include/Player.hpp"

Player::Player(Color c): color(c) {
    GeneratePieces(c);
}

void Player::GeneratePieces(Color c) {
    if(c == Color::white) GenerateWhitePieces();
    else GenerateBlackPieces();
}

void Player::GenerateBlackPieces() {

}

void Player::GenerateWhitePieces() {
    
}