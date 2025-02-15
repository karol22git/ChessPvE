#include "../include/Board.hpp"
#include "../include/Constants.hpp"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

Board::Board(wxWindow* parent, wxWindowID id, const wxPoitn &pos, const wxSize &size) : wxWindow(parent,id,pos,size) {
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    this->Bind(wxEVT_PAINT, &DrawingCanvas::OnPaint, this);
}

void Board::OnPaint(wxPaintEvent &evt) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if(gc) {
        
    }
}