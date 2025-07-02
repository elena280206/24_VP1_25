#pragma once
#include "Figure.h"

class Trapeze : public Figure {
public:
    Trapeze(int x, int y, int a, int b, COLORREF bg, COLORREF border);
    void draw() override;
    void hide() override;

private:
    POINT points[4];
};