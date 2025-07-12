#include "../include/BoardPanel.hpp"
#include "../include/Constants.hpp"
#include "../include/ChessAppFrame.hpp"
#include <iostream>
#include <algorithm>
BoardPanel::BoardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size): wxWindow(parent,id,pos,size), pieces(8, std::vector<Piece*>(8, nullptr)), moderator(new Moderator(parent)) {
    //wxInitAllImageHandlers();
    mouseHandler = new MouseEventHandler(this);
    this->SetBackgroundStyle(wxBG_STYLE_PAINT);
    this->Bind(wxEVT_PAINT, &BoardPanel::OnPaint, this);

    Bind(wxEVT_LEFT_DOWN,&MouseEventHandler::MouseLeftClick,mouseHandler);
    Bind(wxEVT_RIGHT_DOWN,&MouseEventHandler::MouseRightClick,mouseHandler);
    struct GraphicsResources gr = GraphicsResources();
    gr.Run();
    moderator->SetGr(gr);
    moderator->GetGraphicsResources();
    //moderator->SetGraveyards(((*ChessAppFrame*)parent)->GetOppGraveyardPanel(),parent->GetPlayerGraveyardPanel());
    moderator->SetGraveyards(((ChessAppFrame*)parent)->GetOppGraveyardPanel(),((ChessAppFrame*)parent)->GetPlayerGraveyardPanel());
    //wxImage image;
    //if (!image.LoadFile(resourcesDir + "white_king.svg.png", wxBITMAP_TYPE_ANY)) {
    //    wxLogError("Failed to load the image.");
    //    return;
    //}
    //wxBitmap bitmap(image);
    //pieces[5][5] = new King(bitmap,5,5);
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
    const wxColour* customColorB = new wxColour(255,0,0);
    auto penA= wxPen(*customColorA,4);
    auto penB = wxPen(*customColorB,4);
    gc->SetPen(wxPen(*customColorB,4)); 
    gc->SetBrush(*wxTRANSPARENT_BRUSH);
    for(auto n: aureolas) {
        //std::cout<<n[0]<<";"<<7-n[1]<<std::endl;
        if(n.back() == 0) gc->SetPen(wxPen(*customColorA,4));
        else gc->SetPen(wxPen(*customColorB,4));
        gc->DrawRectangle((n[0])*fieldSize +offset, ( 7-n[1])*fieldSize + offset,fieldSize,fieldSize);
    }
}

void BoardPanel::PaintPieces(wxGraphicsContext *gc) {
    auto l = moderator->GetPieces();
    for(auto n: l) {
        for(auto m : n) {
            if(m!=nullptr)gc->DrawBitmap(m->GetImage(),m->GetX()*fieldSize+offset,(7-m->GetY())*fieldSize+offset,fieldSize,fieldSize);
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

/*void BoardPanel::MouseLeftClick(wxMouseEvent &evt) {
    wxPoint mousePosition = evt.GetPosition();
    std::cout<< mousePosition.x /70<< ";"<< 7 - mousePosition.y/70<<std::endl;
}*/

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


Piece* BoardPanel::GetPieceOnField(int x, int y) {
    return pieces[x][y];
}


void BoardPanel::GetAureoloasFromPiece(Piece* p) {
    if(p == nullptr) return;
    ///auto newMoves = p->GetLegalMoves(moderator->GetPieces());
    aureolas = p->GetLegalMoves(moderator->GetPieces());
    //tutaj
    //for(auto n: newMoves) {
    //     if(moderator->isFree(n[0],n[1])) {aureolas.push_back({n[0],n[1],0});}
    //     else if(moderator->isEnemy(p->GetColour(),n[0],n[1])) {aureolas.push_back({n[0],n[1],1});}
    //}
    //for(auto n: aureolas) std::cout<<n.size()<<std::endl;
}

int BoardPanel::HowManyPossibleMoves() {
    return aureolas.size();
}

bool BoardPanel::ContainsAureola(int x, int y) {
    //std::vector<int> s = {x,y};
    //auto r = std::find(aureolas.begin(),aureolas.end(),s);
    //if(r == aureolas.end()) return false;
    //else return true;
    for(auto a: aureolas) {
        if(a[0] == x && a[1] == y) return true;
    }
    return false;
}

int BoardPanel::GetAureolaType(int xPosition, int yPosition) {
    for(auto a: aureolas) {
        if(a[0] == xPosition && a[1] == yPosition) return a[2];
    }
    return 0;
}