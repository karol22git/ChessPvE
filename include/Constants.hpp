#pragma once
#include <string>

const int offset = 2;
const int frameWidth = 820;
const int frameHeight = 720;
const int fieldSize = 70;
const int graveyardFieldSize = 50;
const int boardSize = 8;
const int graveyardSize = 16;
const std::string boardFile = "../resources/board.png";
const std::string resourcesDir = "../resources/";
const bool drawFromPng = true;

enum Colors {
    white = 1,
    black
};