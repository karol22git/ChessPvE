#pragma once
#include <wx/wx.h>
class BoardPanel;
class MouseEventHandler {
    public:
        MouseEventHandler(BoardPanel* parent);
        void MouseLeftClick(wxMouseEvent &evt);
        void MouseRightClick(wxMouseEvent &evt);
    private:
        BoardPanel* parent;
};