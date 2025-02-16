#include "../include/BoardPanel.hpp"
#include "../include/Constants.hpp"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

BoardPanel::BoardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size): wxWindow(parent,id,pos,size) {
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    this->Bind(wxEVT_PAINT, &BoardPanel::OnPaint, this);
}

void BoardPanel::OnPaint(wxPaintEvent &evt) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    //const wxColour* customColorA = new wxColour(0,204, 204); turkus
    const wxColour* customColorA = new wxColour(102,178, 255);
    const wxColour* customColorB = new wxColour(204, 225, 229);
    if(gc) {
        for(int i = 0 ; i < boardSize  ; ++i) {
            for(int j = 0 ; j < boardSize  ; ++j) {
                //if((i+j)%2 == 0) gc->SetBrush(*wxBLUE_BRUSH);
                //else gc->SetBrush(*wxWHITE_BRUSH);
                if((i+j)%2 == 0) gc->SetBrush(*customColorA);
                else gc->SetBrush(*customColorB);
                gc->DrawRectangle((boardSize -i - 1)*fieldSize, (j)*fieldSize,fieldSize,fieldSize);
            }
        }
    }
    delete gc;
}