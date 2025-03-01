#include "../include/BoardPanel.hpp"
#include "../include/Constants.hpp"
//#include <wx/graphics.h>
//#include <wx/dcbuffer.h>
#include <iostream>

BoardPanel::BoardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size): wxWindow(parent,id,pos,size) {
    wxInitAllImageHandlers();
    mouseHandler = new MouseEventHandler(this);
   // wxSize size = this->GetSize();
   // wxBitmap screenshot(size);
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    this->Bind(wxEVT_PAINT, &BoardPanel::OnPaint, this);
    //this->Bind(wxEVT_LEFT_DOWN,&BoardPanel::MouseLeftClick,this);

    Bind(wxEVT_LEFT_DOWN,&MouseEventHandler::MouseLeftClick,mouseHandler);
    Bind(wxEVT_RIGHT_DOWN,&MouseEventHandler::MouseRightClick,mouseHandler);
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
    if(drawFromPng) PaintFromPng(gc);
    else PaintFromScratch(gc);
    PaintPieces(gc);
    PaintAureolas(gc);
    delete gc;
}

void BoardPanel::PaintAureolas(wxGraphicsContext *gc) {
    const wxColour* customColorA = new wxColour(0,135, 62);// fajny christmas green
    gc->SetPen(wxPen(*customColorA,4)); 
    gc->SetBrush(*wxTRANSPARENT_BRUSH);
    for(auto n: aureolas) {
        gc->DrawRectangle((n[0])*fieldSize +offset, (n[1])*fieldSize + offset,fieldSize,fieldSize);
    }
}

void BoardPanel::PaintPieces(wxGraphicsContext *gc) {
    for(auto n: pieces) {
        gc->DrawBitmap(n->GetImage(),0+offset,0+offset,fieldSize,fieldSize);
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
    gc->DrawBitmap(bitmap,0+offset,0+offset,560,560);
}


void BoardPanel::TakeScreenshot() {
   wxSize size = this->GetSize();
   screenshot = wxBitmap(size);
    wxClientDC dc(this);
    wxMemoryDC memDC;
    memDC.SelectObject(screenshot);
    memDC.Blit(0,0,size.GetWidth(),size.GetHeight(),&dc,0,0);
    memDC.SelectObject(wxNullBitmap);
    //screenshot.SaveFile("test.png",wxBITMAP_TYPE_PNG);
}

void BoardPanel::MouseLeftClick(wxMouseEvent &evt) {
    wxPoint mousePosition = evt.GetPosition();
    std::cout<< mousePosition.x /70<< ";"<< 7 - mousePosition.y/70<<std::endl;
}

void BoardPanel::UpdatePart(const wxRect& rect) {
    RefreshRect(rect);
    Update();
}

void BoardPanel::AddNewAureola(int x, int y) {
    aureolas.push_back({x,y});
}

void BoardPanel::AddNewAureola(std::vector<int> _aureola) {
    aureolas.push_back(_aureola);
}

void BoardPanel::ClearAureolas() {
    aureolas.clear();
    Refresh();
}