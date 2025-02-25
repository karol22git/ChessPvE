#include "../include/BoardPanel.hpp"
#include "../include/Constants.hpp"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <iostream>

BoardPanel::BoardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size): wxWindow(parent,id,pos,size) {
    wxInitAllImageHandlers();
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    this->Bind(wxEVT_PAINT, &BoardPanel::OnPaint, this);
    this->Bind(wxEVT_LEFT_DOWN,&BoardPanel::MouseLeftClick,this);
    wxImage image;
    if (!image.LoadFile(resourcesDir + "white_pawn.svg.png", wxBITMAP_TYPE_ANY)) {
        wxLogError("Failed to load the image.");
        return;
    }
    wxBitmap bitmap(image);
    pieces.push_back(new Piece(bitmap,5,5));
}

void BoardPanel::OnPaint(wxPaintEvent &evt) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();
    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if(drawFromPng) PaintFromScratch(gc);
    else PaintFromPng(gc);
    PaintPieces(gc);
    delete gc;
}

void BoardPanel::PaintPieces(wxGraphicsContext *gc) {
    for(auto n: pieces) {
        gc->DrawBitmap(n->GetImage(),0,0,fieldSize,fieldSize);
    }
}

void BoardPanel::PaintFromScratch(wxGraphicsContext *gc) {
    const wxColour* customColorA = new wxColour(102,178, 255);
    const wxColour* customColorB = new wxColour(204, 225, 229);
    if(gc) {
        for(int i = 0 ; i < boardSize  ; ++i) {
            for(int j = 0 ; j < boardSize  ; ++j) {
                if((i+j)%2 == 0) gc->SetBrush(*customColorA);
                else gc->SetBrush(*customColorB);
                gc->DrawRectangle((boardSize -i - 1)*fieldSize, (j)*fieldSize,fieldSize,fieldSize);
            }
        }
    }
}

void BoardPanel::PaintFromPng(wxGraphicsContext *gc) {
    wxImage image;
    if (!image.LoadFile(boardFile, wxBITMAP_TYPE_ANY)) {
        wxLogError("Failed to load the image.");
        return;
    }
    wxBitmap bitmap(image);
    gc->DrawBitmap(bitmap,0,0,560,560);
}

void BoardPanel::TakeScreenshot() {
    wxSize size = this->GetSize();
    wxBitmap screenshot(size);
    wxClientDC dc(this);
    wxMemoryDC memDC;
    memDC.SelectObject(screenshot);
    memDC.Blit(0,0,size.GetWidth(),size.GetHeight(),&dc,0,0);
    memDC.SelectObject(wxNullBitmap);
    screenshot.SaveFile("test.png",wxBITMAP_TYPE_PNG);
}

void BoardPanel::MouseLeftClick(wxMouseEvent &evt) {
    wxPoint mousePosition = evt.GetPosition();
    std::cout<< mousePosition.x /70<< ";"<< 7 - mousePosition.y/70<<std::endl;
}sssss

screenshot