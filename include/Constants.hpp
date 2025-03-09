#pragma once
#include <string>
#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

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
struct GraphicsResources gResources();

enum Color {
    white = 1,
    black
};

struct GraphicsResources {
    wxBitmap whitePawnBitmap, blackPawnBitmap, whiteBishopBitmap, blackBishopBitmap,
        whiteKnightBitmap, blackKnightBitmap, whiteRookBitmap, blackRookBitmap, whiteQueenBitmap,
        blackQueenBitmap, whiteKingBitmap, blackKingBitmap;
    GraphicsResources() {
        wxImage image;
        image.LoadFile(resourcesDir + "white_pawn.svg.png", wxBITMAP_TYPE_ANY);
        whitePawnBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "black_pawn.svg.png", wxBITMAP_TYPE_ANY);
        blackPawnBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "white_bishop.svg.png", wxBITMAP_TYPE_ANY);
        whiteBishopBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "black_bishop.svg.png", wxBITMAP_TYPE_ANY);
        blackBishopBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "white_knight.svg.png", wxBITMAP_TYPE_ANY);
        whiteKnightBitmap =  wxBitmap(image);
        image.LoadFile(resourcesDir + "black_knight.svg.png", wxBITMAP_TYPE_ANY);
        blackKnightBitmap =  wxBitmap(image);
        image.LoadFile(resourcesDir + "white_rook.svg.png", wxBITMAP_TYPE_ANY);
        whiteRookBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "black_rook.svg.png", wxBITMAP_TYPE_ANY);
        blackRookBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "white_queen.svg.png", wxBITMAP_TYPE_ANY);
        whiteQueenBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "black_queen.svg.png", wxBITMAP_TYPE_ANY);
        blackQueenBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "white_king.svg.png", wxBITMAP_TYPE_ANY);
        whiteKingBitmap = wxBitmap(image);
        image.LoadFile(resourcesDir + "black_king.svg.png", wxBITMAP_TYPE_ANY);
        blackKingBitmap = wxBitmap(image);
    }
};