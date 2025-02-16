#pragma once
#include <wx/wx.h>

class BoardPanel: public wxWindow {
    public:
        BoardPanel(wxWindow* parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
        virtual ~BoardPanel(){}
    private:
        void OnPaint(wxPaintEvent &evt);
};