#pragma once
#include <wx/wx.h>
#include "../include/ActionPanel.hpp"
#include "../include/GraveyardPanel.hpp"
#include "../include/BoardPanel.hpp"
#include "Moderator.hpp"
class ChessAppFrame: public wxFrame {
    public:
        ChessAppFrame();
        GraveyardPanel* GetOppGraveyardPanel() const;
        GraveyardPanel* GetPlayerGraveyardPanel() const;
        void PassData(std::string, std::string) const;
        Moderator* GetMod() const;
        void RedrawBoard();
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