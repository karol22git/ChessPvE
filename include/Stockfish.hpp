
#pragma once
#include <winsock2.h>
#include <windows.h>
#include <boost/process/v1/system.hpp>
#include <boost/process/v1/child.hpp>
#include <boost/process/v1/pipe.hpp>
#include <boost/process/v1/io.hpp>
#include <iostream>
#include <string>
#include <wx/textctrl.h>
#include <wx/wx.h>
#include "DebugConsole.hpp"
namespace bp = boost::process::v1;
class Stockfish {
    public:
        Stockfish(wxWindow *p) {
            debugConsole = new DebugConsole(p);
            debugConsole->Show();
        };
        void Init();
        void SetElo(const std::string);
        std::string Start();
        std::string GetNextMove();
        std::vector<std::string> GetListOfMoves();
        void AddNewMoveToHistory(std::string);
        bool isMoveLegal(const std::string);
        void Reset();
        ~Stockfish() {
            delete debugConsole;
        };
    private:
        const std::string command = "../bin/stockfish.exe";
        const std::string initCommand = "setoption name MultiPV value 100\n";
        const std::string initCommand2 = "setoption name UCI_LimitStrength value true\n";
        const std::string initCommand3 = "setoption name UCI_Elo value ";
        const std::string core = "position startpos moves ";
        std::string history = "";
        bp::opstream stockfish_in;
        bp::ipstream pipe_stream;
        bp::child stockfish;
        DebugConsole* debugConsole = nullptr;
};