#include "../include/BoardPanel.hpp"
#include "../include/Constants.hpp"
#include "../include/ChessAppFrame.hpp"
#include <iostream>
#include <algorithm>
BoardPanel::BoardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size): wxWindow(parent,id,pos,size), pieces(8, std::vector<Piece*>(8, nullptr)), moderator(new Moderator(parent)) {
    mouseHandler = new MouseEventHandler(this);
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    this->Bind(wxEVT_PAINT, &BoardPanel::OnPaint, this);

    Bind(wxEVT_LEFT_DOWN,&MouseEventHandler::MouseLeftClick,mouseHandler);
    Bind(wxEVT_RIGHT_DOWN,&MouseEventHandler::MouseRightClick,mouseHandler);
    struct GraphicsResources gr = GraphicsResources();
    gr.Run();
    moderator->SetGr(gr);
    moderator->GetGraphicsResources();
    moderator->SetGraveyards(((ChessAppFrame*)parent)->GetOppGraveyardPanel(),((ChessAppFrame*)parent)->GetPlayerGraveyardPanel());
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
    wxPen penA(wxColour(0,135,62),4);
    wxPen penB(wxColour(255,0,0),4);
    gc->SetBrush(*wxTRANSPARENT_BRUSH);

    for(auto n: aureolas) {
        gc->SetPen(n.back() == 0 ? penA : penB);
        gc->DrawRectangle((n[0])*fieldSize +offset, ( 7-n[1])*fieldSize + offset,fieldSize,fieldSize);
    }
}

void BoardPanel::PaintPieces(wxGraphicsContext *gc) {
    for(const auto& row: moderator->GetPieces()) {
        for(const auto& piece : row) {
            if(piece) gc->DrawBitmap(piece->GetImage(),
                piece->GetX()*fieldSize+offset,
                (7-piece->GetY())*fieldSize+offset,
                fieldSize,fieldSize);
        }
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
}

void BoardPanel::UpdatePart(const wxRect& rect) {
    RefreshRect(rect);
    Update();
}

void BoardPanel::AddNewAureola(int x, int y) {
    aureolas.push_back({x,y});
}

void BoardPanel::AddNewAureola(const std::vector<int>& _aureola) {
    aureolas.push_back(_aureola);
}


void BoardPanel::ClearAureolas() {
    aureolas.clear();
    Refresh();
}


Piece* BoardPanel::GetPieceOnField(int x, int y) const {
    return pieces[x][y];
}


void BoardPanel::GetAureoloasFromPiece(const Piece* p) {
    if(p == nullptr) return;
    aureolas = p->GetLegalMoves(moderator->GetPieces());
}

int BoardPanel::HowManyPossibleMoves() const {
    return aureolas.size();
}

bool BoardPanel::ContainsAureola(int x, int y) const {
    for(auto a: aureolas) {
        if(a[0] == x && a[1] == y) return true;
    }
    return false;
}

int BoardPanel::GetAureolaType(int xPosition, int yPosition) const {
    for(auto a: aureolas) {
        if(a[0] == xPosition && a[1] == yPosition) return a[2];
    }
    return 0;
}