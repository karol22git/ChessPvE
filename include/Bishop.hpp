#include "Piece.hpp"

class Bishop: public Piece {
    public:
        Bishop(wxBitmap _image, int x, int y);
        std::vector<std::vector<int>> GetLegalMoves() override;
};