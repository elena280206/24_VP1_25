#pragma once
#include <list>
#include <initializer_list>
#include "Figure.h"

class FiguresList {
public:
    void addFigures(std::initializer_list<Figure*> figures);
    void displayAll() const;
    void hide();
    void clearAll();

private:
    std::list<Figure*> figures;
};