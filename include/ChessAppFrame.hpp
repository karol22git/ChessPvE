#pragma once
#include <wx/wx.h>
#include "../include/ActionPanel.hpp"
#include "../include/GraveyardPanel.hpp"
#include "../include/BoardPanel.hpp"
class ChessAppFrame: public wxFrame {
    public:
        ChessAppFrame();
        GraveyardPanel* GetOppGraveyardPanel();
        GraveyardPanel* GetPlayerGraveyardPanel();
        void PassData(std::string, std::string);
    private:
        ActionPanel* actionPanel;
        wxBoxSizer* mainSizer;
        wxBoxSizer* middleSizer;
        GraveyardPanel* oppGraveyardPanel;
        GraveyardPanel* playerGraveyardPanel;
        BoardPanel* boardPanel;
        void ArrangeMainSizer();
        void ArrangeMiddleSizer();
        void InitializePlayground();
};