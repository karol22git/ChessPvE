#pragma once
#include <wx/wx.h>
#include "Constants.hpp"
//true = white, false = black
class Piece{
    public:
        Piece(wxBitmap _image, int _position[2]);
        Piece(wxBitmap _image, int x, int y);
        void Move(int x, int y);
        virtual void GetLegalMoves() = 0;
        wxBitmap GetImage();
        int* GetPosition();
        int GetX();
        int GetY();
    private:
        wxBitmap image;
        int position[2];
        Colors colour;
};