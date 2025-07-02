#pragma once
#include "Figure.h"

class Triangle : public Figure {
public:
    Triangle(int x, int y, int a, int b, COLORREF bg, COLORREF border);
    void draw() override;
    void hide() override;

private:
    POINT points[3];
};