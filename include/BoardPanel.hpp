#pragma once
#include <wx/wx.h>
#include <vector>
#include "../include/Piece.hpp"
class BoardPanel: public wxWindow {
    public:
        BoardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
        virtual ~BoardPanel(){}
    private:
        void OnPaint(wxPaintEvent &evt);
        void PaintFromScratch(wxGraphicsContext *gc);
        void PaintFromPng(wxGraphicsContext *gc);
        void PaintPieces(wxGraphicsContext *gc);
        void TakeScreenshot();
        void MouseLeftClick(wxMouseEvent &evt);
        std::vector<Piece*> pieces;
};