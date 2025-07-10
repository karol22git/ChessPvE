#pragma once
#include <wx/wx.h>
#include "DrawingCanvas.hpp"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include "Piece.hpp"
#include <vector>
class GraveyardPanel: public DrawingCanvas {
    public:
        GraveyardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
        void Add(Piece*);
    private:
        void OnPaint(wxPaintEvent &evt) override;
        std::vector<Piece*> pieces;
};