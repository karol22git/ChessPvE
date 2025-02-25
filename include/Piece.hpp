#pragma once
#include <wx/wx.h>

class Piece{
    public:
        Piece(wxBitmap _image, int _position[2]);
        Piece(wxBitmap _image, int x, int y);
        void Move(int x, int y);
        wxBitmap GetImage();
    private:
        wxBitmap image;
        int position[2];
};