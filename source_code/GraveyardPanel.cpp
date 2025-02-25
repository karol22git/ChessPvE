#include "../include/GraveyardPanel.hpp"
#include "../include/Constants.hpp"

GraveyardPanel::GraveyardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : DrawingCanvas(parent,id,pos,size) {
}

void GraveyardPanel::OnPaint(wxPaintEvent &evt) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    gc->SetBrush(*wxWHITE_BRUSH);
    gc->SetPen(wxPen(*wxBLACK,2));
    if(gc) {
        for(int i = 0 ; i < graveyardFieldSize  ; ++i) {
                gc->DrawRectangle(i*graveyardFieldSize, 0,graveyardFieldSize,graveyardFieldSize);
            
        }
    }
    delete gc;
}