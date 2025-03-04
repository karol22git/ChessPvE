#pragma once
#include <wx/wx.h>
#include <vector>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include "../include/Pawn.hpp"
#include "../include/MouseEventHandler.hpp"
class BoardPanel: public wxWindow {
    public:
        BoardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
        virtual ~BoardPanel(){}
        void AddNewAureola(int x, int y);
        void AddNewAureola(std::vector<int> _aureola);
        void UpdatePart(const wxRect& rect);
        void ClearAureolas();
    private:
        void OnPaint(wxPaintEvent &evt);
        void PaintFromScratch(wxGraphicsContext *gc);
        void PaintFromPng(wxGraphicsContext *gc);
        void PaintPieces(wxGraphicsContext *gc);
        void PaintAureolas(wxGraphicsContext *gc);
        void TakeScreenshot();
        void MouseLeftClick(wxMouseEvent &evt);
        //std::vector<Piece*> pieces;
        std::vector<std::vector<Piece*>> pieces;//(8, std::vector<Piece*>(8, nullptr));
       // std::vector<std::vector<Piece*>> pieces(8,std::vector<Piece*>(8,nullptr));
        std::vector<std::vector<int>> aureolas;
        MouseEventHandler* mouseHandler;
        wxBitmap screenshot;
};