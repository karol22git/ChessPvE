#pragma once
#include <wx/wx.h>
#include "Constants.hpp"
#include <vector>
class Piece{
    public:
        Piece(const wxBitmap& _image, int _position[2]);
        Piece(const wxBitmap& _image, int x, int y);
        Piece(const wxBitmap& _image, int x, int y, Color c);
        void Move(int x, int y);
        virtual std::vector<std::vector<int>> GetLegalMoves(std::vector<std::vector<Piece*>>) const = 0;
        void Verify(int x, int y, std::vector<std::vector<Piece*>> &pieces, std::vector<std::vector<int>> &moves) const;
        virtual bool isReachable(int x, int y,std::vector<std::vector<Piece*>> &pieces) const = 0;
        wxBitmap GetImage() const;
        int* GetPosition() ;
        int GetX() const;
        int GetY() const;
        Color GetColour() const;
        virtual ~Piece() = default;
    protected:
        wxBitmap image;
        int position[2];
        Color color= Color::white;
        bool didMove;
};