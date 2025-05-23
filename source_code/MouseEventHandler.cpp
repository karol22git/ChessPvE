#include "../include/MouseEventHandler.hpp"
#include "../include/BoardPanel.hpp"
#include "../include/Constants.hpp"

MouseEventHandler::MouseEventHandler(BoardPanel* _parent): parent(_parent), isChoosing(false), pieceToMove(nullptr) {
}

void MouseEventHandler::MouseLeftClick(wxMouseEvent &evt) {
    if(isChoosing) {
        GetNextMove(evt);
    }
    else GetPossibleMoves(evt);
}

void MouseEventHandler::GetPossibleMoves(wxMouseEvent &evt) {
    auto mPosition = GetMousePosition(evt);
    pieceToMove = parent->GetPieceOnField(mPosition[0],mPosition[1]);
    if(pieceToMove == nullptr) return;
    parent->AddNewAureola({mPosition[0],mPosition[1]});
    parent->GetAureoloasFromPiece(pieceToMove);
    isChoosing = true;
    parent->Refresh();
}

std::vector<int> MouseEventHandler::GetMousePosition(wxMouseEvent &evt) {
    wxPoint mousePosition = evt.GetPosition();
    int xPosition = mousePosition.x /70;
    int yPosition =7-mousePosition.y/70;
    return {xPosition,yPosition};
}
void MouseEventHandler::GetNextMove(wxMouseEvent &evt) {
    wxPoint mousePosition = evt.GetPosition();
    int xPosition = mousePosition.x /70;
    int yPosition =7-mousePosition.y/70;
    if(parent->ContainsAureola(xPosition,yPosition)) return;
    else {
        parent->ClearAureolas();
        isChoosing = false;
    }
}

void MouseEventHandler::MouseRightClick(wxMouseEvent& evt) {
    parent->ClearAureolas();
    isChoosing = false;
}