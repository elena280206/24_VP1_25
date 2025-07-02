#include "Complex.h"

Complex::Complex(Figure* t, Figure* tr)
    : Figure(t->getPosition().x, t->getPosition().y, 0, 0, 0, 0), triangle(t), trapeze(tr) {}

void Complex::draw() {
    triangle->draw();
    trapeze->draw();
}

void Complex::hide() {
    triangle->hide();
    trapeze->hide();
}

void Complex::move(int newX, int newY) {

    triangle->move(newX, newY);
    trapeze->move(newX, newY + trapeze->getH());
}