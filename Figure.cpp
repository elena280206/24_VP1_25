#include "Figure.h"

Figure::Figure() : position{ 0, 0 }, widthL(0), widthT(0), height(0), bgColor(RGB(240, 240, 240)), borderColor(RGB(240, 240, 240)) {
    hWindow = GetConsoleWindow();
    hDC = GetDC(hWindow);
    GetClientRect(hWindow, &windowRect);
}

Figure::Figure(int x, int y, int a, int b, COLORREF bg, COLORREF border)
    : position{ x, y }, height(a), widthL(b), bgColor(bg), borderColor(border) {
    hWindow = GetConsoleWindow();
    hDC = GetDC(hWindow);
    GetClientRect(hWindow, &windowRect);
    widthT = widthL / 2;
}

void Figure::draw()
{
    return;
}

void Figure::hide()
{
    return;
}

void Figure::move(int newX, int newY) {
    hide();
    position.x = newX;
    position.y = newY;
    draw();
}