#pragma once
#include <wx/wx.h>

class DrawingCanvas: public wxWindow {
    public:
        DrawingCanvas(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
        virtual ~DrawingCanvas(){}
    protected:
        virtual void OnPaint(wxPaintEvent &evt) = 0;
};