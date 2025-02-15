#pragma once
#include <wx/wx.h>

class Board: public wxWindow {
    public:
        Board(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
        virtual ~DrawingCanvas(){}
    private:
        void OnPaint(wxPaintEvent &evt);
}