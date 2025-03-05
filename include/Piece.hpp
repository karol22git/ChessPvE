#pragma once
#include <wx/wx.h>
#include "Constants.hpp"
#include <vector>
//true = white, false = black
class Piece{
    public:
        Piece(wxBitmap _image, int _position[2]);
        Piece(wxBitmap _image, int x, int y);
        void Move(int x, int y);
        virtual std::vector<std::vector<int>> GetLegalMoves() = 0;
        wxBitmap GetImage();
        int* GetPosition();
        int GetX();
        int GetY();
    protected:
        wxBitmap image;
        int position[2];
        Colors color= Colors::white;
};