#pragma once
#include <wx/wx.h>
#include "../include/Piece.hpp"
#include <vector>
class BoardPanel;
class MouseEventHandler {
    public:
        MouseEventHandler(BoardPanel* parent);
        void MouseLeftClick(wxMouseEvent &evt);
        void MouseRightClick(wxMouseEvent &evt);
        void GetPossibleMoves(wxMouseEvent &evt);
        void GetNextMove(wxMouseEvent &evt);
        std::vector<int> GetMousePosition(wxMouseEvent &evt);
    private:
        BoardPanel* parent;
        bool isChoosing;
        Piece* pieceToMove;
};