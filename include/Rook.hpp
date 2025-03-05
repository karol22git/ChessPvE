#include "Piece.hpp"

class Rook: public Piece {
    public:
        Rook(wxBitmap _image, int x, int y);
        std::vector<std::vector<int>> GetLegalMoves() override;
    private:
        bool didMove;
};