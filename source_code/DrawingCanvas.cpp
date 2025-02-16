#include "../include/DrawingCanvas.hpp"

DrawingCanvas::DrawingCanvas(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size): wxWindow(parent,id,pos,size) {
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    this->Bind(wxEVT_PAINT, &DrawingCanvas::OnPaint, this);
}