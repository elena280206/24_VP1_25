#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <stdexcept>

class Figure {
public:

    Figure();

    Figure(int x, int y, int a, int b, COLORREF bg, COLORREF border);
    virtual void draw();
    virtual void hide();
    virtual void move(int newX, int newY);
    POINT getPosition() { return position; };
    int getH() { return height; };
    ~Figure() { ReleaseDC(hWindow, hDC); }

    class BorderException : public std::runtime_error {
    public:
        BorderException(const std::string& msg) : std::runtime_error(msg) {}
    };

    class InvalidParameters : public std::runtime_error {
    public:
        InvalidParameters(const std::string& msg) : std::runtime_error(msg) {}
    };




protected:
    COLORREF bgColor, borderColor;
    HWND hWindow;
    HDC hDC;
    RECT windowRect;
    POINT position;
    int widthL, widthT, height;

};