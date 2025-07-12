#include "../include/Stockfish.hpp"


void Stockfish::Init() {
    stockfish = bp::child(command,bp::std_in< stockfish_in, bp::std_out > pipe_stream);
    stockfish_in << initCommand<<std::flush;
    std::string line;
    std::getline(pipe_stream, line);
}

void Stockfish::SetElo(std::string elo) {
    stockfish_in << initCommand2<<std::flush;
    auto setEloCommand = initCommand2 + elo +"\n";
    stockfish_in <<setEloCommand<<std::flush;
}
std::string Stockfish::Start() {
    stockfish_in<<"position startpos\n"<<std::flush;
    stockfish_in<<"go depth 1\n"<<std::flush;
    std::string line;
    while (pipe_stream && std::getline(pipe_stream, line)) {
      //  std::cout << line <<std::endl;
        if(line.find("bestmove") != std::string::npos) break;
    }
    auto nMove =  line.substr(9);
    AddNewMoveToHistory(nMove);
    return nMove;
}

std::string Stockfish::GetNextMove() {
    std::string nextCommand = "position startpos moves " + history + "\n";
    stockfish_in<<nextCommand<<std::flush;
    stockfish_in<<"go depth 1\n"<<std::flush;
    std::string line;
    while (pipe_stream && std::getline(pipe_stream, line)) {
        if(line.find("bestmove") != std::string::npos) break;
    }
    if(line.find("ponder") != std::string::npos) {
        return line.substr(9,4);
    }
    return line.substr(9);
}

std::vector<std::string> Stockfish::GetListOfMoves() {
    std::string nextCommand;
    if(history != "") nextCommand = "position startpos moves " + history + "\n";
    else nextCommand = "position startpos\n";
    //std::string nextCommand = "position startpos moves " + history + "\n";
    stockfish_in<<nextCommand<<std::flush;
    stockfish_in<<"go depth 1\n"<<std::flush;
    std::string line;
    std::vector<std::string> moves;
    while (pipe_stream && std::getline(pipe_stream, line)) {
        //std::cout << line <<std::endl;
        if(line.find("pv") != std::string::npos) {
            auto newMove = line.substr(line.find_last_of("pv")+2);
            if(newMove.length() > 7) newMove = newMove.substr(0, newMove.find(" "));
            newMove.erase(std::remove(newMove.begin(), newMove.end(), '\n'), newMove.end());
            newMove.erase(std::remove(newMove.begin(), newMove.end(), '\r'), newMove.end());
            moves.push_back(newMove);
           // debugConsole->LogMessage(std::to_string(newMove.length()));
        }
        if(line.find("bestmove") != std::string::npos) break;
    }
    if(line.find("none") != std::string::npos) return {};
    return moves;
}

bool Stockfish::isMoveLegal(std::string newMove) {
    auto moves = GetListOfMoves();
    //debugConsole->LogMessage("sprawdzam " +newMove + "\n");
    //debugConsole->LogMessage(std::to_string(newMove.length()));
    //for(auto s: moves) debugConsole->LogMessage("mam " + s+ "\n");
    auto r = (std::find(moves.begin(), moves.end(), newMove) != moves.end());
    //if(r) debugConsole->LogMessage("1 \n");
    //else debugConsole->LogMessage("0 \n");
    
    return (std::find(moves.begin(), moves.end(), newMove) != moves.end());
}

void Stockfish::AddNewMoveToHistory(std::string newMove) {
    newMove.erase(std::remove(newMove.begin(), newMove.end(), '\n'), newMove.end());
    newMove.erase(std::remove(newMove.begin(), newMove.end(), '\r'), newMove.end());

    history = history + " " + newMove;
    debugConsole->LogMessage(history + "\n");
}