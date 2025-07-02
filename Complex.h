#pragma once
#include "Figure.h"
#include "Triangle.h"
#include "Trapeze.h"

class Complex : public Figure {
public:
    Complex(Figure* t, Figure* tr);
    void draw() override;
    void hide() override;
    void move(int newX, int newY) override;

private:
    Figure* triangle;
    Figure* trapeze;
};