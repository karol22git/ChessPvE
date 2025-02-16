#include "../include/GraveyardPanel.hpp"
#include "../include/Constants.hpp"

GraveyardPanel::GraveyardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : DrawingCanvas(parent,id,pos,size) {
}

void GraveyardPanel::OnPaint(wxPaintEvent &evt) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    //const wxColour* customColorA = new wxColour(0,204, 204);
    //const wxColour* customColorB = new wxColour(204, 225, 229);
    gc->SetBrush(*wxWHITE_BRUSH);
    gc->SetPen(wxPen(*wxBLACK,2));
    if(gc) {
        for(int i = 0 ; i < graveyardFieldSize  ; ++i) {
                //if(i%2 == 0) gc->SetBrush(*wxBLUE_BRUSH);
                //if(i%2 == 0) gc->SetBrush(*customColorA);
                //else gc->SetBrush(*wxBLACK_BRUSH);
                //else gc->SetBrush(*customColorB);
                gc->DrawRectangle(i*graveyardFieldSize, 0,graveyardFieldSize,graveyardFieldSize);
            
        }
    }
    delete gc;
}