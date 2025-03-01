#include "../include/MouseEventHandler.hpp"
#include "../include/BoardPanel.hpp"
#include "../include/Constants.hpp"

MouseEventHandler::MouseEventHandler(BoardPanel* _parent) {
    parent = _parent;
}

void MouseEventHandler::MouseLeftClick(wxMouseEvent &evt) {
    wxPoint mousePosition = evt.GetPosition();
    int xPosition = mousePosition.x /70;
    int yPosition = mousePosition.y/70;
    //std::cout<< mousePosition.x /70<< ";"<< 7 - mousePosition.y/70<<std::endl;
    parent->AddNewAureola({xPosition,yPosition});
    parent->UpdatePart(wxRect((xPosition)*fieldSize -10 +offset,(yPosition) *fieldSize - 10 +offset,fieldSize+20,fieldSize+20));
   // std::cout<<(xPosition)*fieldSize<<";"<<(boardSize - yPosition) *fieldSize<<std::endl;
}

void MouseEventHandler::MouseRightClick(wxMouseEvent& evt) {
    parent->ClearAureolas();
}