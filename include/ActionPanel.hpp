#include <wx/wx.h>

class ActionPanel: public wxPanel {
    public:
        ActionPanel(wxWindow* parent, wxSize size);
    private:
        wxButton *drawButton;
        wxButton *surrenderButton;
        wxStaticText *infoField;
        wxStaticBoxSizer *actionPanelSizer;
        void CreateButtons();
        void CreateInfoField();
        void ArrangeSizer();
};