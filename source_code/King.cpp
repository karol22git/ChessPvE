#include "King.hpp"

King::King(wxBitmap _image, int x, int y, Color c) : Piece(_image,x,y,c) {
}


std::vector<std::vector<int>> King::GetLegalMoves(std::vector<std::vector<Piece*>> pieces)  {
    std::vector<std::vector<int>> newMoves;
    auto currentX = GetX();
    auto currentY = GetY();
    //if(currentX +1 <= 7) newMoves.push_back({currentX +1, currentY});
    if(currentX +1 <= 7) Verify(currentX+1,currentY,pieces,newMoves);//newMoves.push_back({currentX +1, currentY});
    if(currentX - 1 >= 0) Verify(currentX-1,currentY,pieces,newMoves);//newMoves.push_back({currentX - 1, currentY});
    if(currentY +1 <= 7) Verify(currentX,currentY+1,pieces,newMoves);// newMoves.push_back({currentX, currentY +1});
    if(currentY - 1 >=0) Verify(currentX,currentY-1,pieces,newMoves);//newMoves.push_back({currentX,currentY-1});
    if(currentY - 1>= 0 && currentX-1>=0) Verify(currentX-1,currentY-1,pieces,newMoves);//newMoves.push_back({currentX - 1 , currentY - 1});
    if(currentY - 1 >=0 && currentX+1<=7) Verify(currentX+1,currentY-1,pieces,newMoves);//newMoves.push_back({currentX +1,currentY-1});
    if(currentY +1 <=7 && currentX-1>=0) Verify(currentX-1,currentY+1,pieces,newMoves);//newMoves.push_back({currentX-1, currentY+1});
    if(currentY+1<=7 && currentX+1<=7) Verify(currentX+1,currentY+1,pieces,newMoves);//newMoves.push_back({currentX+1, currentY+1});
    return newMoves;
}
