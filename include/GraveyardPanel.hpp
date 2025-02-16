#pragma once
#include <wx/wx.h>
#include "DrawingCanvas.hpp"
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
class GraveyardPanel: public DrawingCanvas {
    public:
        GraveyardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    private:
        void OnPaint(wxPaintEvent &evt) override;
};